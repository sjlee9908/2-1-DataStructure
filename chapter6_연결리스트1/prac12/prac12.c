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


void find(ListNode* head) {
	element find_data;
	ListNode* p = head;
	int count = 0;
	printf("탐색할 값을 입력하시오: ");
	scanf("%d", &find_data);

	for (; p != NULL; p = p->link) {
		if (p->data == find_data) count++;
	}
	printf("%d는 연결 리스트에서 %d번 나타납니다", find_data, count);
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
		find(head);
	}
}