#include <stdio.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* right, * left;
} TreeNode;

TreeNode* new_node(int key) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = key;
	temp->left = temp->right = NULL;
}

TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL)node = new_node(key);
	if (key < node->key) node->left = new_node(key);
	else if (key > node->key) node->right = new_node(key);
	return node;
}

int inorder(TreeNode* root) {
	static int res = 0;
	if (root) {
		inorder(root->left);
		inorder(root->right);
		res += root->key;
	}
	return res;
}

int main() {
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	root = insert_node(root, 30);
	root = insert_node(root, 20);
	root = insert_node(root, 10);
	root = insert_node(root, 40);
	root = insert_node(root, 50);
	root = insert_node(root, 60);
	inorder(root);
	printf("%d", inorder(root));
}