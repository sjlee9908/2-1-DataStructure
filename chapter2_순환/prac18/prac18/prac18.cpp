#include <stdio.h>

int ack(int m, int n) {
	if (m == 0) return n + 1;
	if (n == 0) return ack(m - 1, 1);
	return ack(m - 1, ack(m, n - 1));
}
int ack_iter(int m, int n) {
	while (m != 0) {
		if (n == 0)	n = 1;
		else n = ack_iter(m, n - 1);
		m = m - 1;
	}
	return n + 1;
}

int main() {
	printf("%d %d\n", ack(3, 2), ack_iter(3, 2));
	printf("%d %d\n", ack(2, 3), ack_iter(2, 3));
}