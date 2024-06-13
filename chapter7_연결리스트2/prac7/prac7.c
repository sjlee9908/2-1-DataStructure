#include <stdio.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node* rlink;
	struct Node* llink;
} Node;

void init(Node* head) {
	head->rlink = head;
	head->llink = head;
}

void append(Node* before, element data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;

	node->rlink = before->rlink;
	node->llink = before;

	before->rlink->llink = node;
	before->rlink = node;
}

Node* search(Node* L, element data) {
	for (Node* tmp = L->rlink; tmp != L; tmp = tmp->rlink) {
		if (data == tmp->data) return tmp;
	}
	return NULL;
}

void free_all(Node* head) {
	Node* node = head;
	Node* tmp;
	while (node != head) {
		tmp = node->rlink;
		free(node);
		node = tmp;
	}
}

int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	Node* node;
	init(head);

	append(head, 10);
	append(head, 20);
	append(head, 30);
	append(head, 40);

	node = search(head, 230);

	if (node == NULL) printf("찾는 값이 없습니다");
	else printf("찾는 값이 있습니다");
	
	free_all(head);
}