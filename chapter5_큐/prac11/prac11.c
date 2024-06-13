#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_QUEUE_SIZE 100

typedef char element;
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
	DequeType dq;
	init_deque(&dq);
	char st[100];
	char a;
	char b;

	printf("문자열을 입력하시오: ");
	scanf("%[^\n]", st);

	for (int i = 0; i < strlen(st); i++) {
		st[i] = tolower(st[i]);
		add_rear(&dq, st[i]);
	}

	while (!is_empty(&dq)) {
		a = delete_front(&dq);
		if (is_empty(&dq)) break;
		b = delete_rear(&dq);
		if (a!=b) {
			printf("회문이 아닙니다\n");
			return 0;
		}
	}
	printf("회문입니다");
	return 0;
}