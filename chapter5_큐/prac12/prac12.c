#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} DequeType;

void error(const char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_deque(DequeType* q) {
	q->front = q->rear = 0;
}

int is_empty(DequeType* q) {
	return (q->front == q->rear);
}

int is_full(DequeType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void deque_print(DequeType* q) {
	printf("DEQUE(front=%d rear=%d) = ", q->front, q->rear);
	if (!is_empty(q)) {
		int i = q->front;
		do {
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void add_rear(DequeType* q, element item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element get_front(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element val) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q) {
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태 입니다");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	return q->data[q->rear];
}

int main() {
	DequeType d1;
	DequeType d2;
	init_deque(&d1);
	init_deque(&d2);

	add_front(&d1, 3);
	add_front(&d1, 2);
	add_front(&d1, 1);
	printf("d1= "); deque_print(&d1);

	while (!is_empty(&d1) || !is_empty(&d2)) {
		if (is_empty(&d1)) add_front(&d1, delete_rear(&d2));
		printf("d1= "); deque_print(&d1);
		if (is_empty(&d2)) add_front(&d2, delete_rear(&d1));
		printf("d2= "); deque_print(&d2);
		if (!is_empty(&d1)) delete_rear(&d1);
		printf("d1= "); deque_print(&d1);
		if (!is_empty(&d2)) delete_rear(&d2);
		printf("d2= "); deque_print(&d2);
	}
}