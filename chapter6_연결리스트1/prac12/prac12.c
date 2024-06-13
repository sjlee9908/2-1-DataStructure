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
	printf("Ž���� ���� �Է��Ͻÿ�: ");
	scanf("%d", &find_data);

	for (; p != NULL; p = p->link) {
		if (p->data == find_data) count++;
	}
	printf("%d�� ���� ����Ʈ���� %d�� ��Ÿ���ϴ�", find_data, count);
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
		find(head);
	}
}