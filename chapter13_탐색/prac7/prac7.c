#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 10000

typedef struct AVLnode {
	int key;
	struct AVLnode* left;
	struct AVLnode* right;
}AVLnode;

int get_height(AVLnode* node) {
	int height = 0;
	if (node != NULL) height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

int get_balance(AVLnode* node) {
	if (node == NULL) return 0;
	return get_height(node->left) - get_height(node->right);
}

AVLnode* create_node(int key) {
	AVLnode* node = (AVLnode*)malloc(sizeof(AVLnode));
	node->key = key;
	node->left = NULL;
	node->right = NULL;
}

AVLnode* rotate_right(AVLnode* parent) {
	AVLnode* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}

AVLnode* rotate_left(AVLnode* parent) {
	AVLnode* child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

AVLnode* insert(AVLnode* node, int key) {
	if (node == NULL) return (create_node(key));
	if (key < node->key) node->left = insert(node->left, key);
	else if (key > node->key) node->right = insert(node->right, key);
	else return node;

	int balance = get_balance(node);

	if (balance > 1 && key < node->left->key) return rotate_right(node);
	if (balance < -1 && key > node->right->key) return rotate_left(node);
	if (balance > 1 && key > node->left->key) {
		node->left = rotate_left(node->left);
		return rotate_right(node);
	}
	if (balance < -1 && key < node->right->key) {
		node->right = rotate_right(node->right);
		return rotate_left(node);
	}
	return node;
}

void preorder(AVLnode* root) {
	if (root != NULL) {
		printf("[%d] ", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

int main() {
	AVLnode* root = NULL;
	double log_n = ceil(log2(N + 1)) * 2;

	for (int i = 1; i <= N; i++) {
		int num = rand() % (N - 1) + 1;
		printf("%d ", i);
		root = insert(root, num);
	}

	printf("\n\n트리의 높이: %d", get_height(root));
	printf("\nlog(2, N+1): %f", log_n);

	return 0;
}