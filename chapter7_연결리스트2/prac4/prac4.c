#include <stdio.h>

typedef int element;
typedef struct Node {
	element data;
	struct Node* link;
}Node;

Node* append(Node* head, element data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link;
		head->link = node;		
	}
	return head;
}

int get_size(Node* head) {
	Node* node = head;
	int res = 0;
	do {
		res++;
		node = node->link;
	} while (node != head);

	return res;
}

void free_all(Node* head) {
	Node* node = head;
	Node* tmp;
	do {
		tmp = node->link;
		free(node);
		node = tmp;
	} while (node != head);
}

int main() {
	Node* head = NULL;
	head = append(head, 1);
	head = append(head, 2);
	head = append(head, 3);
	head = append(head, 4);

	printf("%d°³", get_size(head));
	free_all(head);
}