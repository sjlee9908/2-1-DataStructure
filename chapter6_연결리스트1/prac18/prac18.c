#include <stdio.h>

typedef int element;

typedef struct Node {
	element data;
	struct Node* link;
}Node;

void append(Node* n1, element data) {
	Node* p = n1;
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->link = NULL;

	for (; p->link != NULL; p = p->link);

	p->link = tmp;
}

void sort(Node* n) {
	Node* p = n;
	element tmp;

	for (; p != NULL; p = p->link) {
		if (p->link == NULL) return;
		if (p->data > p->link->data) {
			tmp = p->data;
			p->data = p->link->data;
			p->link->data = tmp;

		}
	}
}

Node* merge(Node* n1, Node* n2) {
	Node* new_head = (Node*)malloc(sizeof(Node));
	Node* ex_np = new_head;
	Node* p1 = n1;
	Node* p2 = n2;
	ex_np->data = p1->data;
	ex_np->link = NULL;
	p1 = p1->link;
	int count = 1;

	while (p1 != NULL) {
		if (p2 != NULL && count % 2 == 1) {
			Node* np = (Node*)malloc(sizeof(Node));
			ex_np->link = np;
			np->data = p2->data;
			np->link = NULL;
			ex_np = np;
			p2 = p2->link;
			count++;
		}
		else {
			Node* np = (Node*)malloc(sizeof(Node));
			ex_np->link = np;
			np->data = p1->data;
			np->link = NULL;
			ex_np = np;
			p1 = p1->link;
			count++;
		}
	}
	if (p2 != NULL) {
		for (; p2 != NULL; p2 = p2->link) {
			Node* np = (Node*)malloc(sizeof(Node));
			ex_np->link = np;
			np->data = p2->data;
			np->link = NULL;
			ex_np = np;
		}
	}
	sort(new_head);
	return new_head;
}

void free_all(Node* n) {
	Node* p = n;
	Node* tmp;
	for (; p != NULL;) {
		tmp = p->link;
		free(p);
		p = tmp;
	}
}

void Nodeshow(Node* n) {
	Node* p = n;
	for (; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("\n");
}

int main() {
	Node* a = (Node*)malloc(sizeof(Node));
	a->data = 11;
	a->link = NULL;
	Node* b = (Node*)malloc(sizeof(Node));
	b->data = 21;
	b->link = NULL;

	Node* c;

	append(a, 12);
	append(b, 22);
	append(b, 23);
	append(b, 24);

	c = merge(a, b);

	Nodeshow(a);
	Nodeshow(b);
	Nodeshow(c);

	free_all(a);
	free_all(b);
	free_all(c);
}