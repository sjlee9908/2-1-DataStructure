#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct TreeNode {
	element key;
	struct TreeNode* left, * right;
} TreeNode;

TreeNode* search(TreeNode* node, int key) {
	if (node == NULL) return NULL;
	if (key == node->key) return node;
	else if (key < node->key)
		return search(node->left, key);
	else
		return search(node->right, key);
}