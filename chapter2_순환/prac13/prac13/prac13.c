#include <stdio.h>

int sigma(int n) {
	if (n == 1) return 1;
	else return n + sigma(n - 1);
}

int main() {
	printf("%d", sigma(3));
}