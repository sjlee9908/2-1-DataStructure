#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentTag {
	char name[10];
	int age;
	double gpa;
}student;

int main() {
	student* s;
	s = (student*)malloc(sizeof(student));
	if (s == NULL) {
		fprintf(stderr, "�޸𸮰� �����ؼ� �Ҵ��� �� �����ϴ�.");
		exit(1);
	}
	strcpy(s->name, "Park");
	s->age = 20;

	free(s);
	return 0;
}
