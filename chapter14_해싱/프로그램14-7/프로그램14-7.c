#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define KEY_SIZE 10
#define TABLE_SIZE 13
#define empty(item) (strlen(item.key)==0)
#define equal(item1, item2) (!strcmp(item1.key, item2.key))


typedef struct {
	char key[KEY_SIZE];
} element;

element hash_table[TABLE_SIZE];

void init_table(element ht[]) {
	int i;
	for (i = 0; i < TABLE_SIZE; i++) ht[i].key[0] = NULL;
}

int transform(char* key) {
	int number = 0;
	while (*key)
		number = 31 * number + *key++;
	return number;
}

//제산함수를 사용한 해싱함수
int hash_function(char* key) {
	return transform(key) % TABLE_SIZE;
}

void hash_qp_add(element item, element ht[]) {
	int i, hash_value, inc = 0;
	hash_value = i = hash_function(item.key);
	while (!empty(ht[i])) {
		if (equal(item, ht[i])) {
			fprintf(stderr, "탐색키가 중복되었습니다\n");
			exit(1);
		}
		i = (hash_value + inc * inc) % TABLE_SIZE;
		inc = inc + 1;
		if (i == hash_value){
			fprintf(stderr, "테이블이 가득찼습니다\n");
			exit(1);
			}
	}
	ht[i] = item;
}