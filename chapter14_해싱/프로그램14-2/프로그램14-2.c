#include <stdio.h>
#define KEY_SIZE 10
#define TABLE_SIZE 13

typedef struct {
	char key[KEY_SIZE];
} element;

element hash_table[TABLE_SIZE];

//�ؽ����̺� �ʱ�ȭ
void init_table(element ht[]) {
	int i;
	for (i = 0; i < TABLE_SIZE; i++) {
		ht[i].key[0] = NULL;
	}
}