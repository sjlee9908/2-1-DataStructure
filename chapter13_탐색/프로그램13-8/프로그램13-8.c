#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
	int key;
	struct AVLNode* left;
	struct AVLNode* right;
} AVLNode;

AVLNode* rotate_right(AVLNode* parent) {
	AVLNode* child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}