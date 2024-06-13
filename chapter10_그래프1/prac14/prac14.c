#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
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
		fprintf(stderr, "그래프: 정점 번호 오류");
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
	g->adj_mat[end][start] = 1;
}

int visited1[MAX_VERTICES];
void dfs_mat_base(GraphType* g, int v) {
	int w;
	visited1[v] = TRUE;
	//printf("정점 %d -> ", v);
	for (w = 0; w < g->n; w++)
		if (g->adj_mat[v][w] && !visited1[w])
			dfs_mat_base(g, w);
}

int visited2[MAX_VERTICES];
void dfs_mat_find(GraphType* g, int v) {
	int w;
	visited2[v] = TRUE;
	//printf("정점 %d -> ", v);
	for (w = 0; w < g->n; w++)
		if (g->adj_mat[v][w] && !visited2[w])
			dfs_mat_find(g, w);
	
}


void bridge_find(GraphType* g) {
	dfs_mat_base(g, 0);
	printf("\n");
	int centi_i = 0;
	int centi_j = 0;
	
	GraphType* copy_g = (GraphType*)malloc(sizeof(GraphType));
	copy_g->n = g->n;
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			copy_g->adj_mat[i][j] = g->adj_mat[i][j];
		}
	}

	for (centi_i = 0; centi_i < g->n; centi_i++) {
		for (centi_j = 0; centi_j < g->n; centi_j++) {
			if (copy_g->adj_mat[centi_i][centi_j] == 1) {
				
				copy_g->adj_mat[centi_i][centi_j] = 0;

				for (int i = 0; i < MAX_VERTICES; i++) visited2[i] = 0;
				dfs_mat_find(copy_g, 0);
				for (int i = 0; i < MAX_VERTICES; i++) {
					if (visited1[i] != visited2[i]) {
						printf("브릿지 발견: %d %d\n", centi_i, centi_j);
						break;
					}

				}
				copy_g->adj_mat[centi_i][centi_j] = 1;
			}
		}
	}
}

int main(void) {
	GraphType* g;
	g = (GraphType*)malloc(sizeof(GraphType));
	init(g);
	for (int i = 0; i < 10; i++)
		insert_vertex(g, i);

	insert_edge(g, 0, 1);
	insert_edge(g, 1, 2);
	insert_edge(g, 1, 3);
	insert_edge(g, 2, 3);
	insert_edge(g, 2, 4);
	insert_edge(g, 3, 4);
	insert_edge(g, 3, 5);
	insert_edge(g, 5, 6);
	insert_edge(g, 5, 7);
	insert_edge(g, 6, 7);
	insert_edge(g, 7, 8);
	insert_edge(g, 7, 9);


	bridge_find(g);

	free(g);
	return 0;
}