#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct QueueNode {
	element data;
	struct QueueNode* link;
} QueueNode;

typedef struct {
	QueueNode* front, * rear;
} LinkedQueueType;

void enqueue(LinkedQueueType* q, element data) {
	QueueNode* temp = (QueueNode*)malloc(sizeof(QueueNode));
	temp->data = data;
	temp->link = NULL;
	if (is_empty(q)) {
		q->front = temp;
		q->rear = temp;
	}
	else {
		q->rear->link = temp;
		q->rear = temp;
	}
}