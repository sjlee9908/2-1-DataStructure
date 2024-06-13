#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 50
#define MAX_QUEUE_SIZE 10

typedef int element;
typedef struct {
	element queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void queue_init(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->rear == q->front);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}

typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];

void bfs_list(GraphType* g, int v) {
	GraphNode* w;
	QueueType q;

	init(&q);
	visited[v] = TRUE;
	printf("%d 방문 -> ", v);
	enqueue(&q, v);
	while (!is_empty(&q)) {
		v = dequeue(&q);
		for (w = g->adj_list[v]; w; w = w->link) {
			if (!visited[w->vertex]) {
				visited[w->vertex] = TRUE;
				pritnf("%d 방문 -> ", w->vertex);
				enqueue(&q, w->vertex);
			}
		}
	}
}