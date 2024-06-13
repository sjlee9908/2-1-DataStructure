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

	for (; p->link!= NULL; p = p->link);

	p->link = tmp;
}

Node* alternate(Node* n1, Node* n2) {
	Node* new_head = (Node*)malloc(sizeof(Node));
	Node* p1 = n1;
	Node* p2 = n2;

	new_head->data = p1->data;
	new_head->link = NULL;
	p1 = p1->link;
	int count = 1;

	while(p1!=NULL){
		if (p2 != NULL && count % 2 == 1 ) {
			append(new_head, p2->data);
			p2 = p2->link;
			count++;
		}
		else {
			append(new_head, p1->data);
			p1 = p1->link;
			count++;
		}
	}
	if (p2 != NULL) {
		for (; p2 != NULL; p2 = p2->link) {
			append(new_head, p2->data);
		}
	}
	return new_head;
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

	c = alternate(a, b);

	Nodeshow(a);
	Nodeshow(b);
	Nodeshow(c);
}