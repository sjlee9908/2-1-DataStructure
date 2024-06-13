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

void search(TreeNode* node, int data) {
	if (node != NULL) {
		if (data > node->key)
			printf("%d보다 작은 노드: %d\n", data, node->key);
		search(node->left, data);
		search(node->right, data);
	}
}

int main() {
	TreeNode* root = NULL;

	root = insert_node(root, 10);
	root = insert_node(root, 32);
	root = insert_node(root, 9);
	root = insert_node(root, 75);
	root = insert_node(root, 29);
	root = insert_node(root, 42);
	root = insert_node(root, 52);


	search(root, 30);

}