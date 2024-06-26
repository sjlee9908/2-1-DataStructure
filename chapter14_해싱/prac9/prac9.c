#include <stdio.h>
#define TABLE_SIZE 7

typedef struct {
	int key;
} element;

struct list {
	element item;
	struct list* link;
};

struct list* hash_table[TABLE_SIZE];

int hash_function(int key) {
	return key % TABLE_SIZE;
}

void hash_chain_add(element item, struct list* ht[]) {
	int hash_value = hash_function(item.key);
	struct list* ptr;
	struct list* node_before = NULL, * node = ht[hash_value];
	for (; node; node_before = node, node = node->link) {
		if (node->item.key == item.key) {
			fprintf(stderr, "이미 탐색키가 저장되어 있음\n");
			return;
		}
	}
	ptr = (struct list*)malloc(sizeof(struct list));
	ptr->item = item;
	ptr->link = NULL;
	if (node_before)node_before->link = ptr;
	else ht[hash_value] = ptr;
}

void hash_chain_search(element item, struct list* ht[]) {
	struct list* node;
	int hash_value = hash_function(item.key);
	for (node = ht[hash_value]; node; node = node->link) {
		if (node->item.key == item.key) {
			fprintf(stderr, "탐색 %d 성공 \n", item.key);
			return;
		}
	}
	printf("키를 찾지 못했음\n");
}

void hash_chain_delete(element item, struct list* ht[]) {
	struct list* node;
	int hash_value = hash_function(item.key);
	struct list* ex_node = ht[hash_value];

	for (node = ht[hash_value]; node; ex_node=node, node = node->link) {
		if (node->item.key == item.key) {
			if (node == ht[hash_value]) {
				ht[hash_value] = node->link;
				free(node);
			}
			else {
				ex_node->link = node->link;
				free(node);
			}

			return;
		}
	}
	printf("삭제 실패: 키를 찾지 못했음\n");

}

void hash_chain_print(struct list* ht[]) {
	struct list* node;
	int i;
	printf("\n========================\n");
	for (i = 0; i < TABLE_SIZE; i++) {
		printf("[%d]->", i);
		for (node = ht[i]; node; node = node->link) {
			printf("%d->", node->item.key);
		}
		printf("\n");
	}
	printf("========================\n");
}

#define SIZE 5
int main(void) {
	int data[SIZE] = { 8,1,9,6,13 };
	element e;

	for (int i = 0; i < SIZE; i++) {
		e.key = data[i];
		hash_chain_add(e, hash_table);
		hash_chain_print(hash_table);
	}
	for (int i = 0; i < SIZE; i++) {
		e.key = data[i];
		hash_chain_search(e, hash_table);
	}
	e.key = 5656;
	hash_chain_delete(e, hash_table);
	hash_chain_print(hash_table);
	return 0;
}