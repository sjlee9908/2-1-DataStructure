#include <stdio.h>

typedef struct Node {
	int data;
	struct Node* link;
} Node;

void sort(Node* n) {
	for (Node* p = n; p != NULL; p = p->link) {
		for (Node* q = p->link; q != NULL; q = q->link) {
			if (p->data > q->data) {
				int tmp = p->data;
				p->data = q->data;
				q->data = tmp;
			}
		}
	}
}


int is_empty(Node* n) {
	return (n == NULL);
}

int get_length(Node* n) {
	int i = 0;
	for (Node* p = n; p != NULL; p = p->link) {
		i++;
	}
	return i;
}

int is_in_list(Node* n, int find_value) {
	int i = 0;
	for (Node* p = n; p != NULL; p = p->link) {
		i++;
		if (p->data == find_value) return i;
	}
	return 0;
}

void clear(Node* n) {
	Node* tmp;
	for (Node* p = n; p != NULL; p = p->link) {
		tmp = p->link;
		free(p);
		p = tmp;
	}
}

void delete(Node* n, int item) {
	int pos = is_in_list(n, item);
	Node* p = n;
	if (!pos) return;
	else {
		pos -= 2;
		for (int i = 0; i < pos; i++) {
			p = p->link;
		}
		Node* tmp = p->link;
		p->link = p->link->link;
		free(tmp);
	}
	sort(n);
}

Node* add(Node* n, int item) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = item;
	tmp->link = n;

	n = tmp;
	sort(n);

	return n;
}

void display(Node* n) {
	for (Node* p = n; p != NULL; p = p->link) {
		printf("%d->", p->data);
	}
	printf("\n");
}

int main() {
	Node* n1 = NULL;

	n1 = add(n1, 5);
	n1 = add(n1, 2);
	n1 = add(n1, 1);
	n1 = add(n1, 8);
	display(n1);

	delete(n1, 5);
	display(n1);

}