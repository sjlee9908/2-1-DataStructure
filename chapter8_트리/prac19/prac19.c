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

TreeNode* insert_node(TreeNode* root, int key) {
	if (root == NULL) return new_node(key);
	if (key < root->key) root->left = insert_node(root->left, key);
	else if (key > root->key) root->right = insert_node(root->right, key);
	return root;
}

void sort_tree(TreeNode* root) {
	if (root) {
		sort_tree(root->right);
		printf("%d ", root->key);
		sort_tree(root->left);
	}
}

int main() {
	TreeNode* root = NULL;
	int num[11] = { 11,3,4,1,56,5,6,2,98,32,23 };

	for (int i = 0; i < 11; i++) {
		root = insert_node(root, num[i]);
	}

	sort_tree(root);
}