#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200
typedef struct {
	int key;
}element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
}HeapType;

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

void heap_sort(element a[], int n) {
	int i;
	HeapType* h;

	h = create();
	init(h);

	for (i = 0; i < n; i++) {
		insert_max_heap(h, a[i]);
		for (int j = 0; j < n; j++) printf("%d ", a[j].key);
		printf("\n");
	}
	for (i = (n - 1); i >= 0; i--) {
		a[i] = delete_max_heap(h);
		for (int j = 0; j < n; j++) printf("%d ", a[j].key);
		printf("\n");

	}
	free(h);
}

#define SIZE 10
int main() {
	element list[SIZE] = { 41, 67, 34, 0, 69, 24, 78, 58, 62, 64 };
	printf("숫자의 개수 : 10\n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i].key);
	}

	printf("\n\n\n");	
	heap_sort(list, SIZE);
	printf("\n\n\n");

	printf("정렬된 배열 : \n");
	for (int i = 0; i < SIZE; i++) {
		printf("%d ", list[i].key);
	}
	printf("\n");
	return 0;
}