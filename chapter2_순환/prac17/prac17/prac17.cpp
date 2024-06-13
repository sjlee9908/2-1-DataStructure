#include <stdio.h>

int fac(int n) {
	int res = 1;
	for (int i = 1; i <= n; i++) res *= i;
	return res;
}

int binomal_coefficient(int n, int k) {
	if (k == 0 || k == n) return 1;
	if (k > 0 && n > 0 && n > k) return binomal_coefficient(n - 1, k - 1) + binomal_coefficient(n - 1, k);
}

int binomal_coefficient_iter(int n, int k) {
	if (k<0 || k>n) return 1;
	return fac(n) / (fac(k) * fac(n - k));
}


int main() {
	printf("%d\n", binomal_coefficient(12, 3));
	printf("%d\n", binomal_coefficient_iter(12, 3));
}