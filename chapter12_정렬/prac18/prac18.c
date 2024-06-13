#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 10
#define SWAP(x,y,t) ((t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

int median(int list[]) {
	int max = list[0];
	int min = list[0];
	int eval;

	for (int i = 0; i < MAX_SIZE; i++) {
		if (list[i] > max) max = list[i];
		if (list[i] < min) min = list[i];
	}

	eval = max + min / 2;
	min = 10000;
	int min_index;
	int diff_eval[MAX_SIZE];
	for (int i = 0; i < MAX_SIZE; i++) {
		diff_eval[i] = abs(list[i] - eval);
		if (diff_eval[i] < min) min_index = i;
	}
	return list[min_index];
}


int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high;

	low = left;
	high = right + 1;
	pivot = list[left];
	do {
		do low++;
		while (list[low] < pivot);
		do high--;
		while (list[high] > pivot);
		if (low < high) SWAP(list[low], list[high], temp);
	} while (low < high);
	SWAP(list[left], list[high], temp);
	return high;
}

void quick_sort(int list[], int left, int right) {
	if (left < right) {
		int q = partition(list, left, right);
		quick_sort(list, left, q - 1);
		quick_sort(list, q + 1, right);
	}
}

int main() {
	int i;
	n = MAX_SIZE;
	srand(time(NULL));
	for (i = 0; i < n; i++) list[i] = rand() % 100;
	quick_sort(list, 0, n - 1);
	for (i = 0; i < n; i++) printf("%d ", list[i]);
	printf("\n");
	return 0;
}