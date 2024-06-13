#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node* llink;
	struct Node* rlink;
} Node;

void init(Node* head) {
	head->rlink = head;
	head->llink = head;
}

void append(Node* before, element data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;

	node->llink = before;
	node->rlink = before->rlink;

	before->rlink->llink = node;
	before->rlink = node;
}

void print_all(Node* head) {
	Node* node = head->rlink;
	printf("�����͸� �������� ���: ");
	do {
		printf("%d ", node->data);
		node = node->rlink;
	} while (node != head);
}

void free_all(Node* head) {
	Node* node = head;
	Node* tmp;
	do {
		tmp = node->rlink;
		free(node);
		node = tmp;
	} while (node != head);

}

int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	init(head);
	int count;
	element data;

	printf("�������� ������ �Է��Ͻÿ� : ");
	scanf("%d", &count);

	for (int i = 1; i < count+1; i++) {
		printf("��� #%d�� �����͸� �Է��Ͻÿ�: ", i);
		scanf("%d", &data);
		append(head, data);
	}
	print_all(head);

}