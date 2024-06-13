#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

ListNode* append(ListNode* head, element data) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->data = data;
	temp->link = NULL;

	ListNode* q = head;
	for (; q->link != NULL; q = q->link);
	
	q->link = temp;
}

void show_list(ListNode* head) {
	ListNode* p = head;
	for (; p != NULL; p = p->link) {
		printf("%d", p->data);
		if (p->link != NULL) printf("->");
	}
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
		printf("생성된 연결 리스트: ");
		show_list(head);
	}
}