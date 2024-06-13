#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define NAME_SIZE 30


typedef struct {
	int key;
	char name[NAME_SIZE];
} record;

void insertion_sort(record list[], int n) {
	int i, j, key;
	char temp[NAME_SIZE];
	for (i = 0; i < n; i++) {
		key = list[i].key;
		strcpy(temp, list[i].name);

		for (j = i - 1; j >= 0 && list[j].key > key; j--) {
			list[j + 1].key = list[j].key;
			strcpy(list[j + 1].name, list[j].name);
		}

		list[j + 1].key = key;
		strcpy(list[j+1].name, temp);
	}
}

int main() {
	record list[10] = {
		{34, "1"},{12, "2"},{45, "3"},{31, "4"},{24, "5"},{98, "6"},{76, "7"},{53, "8"},{24, "9"},{83, "10"},
	};

	insertion_sort(list, 10);
	
	for (int i = 0; i < 10; i++) {
		printf("%d:%s ->\n", list[i].key, list[i].name);
	}
}