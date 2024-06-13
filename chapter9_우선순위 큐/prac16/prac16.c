#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct {
	int heap[MAX_ELEMENT];
	int heap_size;
} HeapType;


int delete_some_heap(HeapType* h, int key) {
	int p, c;
	for (int i = 1; i <= h->heap_size; i++)
		if (h->heap[i] == key) {
			p = i;
			c = 2 * i;
			break;
		}

	int item = h->heap[p], temp = h->heap[(h->heap_size)--];
	while (c <= h->heap_size) {
		if ((c < h->heap_size) && (h->heap[c] < h->heap[c + 1]))
			c++;
		if (temp >= h->heap[c])
			break;
		h->heap[p] = h->heap[c];
		p = c;
		c *= 2;
	}
	h->heap[p] = temp;
	return item;
}