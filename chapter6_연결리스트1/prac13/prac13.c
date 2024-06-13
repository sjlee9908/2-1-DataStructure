#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int element;

typedef struct Node {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* append(ListNode* head, element data) {
	ListNode* p = head;
	ListNode* tmp = (ListNode*)malloc(sizeof(ListNode));
	tmp->data = data;
	tmp->link = NULL;

	for (; p->link != NULL; p = p->link);

	p->link = tmp;
}

void show_list(ListNode* head) {
	ListNode* p = head;
	for (; p != NULL; p = p->link) {
		printf("%d", p->data);
		if (p->link != NULL) printf("->");
	}
}

void remove_node(ListNode* head) {
	element remove_data;
	ListNode* p = head;
	ListNode* tmp = head;
	int count = 0;
	printf("삭제할 값을 입력하시오: ");
	scanf("%d", &remove_data);
	
	if (head->data == remove_data) {
		p = head->link;
		free(head);
		head = p;
	}

	for (; p->link != NULL; p = p->link) {
		tmp = p->link;
		if (tmp->data == remove_data) {
			tmp = tmp->link;
			free(p->link);
			p->link = tmp;
		}
	}
	show_list(head);
}

int main() {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->link = NULL;
	int count = 0;
	element data;

	printf("노드의 개수:");
	scanf("%d", &count);

	if (count == 0) return 0;
	else {
		printf("노드 #1 데이터: ");
		scanf("%d", &data);
		head->data = data;
		for (int i = 1; i < count; i++) {
			printf("노드 #%d 데이터: ", i + 1);
			scanf("%d", &data);
			append(head, data);
		}
		remove_node(head);
	}
}