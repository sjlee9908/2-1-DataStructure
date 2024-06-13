#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50
typedef struct GraphType {
	int n;
	int adj_mat[MAX_VERTICES][MAX_VERTICES];
} GraphType;

void init(GraphType* g) {
	int r, c;
	g->n = 0;
	for (r = 0; r < MAX_VERTICES; r++)
		for (c = 0; c < MAX_VERTICES; c++)
			g->adj_mat[r][c] = 0;
}

void insert_vertex(GraphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "그래프: 정점의 개수 초과");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int start, int end) {
	if (start >= g->n || end >= g->n) {
		fprintf(stderr, "그래프: 정점 번호 오류");
		return;
	}
	g->adj_mat[start][end] = 1;
}

void printf_adj_mat(GraphType* g) {
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			printf("%2d ", g->adj_mat[i][j]);
		}
		printf("\n");
	}
}
//1, O(n)
int out_degree(GraphType* g, int node) {
	int res=0;
	for (int i = 0; i < g->n; i++) {
		if (g->adj_mat[node][i] == 1) res++;
	}
	return res;
}
//2, O(n)
int in_degree(GraphType* g, int node) {
	int res = 0;
	for (int i = 0; i < g->n; i++) {
		if (g->adj_mat[i][node] == 1) res++;
	}
	return res;
}
//3, O(n^2)
int all_degree(GraphType* g) {
	int res = 0;
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			if (g->adj_mat[i][j] == 1) res++;
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
	printf_adj_mat(g);

	printf("\n");
	printf("%d %d %d", out_degree(g, 1), in_degree(g, 1), all_degree(g));


	free(g);
}
