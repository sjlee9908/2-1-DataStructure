#include <stdio.h>

void insert(int arr[], int loc, int value) {
	for (int i = 0; i < loc; i++) {
		arr[i] = arr[i + 1];
	}
	arr[loc] = value;
}

void delete(int arr[], int loc) {
	for (int i = loc; i > 0; i--) {
		arr[i] = arr[i-1];
	}
	arr[0] = 0;
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
	delete(arr, 4);

	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}

}