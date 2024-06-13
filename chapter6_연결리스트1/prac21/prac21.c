#include <stdio.h>
#include <math.h>

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

void print(HeaderNode* hn) {
	Node* n = hn->head;

	for (; n != NULL; n = n->link) {
		printf("%dx^%d + ", n->coef, n->expon);
	}
	printf("\n");
}

int poly_eval(HeaderNode* hn, int x) {
	int result = 0;
	Node* n = hn->head;
	for (; n != NULL; n = n->link) {
		result += pow(x, n->expon) * n->coef;
	}
	return result;
}

void free_all(HeaderNode* hn) {
	Node* n = hn->head;
	Node* tmp;
	while (n != NULL){
		tmp = n->link;
		free(n);
		n = tmp;
	}
	free(hn);
}

int main() {
	HeaderNode* n1 = create();
	append(n1, 1, 3);
	append(n1, 2, 1);
	append(n1, 6, 0);

	print(n1);
	printf("x∞° %d¿œ ∂ß, %d", 2, poly_eval(n1, 2));
	free_all(n1);

}