#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
	char s[30];
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

HeapType* create() {
	return (HeapType*)malloc(sizeof(HeapType));
}

void init(HeapType* h) {
	h->heap_size = 0;
}

void insert_max_heap(HeapType* h, element item) {
	int i;
	i = ++(h->heap_size);

	while ((i != 1) && (item.key > h->heap[i / 2].key)) {
		h->heap[i] = h->heap[i / 2];
		i /= 2;
	}
	h->heap[i] = item;
}

element delete_max_heap(HeapType* h) {
	int parent, child;
	element item, temp;

	item = h->heap[1];
	temp = h->heap[(h->heap_size)--];
	parent = 1;
	child = 2;

	while (child <= h->heap_size) {
		if ((child < h->heap_size) && (h->heap[child].key < h->heap[child + 1].key))
			child++;
		if (temp.key >= h->heap[child].key) break;
		h->heap[parent] = h->heap[child];
		parent = child;
		child *= 2;
	}
	h->heap[parent] = temp;
	return item;
}

int main() {
	char s[30];
	char sel;
	int key;
	HeapType* h = create();
	init(h);


	while (1) {
		printf("삽입(i), 삭제(d): ");
		scanf("%c", &sel);
		getchar();
		
		if (sel == 'i') {
			printf("할일: ");
			scanf("%s", s);
			printf("우선순위: ");
			scanf("%d", &key);
			getchar();
			element e1 = { key, "" };
			strcpy(e1.s, s);
			insert_max_heap(h, e1);
		}
		else {
			printf("제일 우선 순위가 높은 일은 \"%s\"\n", delete_max_heap(h).s);
		}
	}
}

