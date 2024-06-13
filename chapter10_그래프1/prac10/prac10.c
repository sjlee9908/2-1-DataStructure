#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

void init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++) {
		g->adj_list[v] = NULL;
	}
}

void insert_vertex(GraphType* g, int v) {
	if ((g->n) + 1 > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v) {
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트", i);
		while (p != NULL) {
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}
//1, O(n)
int out_degree(GraphType* g, int node) {
	GraphNode* p = g->adj_list[node];
	int res = 0;
	for (; p != NULL; p = p->link) res++;
	return res;
}
//2, O(n^2)
int in_degree(GraphType* g, int node) {
	int res = 0;

	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		while (p != NULL) {
			if (node == p->vertex) res++;
			p = p->link;
		}
	}
	return res;
}
//3, O(n^2)
int all_degree(GraphType* g) {
int res = 0;
for (int i = 0; i < g->n; i++) {
	GraphNode* p = g->adj_list[i];
	while (p != NULL) {
		res++;
		p = p->link;
	}
}
return res;
}

void main() {
	GraphType* g;

	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 6; i++)
		insert_vertex(g, i);

	insert_edge(g, 0, 1);
	insert_edge(g, 0, 2);
	insert_edge(g, 0, 3);
	insert_edge(g, 1, 2);
	insert_edge(g, 1, 3);
	insert_edge(g, 2, 4);
	insert_edge(g, 3, 0);
	insert_edge(g, 3, 4);
	insert_edge(g, 4, 1);
	insert_edge(g, 4, 2);
	insert_edge(g, 5, 4);

	printf("\n");
	printf("%d %d %d", out_degree(g, 1), in_degree(g, 1), all_degree(g));


	free(g);
}
