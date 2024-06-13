#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
} StackType;

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

int main() {
	char st[50];
	StackType s;
	init_stack(&s);

	printf("���ڿ��� �Է��Ͻÿ�: ");
	scanf("%[^\n]", st);

	for (int i = 0; i < strlen(st); i++) {
		if (isalpha(st[i])) {
			st[i] = tolower(st[i]);
			push(&s, st[i]);
		}
	}

	for (int i = 0; i < strlen(st); i++) {
		if (isalpha(st[i])) {
			st[i] = tolower(st[i]);
			push(&s, st[i]);
		}
		else {
			continue;
		}
	}

	printf("ȸ���Դϴ�.");
	return 0;
}