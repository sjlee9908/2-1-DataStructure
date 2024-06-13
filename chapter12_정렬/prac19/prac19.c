#include <stdio.h>
#define MAX_SIZE 50

int sorted[MAX_SIZE];

void merge(int list[], int left, int mid, int right) {
	int i, j, k, l;
	i = left, j = mid + 1, k = left;
	while (i <= mid && j <= right) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i > mid) for (l = j; l <= right; l++) sorted[k++] = list[l];
	else for (l = i; l <= mid; l++) sorted[k++] = list[l];
	for (l = left; l <= right; l++) list[l] = sorted[l];
}

void merge_sort(int list[], int left, int right) {
	int mid;
	printf("merge_sort(list, %d, %d)\n",left, right);
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}

int main() {
	int list[10] = { 49,2,14,64,23,74,85,91,43,12 };
	merge_sort(list, 0, 9);
	for (int i = 0; i < 10; i++) printf("%d ", list[i]);
}