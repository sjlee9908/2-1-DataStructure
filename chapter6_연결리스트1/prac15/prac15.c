#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int element;

typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

void append(ListNode* head, element data) {
	ListNode* temp = (ListNode*)malloc(sizeof(ListNode));
	temp->data = data;
	temp->link = NULL;

	ListNode* q = head;
	for (; q->link != NULL; q = q->link);

	q->link = temp;
}

void show_list(ListNode* head) {
	ListNode* p = head;
	element max = head->data;
	element min = head->data;
	
	for (; p != NULL; p = p->link) {
		printf("%d", p->data);
		if (p->link != NULL) printf("->");
		if (max > p->data) max = p->data;
		if (min < p->data) min = p->data;
	}
	printf("\n�ִ�:%d, �ּڰ�:%d", max, min);

}


int main() {
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->link = NULL;
	int count = 0;
	element data;

	printf("����� ����:");
	scanf("%d", &count);

	if (count == 0) return 0;
	else {
		printf("��� #1 ������: ");
		scanf("%d", &data);
		head->data = data;
		for (int i = 1; i < count; i++) {
			printf("��� #%d ������: ", i + 1);
			scanf("%d", &data);
			append(head, data);
		}
		printf("������ ���� ����Ʈ: ");
		show_list(head);
	}
}