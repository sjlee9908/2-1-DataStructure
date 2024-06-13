#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
} TreeNode;

void inorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		printf("[%d] ", root->data);
		inorder(root->right);
	}
}

void preorder(TreeNode* root) {
	if (root != NULL) {
		printf("[%d] ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(TreeNode* root) {
	if (root != NULL) {
		inorder(root->left);
		inorder(root->right);
		printf("[%d] ", root->data);
	}
}