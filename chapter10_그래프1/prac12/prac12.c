#define _CRT_SECURE_NO_WARNINGS
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

void read_graph_mat(GraphType* g, char* name) {
	init(g);
	FILE* fp = fopen(name, "r");
	
	fscanf(fp, "%d", &(g->n));

	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			fscanf(fp, "%d", &(g->adj_mat[i][j]));
		}
	}
}

void write_graph_mat(GraphType* g, char* name) {
	FILE* fp = fopen(name, "w");

	fprintf(fp, "%d\n", g->n);
	for (int i = 0; i < g->n; i++) {
		for (int j = 0; j < g->n; j++) {
			fprintf(fp, "%d ", g->adj_mat[i][j]);
		}
		fprintf(fp, "\n");
	}
}



void main() {
	GraphType* g;

	g = (GraphType*)malloc(sizeof(GraphType));
	read_graph_mat(g, "name.txt");
	printf_adj_mat(g);
	write_graph_mat(g, "name1.txt");

	free(g);
}
