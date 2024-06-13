#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

void dfs_list(GraphType* g, int v) {
	GraphNode* w;
	visited[v] = TRUE;
	printf("Á¤Á¡ %d -> ", v);
	for (w = g->adj_list[v]; w; w = w->link)
		if (!visited[w->vertex])
			dfs_list(g, w->vertex);
}