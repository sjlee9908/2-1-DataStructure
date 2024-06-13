#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct DListNode {
	element data;
	struct DListNode* llink;
	struct DListNode* rlink;
} DListNode;

void dinsert(DListNode* before, element data) {
	DListNode* newnode = (DListNode*)malloc(sizeof(DListNode));
	newnode->data = data;
	newnode->llink = before;
	newnode->rlink = before->rlink;

	before->rlink->llink = newnode;
	before->rlink = newnode;
}
