#include <stdio.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* new_node(int key) {
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->key = key;
	tmp->left = tmp->right = NULL;
	return tmp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL) return new_node(key);
	if (key < node->key) node->left = insert_node(node->left, key);
	else if (key > node->key) node->right = insert_node(node->right, key);
	return node;
}

void inorder(TreeNode* root) {
	if (root) {
		inorder(root->left);
		root->key++;
		inorder(root->right);
	}
}

void display(TreeNode* root){
	if (root) {
		display(root->left);
		printf("%d ", root->key);
		display(root->right);
	}
}

int main() {
	TreeNode* root = NULL;
	for (int i = 0; i < 10; i++) {
		root = insert_node(root, i);
	}

	display(root);
	printf("\n");
	inorder(root);
	display(root);
}