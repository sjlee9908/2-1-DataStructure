#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))
#define MAX_WORD_SIZE 50
#define MAX_MEANING_SIZE 500
#define SIZE 5

typedef struct {
	char word[MAX_WORD_SIZE];
	char meaning[MAX_MEANING_SIZE];
} element;
element list[SIZE];

int main() {
	int i, j;
	element temp;

	printf("5���� �ܾ�� �ǹ̸� �Է��Ͻÿ�\n");
	for (i = 0; i < 5; i++) {
		scanf("%s[^\n]", list[i].word);
		scanf("%s[^\n]", list[i].meaning);
	}

	for (i = 0; i < SIZE - 1; ++i) {
		for (j = i + 1; j < SIZE; ++j) {
			if (strcmp(list[i].word, list[j].word) > 0) SWAP(list[i], list[j], temp);
		}
	}

	printf("\n���� �� ������ ����\n");
	for (i = 0; i < 5; i++) {
		printf("%s: %s\n", list[i].word, list[i].meaning);
	}
	return 0;
}