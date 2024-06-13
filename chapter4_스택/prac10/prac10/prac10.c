#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType *s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "������ȭ����\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���ð��鿡��\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "���ð��鿡��\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main() {
	int count;
	element num;
	StackType s;
	init_stack(&s);

	printf("���� �迭�� ũ��: ");
	scanf("%d", &count);

	printf("������ �Է��Ͻÿ�: ");
	for (int i = 0; i < count; i++) {
		scanf("	 %d", &num);
		push(&s, num);
	}

	getchar();
	printf("������ ���� �迭: ");
	for (int i = 0; i < count; i++) {
		printf("%d ", pop(&s));
	}
}