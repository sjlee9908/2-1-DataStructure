#include <stdio.h>

typedef struct NODE {
	int key;
	struct NODE* rlink;
	struct NODE* llink;
}Node;

int create(Node* n, int key) {
	n->key = key;
	n->llink = NULL;
	n->rlink = NULL;
}

int append(Node* n, int key) {
	Node* temp = (Node*)malloc(sizeof(Node));
	Node* node;
	temp->key = key;
	temp->rlink = NULL;
	for (node = n; node->rlink != NULL; node = node->rlink);
	node->rlink = temp;
	temp->llink = node;
}

void insertion_sort_node(Node* n) {
	int key;
	Node* node1;
	Node* node2;
	Node* tmp = NULL;
	for (node1 = n->rlink; node1 != NULL; node1 = node1->rlink) {
		key = node1->key;
		for (node2 = node1->llink; node2 != NULL && node2->key > key; node2 = node2->llink){
			node2->rlink->key = node2->key;
			if(node2->llink == NULL) tmp = node2;
		}
		node2->rlink->key = key;
	}
}

int main() {
	Node* n = (Node*)malloc(sizeof(Node));
	Node* node;
	create(n, -1);
	append(n, 17);
	append(n, 9);
	append(n, 21);
	append(n, 6);
	append(n, 3);
	append(n, 12);

	for (node = n->rlink; node != NULL; node = node->rlink) printf("%d ", node->key);
	printf("\n");
	insertion_sort_node(n);
	for (node = n->rlink; node != NULL; node = node->rlink) printf("%d ", node->key);
}