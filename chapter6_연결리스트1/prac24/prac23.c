#include <stdio.h>

typedef struct Node {
	int row;
	int col;
	int data;
	struct Node* link;
} Node;

Node* append(Node* n, int row, int col, int data) {
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->row = row;
	tmp->col = col;
	tmp->data = data;
	tmp->link = n;
	
	n = tmp;

	return n;
}

Node* free_all(Node* n) {
	Node* p = n;
	Node* tmp;
	for (; p != NULL; p = p->link) {
		tmp = p->link;
		free(p);
		p = tmp;
	}
}

void display(Node* n) {
	int m[10][10] = { 0, };
	Node* p = n;
	for (; p != NULL; p = p->link) {
		m[p->row][p->col] = p->data;
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			printf("%d  ", m[i][j]);
		}
		printf("\n");
	}
}

int main() {
	Node* sparse_matrix = NULL;

	sparse_matrix = append(sparse_matrix, 1, 3, 12);
	sparse_matrix = append(sparse_matrix, 5, 2, 87);
	sparse_matrix = append(sparse_matrix, 8, 5, 15);
	sparse_matrix = append(sparse_matrix, 1, 5, 12);
	sparse_matrix = append(sparse_matrix, 3, 2, 87);
	sparse_matrix = append(sparse_matrix, 6, 10, 15);

	display(sparse_matrix);

	free_all(sparse_matrix);
}