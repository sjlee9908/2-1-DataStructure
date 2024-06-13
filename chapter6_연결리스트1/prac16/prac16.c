#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef int element;

typedef struct Node {
	element data;
	struct Node* link;
} Node;

Node* append(Node* head, element data) {
	Node* p = head;
	Node* tmp = (Node*)malloc(sizeof(Node));
	tmp->data = data;
	tmp->link = NULL;

	for (; p->link != NULL; p = p->link);

	p->link = tmp;
}

void show_list(Node* head) {
	Node* p = head;
	printf("연결리스트: ");
	for (; p != NULL; p = p->link)
		printf("%d -> ", p->data);
	printf("\n");
}

Node* remove_list(Node* head) {
	Node* p = head->link;
	Node* pre_p = head->link;
	Node* new_head = head->link;
	free(head);

	for (; p != NULL; p = p->link) {
		pre_p = p->link->link;
		free(p->link);
		p->link = pre_p;
		}
		return new_head;
	}

void end_list(Node* head) {
	Node* p = head;
	Node* pp = head->link;

	for (; pp != NULL; p = p->link) {
		free(p);
		p = pp;
		pp = pp->link;
	}
}

int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	head->link = NULL;
	int data;
	int count;

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

		show_list(head);
		head = remove_list(head);
		show_list(head);
		end_list(head);
	}

}