#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void insertion_sort(int list[], int n) {
	int i=0, j, key=-1;

	for (i = 0; i < n; i++) {
		printf("( ");
		for (int k = 0; k < i; k++) printf("%d ", list[k]);
		printf(")\t\t");

		printf("( ");
		for (int k = i; k < n; k++) printf("%d ", list[k]);
		printf(")\t\t");

		if (key != -1) printf("%d»ðÀÔ", key);
		printf("\n");


		key = list[i];
		for (j = i-1; j >= 0 && list[j] > key; j--) {
			list[j + 1] = list[j];
		}
		list[j + 1] = key;
	}
	printf("( ");
	for (int k = 0; k < i; k++) printf("%d ", list[k]);
	printf(")\t\t");

	printf("( ");
	for (int k = i; k < n; k++) printf("%d ", list[k]);
	printf(")\t\t");

	if (key != -1) printf("%d»ðÀÔ", key);
	printf("\n");
}

int main() {
	int list[6];

	for (int i = 0; i < 6; i++) {
		scanf("%d", list + i);
	}

	insertion_sort(list, 6);

}