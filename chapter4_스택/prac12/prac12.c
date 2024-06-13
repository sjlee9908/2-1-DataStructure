#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_STACK_SIZE 100

typedef char element;

typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return(s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택포화에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

element pop(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택공백에러\n");
		exit(1);
	}
	else return s->data[(s->top)--];
}

element peek(StackType* s) {
	if (is_empty(s)) {
		fprintf(stderr, "스택공백에러\n");
		exit(1);
	}
	else return s->data[s->top];
}

int main() {
	char st[100];
	StackType s;

	init_stack(&s);
	printf("문자열을 입력하시오: ");
	scanf("%s", st);

	st[0] = tolower(st[0]);
	push(&s, st[0]);

	printf("압축된 문자열: ");

	for (int i = 1; i < strlen(st); i++) {
		st[i] = tolower(st[i]);
		if (peek(&s) != st[i]) {
			printf("%d", s.top+1);
			printf("%c", peek(&s));
			init_stack(&s);
			push(&s, st[i]);
		}
		else {
			push(&s, st[i]);
		}
	}


	printf("%d", s.top + 1);
	printf("%c", peek(&s));
	init_stack(&s);



}