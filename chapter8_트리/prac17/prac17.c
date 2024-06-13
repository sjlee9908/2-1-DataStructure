#include <stdio.h>

typedef struct TreeNode {
	int key;
	struct TreeNode* right, * left;
} TreeNode;

void max_min(TreeNode* root, int* max, int* min) {
	if (root != NULL) {
		max_min(root->left, max, min);
		if (*max < root->key) *max = root->key;
		if (*min > root->key) *min = root->key;
		max_min(root->right, max, min);
	}
}

TreeNode n1 = { 1, NULL, NULL };
TreeNode n2 = { 4, &n1, NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 120, &n3, &n4 };
TreeNode n6 = { 15, &n2, &n5 };
TreeNode* root = &n6;

int main() {
	int max = n6.key, min = n6.key;
	max_min(root, &max, &min);
	printf("최소값=%d\n최대값=%d", min, max);
}