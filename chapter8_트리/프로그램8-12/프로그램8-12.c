#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* min_value_node(TreeNode* node) {
	TreeNode* current = node;
	while (current->left != NULL)
		current = current->left;
	return current;
}

TreeNode* delete_node(TreeNode* root, int key) {
	if (root == NULL)return root;
	if (key < root->key)
		root->left = delete_node(root->left, key);
	else if (key > root->key)
		root->right = delete_node(root->right, key);
	else {
		if (root->left == NULL) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode* temp = min_value_node(root->right);
		root->key = temp->key;
		root->right = delete_node(root->right, temp->key);
	}
	return root;
}