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

void dequeue(LinkedQueueType* q) {
	QueueNode* temp = q->front;
	element data;
	if (is_empty(q)) {
		fprintf(stderr, "������ �������\n");
		exit(1);
	}
	else {
		data = temp->data;
		q->front = q->front->link;
		if (q->front == NULL)
			q->rear = NULL;
		free(temp);
		return data;
	}
}

