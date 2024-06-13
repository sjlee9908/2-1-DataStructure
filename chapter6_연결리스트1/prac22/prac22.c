#include <stdio.h>
#define ARRAY_MAX 10

typedef struct array_list {
	int arr[ARRAY_MAX];
	int size;
}array_list;

void sort(array_list* n) {
	for (int i = 0; i < n->size; i++) {
		for (int j = i + 1; j < n->size; j++) {
			if (n->arr[i] > n->arr[j]) {
				int tmp = n->arr[i];
				n->arr[i] = n->arr[j];
				n->arr[j] = tmp;
			}
		}
	}
}

int is_empty(array_list* p) {
	return (p->size == 0);
}

int is_full(array_list* p) {
	return (p->size == ARRAY_MAX);
}

int get_length(array_list* p) {
	return p->size;
}

int is_in_list(array_list* p, int find_value) {
	for (int i = 0; i < p->size; i++) {
		if (p->arr[i] == find_value) return i+1;
	}
	return 0;
}

void clear(array_list* p) {
	p->size = 0;
}

void delete(array_list* p, int item) {
	int pos = is_in_list(p, item);
	if (!pos) return;
	else {
		pos -= 1;
		for (int i = pos; i < p->size; i++) {
			int tmp = p->arr[i];
			p->arr[i] = p->arr[i + 1];
			p->arr[i + 1] = tmp;
		}
		p->size--;
	}
	sort(p);
}

void add(array_list* p, int item) {
	p->arr[p->size++] = item;
	sort(p);
}

void display(array_list* p) {
	for (int i = 0; i < p->size; i++) {
		printf("%d->", p->arr[i]);
	}
	printf("\n");
}

void init(array_list* p) {
	p->size = 0;
}


int main() {
	array_list al;
	init(&al);
	

	add(&al, 1);
	add(&al, 2);
	add(&al, 12);
	add(&al, 4);
	add(&al, 4);
	add(&al, 18);
	display(&al);

	delete(&al, 4);
	display(&al);
}