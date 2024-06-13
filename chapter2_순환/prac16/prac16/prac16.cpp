#include <stdio.h>

int sum_iter(int n) {
	int sum = 0;
	for (; n > 0; n--) {
		sum += n;
	}
	return sum;
}

int sum(int n) {
	if (n == 1) return 1;
	else return n + sum(n - 1);
}

int main() {
	printf("%d\n", sum_iter(10));
	printf("%d\n", sum(10));
}