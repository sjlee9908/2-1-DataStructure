#include <stdio.h>

double div(int n) {
	if (n == 1) return 1;
	else return (double)1/n + div(n-1);
}

int main() {
	printf("%f", div(2));
}