#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
	int key;
	struct TreeNode* right, *left;
} TreeNode;

TreeNode* new_node(int item) {
	TreeNode* temp = (TreeNode*)malloc(sizeof(TreeNode));
	temp->key = item;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

TreeNode* insert_node(TreeNode* node, int key) {
	if (node == NULL) return new_node(key);
	if (key < node->key) node->left = insert_node(node->left, key);
	else if (key > node->key) node->right = insert_node(node->right, key);
	return node;
}

int get_height(TreeNode* node) {
	int height = 0;
	if (node != NULL)
		height = 1 + max(get_height(node->left), get_height(node->right));
	return height;
}

void isBalenced(TreeNode* node){
	if (node == NULL) return;
	int diff = get_height(node->left) - get_height(node->right);
	
	if (diff<=1 && diff>=-1) {
		isBalenced(node->right);
		isBalenced(node->left);
	}
	else {
		printf("±ÕÇüÆ®¸®°¡ ¾Æ´Ô\n");
		return;
	}
}

int main() {
	TreeNode* root = NULL;
	TreeNode* tmp = NULL;

	root = insert_node(root, 17);
	root = insert_node(root, 14);
	root = insert_node(root, 26);
	root = insert_node(root, 02);
	root = insert_node(root, 66);
	root = insert_node(root, 28);
	root = insert_node(root, 80);

	isBalenced(root); 
	
}


