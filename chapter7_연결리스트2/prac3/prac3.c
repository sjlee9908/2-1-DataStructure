#include <stdio.h>

typedef int element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
}ListNode;

ListNode* append(ListNode* L, element data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (L == NULL) {
		L = node;
		node->link = L;
	}
	else {
		node->link = L->link;
		L->link = node;
	}
	return L;
}

ListNode* search(ListNode* L, element data) {
	ListNode* node = L;
	do {
		if (data == node->data) {
			printf("%d 있음", node->data);
			return node;
		}
		node = node->link;
	} while (L != node);

	printf("%d 없음\n", data);
	return NULL;
}

void free_all(ListNode* L) {
	ListNode* node = L;
	ListNode* tmp;
	do {
		tmp = node->link;
		free(node);
		node = tmp;
	} while (L != node);
}

int main() {
	ListNode* head = NULL;
	ListNode* node = NULL;

	head = append(head, 10);
	head = append(head, 20);
	head = append(head, 30);
	head = append(head, 40);

	node = search(head, 40);

	free_all(head);
}