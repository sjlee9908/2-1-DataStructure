#include <stdio.h>

typedef struct Node {
	int coef;
	int expon;
	struct Node* link;
}Node;

typedef struct HeaderNode {
	int size;
	Node* head;
	Node* tail;
}HeaderNode;

void append(HeaderNode* n, int coef, int expon) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->coef = coef;
	tmp->expon = expon;
	tmp->link = NULL;

	if (n->tail == NULL) n->head = n->tail = tmp;
	else {
		n->tail->link = tmp;
		n->tail = tmp;
	}
	n->size++;
}

HeaderNode* create() {
	HeaderNode* hn = (HeaderNode*)malloc(sizeof(HeaderNode));
	hn->head = hn->tail = NULL;
	hn->size = 0;
	return hn;
}

HeaderNode* add(HeaderNode* poly1, HeaderNode* poly2){
	HeaderNode* new_poly;
	new_poly = create();

	Node* n1 = poly1->head;
	Node* n2 = poly2->head;

	while(n1 && n2) {
		if (n1->expon == n2->expon) {
			append(new_poly, n1->coef + n2->coef, n1->expon);
			n1 = n1->link;
			n2 = n2->link;
		}
		else if (n1->expon > n2->expon) {
			append(new_poly, n1->coef, n1->expon);
			n1 = n1->link;
		}
		else if (n1->expon < n2->expon) {
			append(new_poly, n2->coef, n2->expon);
			n2 = n2->link;
		}
	}

	for (; n1 != NULL; n1 = n1->link) append(new_poly, n1->coef, n1->expon);
	for (; n2 != NULL; n2 = n2->link) append(new_poly, n2->coef, n2->expon);
	return new_poly;
}

void print(HeaderNode* hn) {
	Node* n = hn->head;

	for (; n != NULL; n = n->link) {
		printf("%dx^%d + ", n->coef, n->expon);
	}
	printf("\n");
}

void free_all(HeaderNode* hn) {
	Node* n = hn->head;
	Node* tmp;
	while (n != NULL) {
		tmp = n->link;
		free(n);
		n = tmp;
	}
	free(hn);
}

int main() {
	HeaderNode* n1 = create();
	append(n1, 3, 6);
	append(n1, 7, 3);
	append(n1, -2, 2);
	append(n1, -9, 0);
	HeaderNode* n2 = create();
	append(n2, -2, 6);
	append(n2, -4, 4);
	append(n2, 6, 2);
	append(n2, 6, 1);
	append(n2, 1, 0);
	HeaderNode* n3;

	print(n1);
	print(n2);
	n3 = add(n1, n2);

	print(n3);
	free_all(n1);
	free_all(n2);
	free_all(n3);
}