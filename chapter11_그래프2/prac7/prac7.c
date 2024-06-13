#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100
#define INF 10000

typedef struct GraphNode {
	int vertex;
	int weight;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];	
} GraphType;

void init(GraphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과\n");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v, int w) {
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류\n");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->weight = w;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트 ", i);
		while (p != NULL) {
			printf("-> %d:%d", p->vertex, p->weight);
			p = p->link;
		}
		printf("\n");
	}
}

int distance[MAX_VERTICES];
int found[MAX_VERTICES];

int choose(int distance[], int n, int found[]) {
	int i, min, minpos;
	min = INT_MAX;
	minpos = 01;
	for (i = 0; i < n; i++) {
		if (distance[i] < min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}

void print_status(GraphType* g) {
	static int step = 1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf(" found: ");
	for (int i = 0; i < g->n; i++) printf("%2d ", found[i]);
	printf("\n\n");
}

void shortest_path(GraphType* g, int start) {
	int i, u, w;
	GraphNode* node = g->adj_list[start];
	int node_weight = INF;
	
	for (i = 0; i < g->n; i++) {
		distance[i] = INF;
	}
	
	while (node) {
		distance[node->vertex] = node->weight;
		node = node->link;
	}

	for (i = 0; i < g->n; i++) {
		found[i] = FALSE;
	}

	found[start] = TRUE;
	distance[start] = 0;

	for (i = 0; i < (g->n)-1; i++) {
		print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w < g->n; w++) {
			node_weight = INF;
			node = g->adj_list[u];
			while (node != NULL) {
				if (node->vertex == w) { 
					node_weight = node->weight;
					break;
				}
				node = node->link;
				
				}
			if (!found[w])
				if (distance[u] + node_weight < distance[w])
					distance[w] = distance[u] + node->weight;
		}
	}
}

int main() {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);

	for (int i = 0; i < 7; i++) insert_vertex(g, i);

	insert_edge(g, 0, 1, 7);
	insert_edge(g, 0, 4, 3);
	insert_edge(g, 0, 5, 10);

	insert_edge(g, 1, 0, 7);
	insert_edge(g, 1, 2, 4);
	insert_edge(g, 1, 3, 10);
	insert_edge(g, 1, 4, 2);
	insert_edge(g, 1, 5, 6);

	insert_edge(g, 2, 1, 4);
	insert_edge(g, 2, 3, 2);

	insert_edge(g, 3, 1, 10);
	insert_edge(g, 3, 2, 2);
	insert_edge(g, 3, 4, 11);
	insert_edge(g, 3, 5, 9);
	insert_edge(g, 3, 6, 4);

	insert_edge(g, 4, 0, 3);
	insert_edge(g, 4, 1, 2);
	insert_edge(g, 4, 3, 11);
	insert_edge(g, 4, 6, 5);

	insert_edge(g, 5, 0, 10);
	insert_edge(g, 5, 1, 6);
	insert_edge(g, 5, 3, 9);

	insert_edge(g, 6, 3, 4);
	insert_edge(g, 6, 4, 5);


	print_adj_list(g);
	shortest_path(g, 0);
	free(g);
	return 0;
}