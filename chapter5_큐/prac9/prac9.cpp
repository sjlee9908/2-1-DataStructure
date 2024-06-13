#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 5

typedef int element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
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

void print_stack(StackType* s) {
	printf("Stack:");
	for (int i = 0; i < s->top+1; i++) {
		printf(" %d |", s->data[i]);
	}
	printf("\n");
}

int main() {
	StackType s1;
	StackType s2;
	int element;

	init_stack(&s1);
	init_stack(&s2);

	while (!is_full(&s1)) {
		printf("����(ť) ��� �Է�: ");
		scanf("%d", &element);
		push(&s1, element);
		print_stack(&s1);
	}

	if (is_empty(&s2)) {
		while (!is_empty(&s1)) {
			push(&s2, pop(&s1));
		}
	}

	printf("���: \n");
	print_stack(&s2);

	while (!is_empty(&s2)) {
		pop(&s2);
		print_stack(&s2);
	}


}