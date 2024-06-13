#include <stdio.h>

typedef int element;

typedef struct Node {
	element data;
	struct Node* link;
}Node;

Node* create(element data) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->data = data;
	p->link = NULL;
	return p;
}

void append(Node* n, element data) {
	Node* p = n;
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->link = NULL;
		
	for (; p->link != NULL; p = p->link);
	p->link = tmp;
}

void free_all(Node* n) {
	Node* p = n;
	Node* tmp;
	for (; p != NULL; p = tmp) {
		tmp = p->link;
		free(p);
		p = tmp;
		if (p == NULL) return;
	}
}

void nodeshow(Node* n) {
	Node* p = n;
	for (; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("\n");
}

void split(Node** a, Node** b, Node* c) {
	Node* p = c->link->link;
	int count = 0;
	*a = create(c->data);
	*b = create(c->link->data);

	for (; p != NULL; p = p->link) {
		if (count % 2 == 0) {
			append(*a, p->data);
			count++;
		}
		else {
			append(*b, p->data);
			count++;
		}
	}
}

int main() {
	Node* a;
	Node* b;
	Node* c = create(1);
	
	append(c, 2);
	append(c, 3);
	append(c, 4);
	append(c, 5);


	nodeshow(c);
	split(&a, &b, c);
	//포인터가 다른 것을 가리키게 변화시켜야 하는데 그럴 수 없음
	//--> 이중포인터를 이용
	nodeshow(a);
	nodeshow(b);

	free_all(c);
	free_all(a);
	free_all(b);
}