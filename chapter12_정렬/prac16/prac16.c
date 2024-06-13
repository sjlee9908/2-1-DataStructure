#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 6
#define SWAP(x, y, t) ((t)=(x), (x)=(y), (y)=(t))

int list[MAX_SIZE];
int n;

void selection_sort(int list[], int n) {
	int i=0, j, least, temp;

	printf("( ");
	for (int k = 0; k < i; k++) printf("%d ", list[k]);
	printf(" )\t\t");

	printf("( ");
	for (int k = i; k < n; k++) printf("%d ", list[k]);
	printf(" )\t\t");

	printf("초기상태");
	printf("\n");
	
	int sel1, sel2;
	for (int i = 0; i < n - 1; i++) {
		least = i;
		for (j = i + 1; j < n; j++) if (list[j] < list[least]) {
			least = j;
			sel1 = list[i];
			sel2 = list[least];
		}
		SWAP(list[i], list[least], temp);

		printf("( ");
		for (int k = 0; k <= i; k++) printf("%d ", list[k]);
		printf(" )\t\t");

		printf("( ");
		for (int k = i+1; k < n; k++) printf("%d ", list[k]);
		printf(" )\t\t");

		printf("%d선택 후 %d과 교환", sel2, sel1);
		printf("\n");

	}
}

int main() {
	int i;
	n = MAX_SIZE;
	int list[MAX_SIZE] = { 17,9,21,6,3,12 };

	selection_sort(list, n);
	for (i = 0; i < n; i++) printf("%d ", list[i]);
	printf("\n");
	return 0;
}