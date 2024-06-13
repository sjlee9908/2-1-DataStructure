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

int show_sum(ListNode* head) {
	int sum = 0;
	ListNode* p = head;
	for (; p != NULL; p = p->link) {
		sum += p->data;
	}
	return sum;
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
		printf("연결 리스트 노드의 개수 = %d", show_sum(head));
	}
}