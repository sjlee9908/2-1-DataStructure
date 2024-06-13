#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct Node {
	char word[20];
	struct Node* link;
}Node;

Node *list[26];

void append(char word[]) {
	int index = word[0] - 97;
	
	Node* new_node = (Node*)malloc(sizeof(Node));
	strcpy(new_node->word, word);
	new_node->link = NULL;

	if (list[index] == NULL) {
		list[index] = new_node;
	}

	else {
		Node* tmp = list[index];
		Node* ex_tmp = tmp;
		while (tmp != NULL) {
			if (strcmp(tmp->word, word) == 0) {
				printf("%s은(는) 이미 저장되어 있음\n", word);
				return;
			}
			ex_tmp = tmp;
			tmp = tmp->link;
		}
		ex_tmp->link = new_node;
	}
}


void search(char word[]) {
	int index = word[0] - 97;

	Node* tmp = list[index];

	while (tmp != NULL) {
		if (strcmp(tmp->word, word) == 0) {
			printf("%s은(는) 인덱스 %c번에 저장됨\n", word, word[0]);
			return;
		}
		tmp = tmp->link;
	}

	printf("%s은(는) 저장되지 않음\n", word);
}

void delete_word(char word[]) {
	int index = word[0] - 97;

	Node* tmp = list[index];
	Node* ex_tmp = tmp;

	if(tmp != NULL)
	if (strcmp(tmp->word, word) == 0) {
		list[index] = list[index]->link;
	}


	while (tmp != NULL) {
		if (strcmp(tmp->word, word) == 0) {
			ex_tmp->link = tmp->link;
			return;
		}
		ex_tmp = tmp;
		tmp = tmp->link;
	}

	printf("%s은(는) 저장되지 않음\n", word);
}


int main() {
	char action_choice;
	char word[20];


	while (1) {
		printf("삽입(i), 탐색(s), 삭제(d): ");
		scanf("%c", &action_choice);
		getchar();
		printf("동물의 이름: ");
		scanf("%s", word);
		getchar();
		
		if (action_choice == 'i') {
			append(word);
			printf("인덱스 %c번에 저장됨\n", word[0]);

		}
		else if (action_choice == 's') {
			search(word);

		}
		else if (action_choice == 'd') {
			delete_word(word);
		}

	}
}