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
	printf("������ ���� �Է��Ͻÿ�: ");
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
		remove_node(head);
	}
}