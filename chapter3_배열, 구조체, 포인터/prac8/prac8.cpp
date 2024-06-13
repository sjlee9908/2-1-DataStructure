#include <stdio.h>

void insert(int arr[], int loc, int value) {
	for (int i = 0; i < loc; i++) {
		arr[i] = arr[i + 1];
	}
	arr[loc] = value;
}

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = i + 1;
	}

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");
	insert(arr, 3, 999);

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

}