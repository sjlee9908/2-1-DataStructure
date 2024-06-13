#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode {
	int key;
	struct AVLNode* left;
	struct AVLNode* right;
} AVLNode;