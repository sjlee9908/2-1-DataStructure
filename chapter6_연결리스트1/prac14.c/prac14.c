#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct {
	char name[10];
	int age;
	float heigh;
} element;

typedef struct Node {
	element data;
	struct Node* link;
}Node;

void append(Node* head, char name[], int age, float heigh) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	strcpy(tmp->data.name, name);
	tmp->data.age = age;
	tmp->data.heigh = heigh;
	tmp->link = NULL;
	Node* p = head;

	for (; p->link != NULL; p = p->link);

	p->link = tmp;
}


void show_list(Node* head) {
	Node* p = head;
	for (; p != NULL; p = p->link) {
		printf("Name:%s, age:%d, heigh:%f\n->\n", p->data.name, p->data.age, p->data.heigh);
	}
	
}


int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	strcpy(head->data.name, "kim");
	head->data.age = 34;
	head->data.heigh = 1.7;
	head->link = NULL;

	append(head, "park", 27, 1.2);
	append(head, "lee", 48, 1.4);
	append(head, "choi", 30, 1.3);

	show_list(head);
}