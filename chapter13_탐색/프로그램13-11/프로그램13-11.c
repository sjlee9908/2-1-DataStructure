#include <stdio.h>
#include <stdlib.h>
#define TWO_NODE 2
#define THREE_NODE 3
#define FALSE 0
#define TRUE 1

typedef struct Tree23Node {
	int type;
	int data;
	int key;
	int key1;
	int key2;
	struct Tree23Node* left;
	struct Tree23Node* middle;
	struct Tree23Node* right;
} Tree23Node;

Tree23Node* tree23_search(Tree23Node* root, int key) {
	if (root == NULL) return FALSE;
	
	else if (key == root->data) return TRUE;

	else if (root->type == TWO_NODE) {
		if (key < root->key) return tree23_search(root->left, key);
		else return tree23_search(root->right, key);
	}
	else {
		if (key < root->key1) return tree23_search(root->left, key);
		else if (key < root->key2) return tree23_search(root->right, key);
		else return tree23_search(root->middle, key);
	}
}