#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 100
typedef int element;

typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
	if (is_full(q)) error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q)) error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

#define BUCKETS 10
#define DIGITS 4

void print_bucket(QueueType q[], int n) {
	printf("\n================\n");
	for (int i = 0; i < n; i++) {
		printf("[%d]-> ", i);
		for (int j = q[i].front+1; j < q[i].rear+1; j++) printf("%d ", q[i].data[j]);
		printf("\n", i);
	}
	printf("\n================\n");
}

void radix_sort(int list[], int n) {
	int i, b, d, factor = 1;
	QueueType queues[BUCKETS];
	for (b = 0; b < BUCKETS; b++) init_queue(&queues[b]);

	for (d = 0; d < DIGITS; d++) {
		for (i = 0; i < n; i++) enqueue(&queues[(list[i] / factor) % 10], list[i]);

		print_bucket(queues, BUCKETS);

		for (b = i = 0; b < BUCKETS; b++) {
			while (!is_empty(&queues[b])) {
				list[i++] = dequeue(&queues[b]);
			}
		}

		factor *= 10;
	}
}

#define SIZE 8

int main() {
	int list[SIZE] = {0, 62, 64, 24, 34, 58, 78, 69};
	radix_sort(list, SIZE);
	for (int i = 0; i < SIZE; i++) printf("%d ", list[i]);
	printf("\n");
	return 0;
}