#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int num;
	char str[20];
}s;

int main() {
	s* st = (s*)malloc(sizeof(s));
	st->num = 100;
	strcpy(st->str, "just testing");

	printf("%d %s", st->num, st->str);
}