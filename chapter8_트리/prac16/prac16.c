#include <stdio.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* right, *left;
} TreeNode;

TreeNode* new_node(int key) {
	TreeNode* tmp = (TreeNode*)malloc(sizeof(TreeNode));
	tmp->key = key;
	tmp->right = tmp->left = NULL;
	return tmp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL) return new_node(key);
	if (key < node->key) node->left = insert_node(node->left, key);
	else if (key > node->key) node->right = insert_node(node->right, key);
	return node;
}

int search(TreeNode* node) {
	static int res = 0;
	if (node) {
		search(node->left);
		if ((node->left == NULL) ^ (node->right == NULL)) res += 1;
		search(node->right);
	}
	return res;
}

int main() {
	TreeNode* root = NULL;

	root = insert_node(root, 35);
	root = insert_node(root, 18);
	root = insert_node(root, 7);
	root = insert_node(root, 26);
	root = insert_node(root, 3);
	root = insert_node(root, 12);
	root = insert_node(root, 26);
	root = insert_node(root, 22);
	root = insert_node(root, 68);
	root = insert_node(root, 99);

	printf("%d", search(root));
}