#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_ELEMENT 200

typedef struct element{
	int key;
	struct element* link;
} element;

element* create(int key) {
	element* tmp = (element*)malloc(sizeof(element));
	tmp->key = key;
	tmp->link = NULL;
	return tmp;
}

element* insert_max_heap(element* h, int key) {
	element* new_node = create(key);
	element* tmp = h;
	int new_index = 0;
	int key_tmp;

	for (tmp->link != NULL; tmp = tmp->link;)
		new_index++;
	tmp->link = new_node;
	tmp = h;

	while (new_index != 1) {
		for (int i = 0; i < new_index / 2; i++) tmp = tmp->link;
		if (new_node->key > tmp->key) {
			key_tmp = new_node->key;
			new_node->key = tmp->key;
			tmp->key = key_tmp;
			new_index /= 2;
		}
	}
	return h;
}

element* delete_max_heap(element* h) {
	int index = 0;
	int parent = 0, child = 1;
	element* temp = h->link;
	element* child_tmp;
	element* parent_tmp=h;
	element* item = h;

	for (temp->link != NULL; temp = temp->link;)
		index++;
	

	while (child <= index) {
		child_tmp = h;
		parent_tmp = h;
		for (int i = 0; i < child; child++) child_tmp = child_tmp->link;
		for (int i = 0; i < parent; parent++) parent_tmp = parent_tmp->link;
		if (child < index && child_tmp->key < child_tmp->link->key) {
			child++;
			child_tmp = child_tmp->link;
		}
		if (temp->key >= child_tmp->key) break;
		parent_tmp->key = child_tmp->key;
		parent = child;
		child *= 2;
	}
	parent_tmp->key = temp->key;
	return item;
}
