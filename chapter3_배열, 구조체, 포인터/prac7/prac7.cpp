#include <stdio.h>

typedef struct Complex {
	float real;
	float imaginary;
} c;

Complex complex_add(Complex c1, Complex c2) {
	c c3;
	c3.real = c1.real + c2.real;
	c3.imaginary = c1.imaginary + c2.imaginary;
	return c3;
}

int main() {
	c c1, c2, c3;
	c1.real = 1;
	c1.imaginary = 2;
	c2.real = 1;
	c2.imaginary = 2;

	c3 = complex_add(c1, c2);
	printf("%f %f", c3.real, c3.imaginary);
}