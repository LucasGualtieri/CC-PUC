#include <math.h>
#include <stdio.h>

int main(void) {
	int x, y;

	printf("X: ");
	scanf(" %d", &x);

	if (x <= 1) {
		y = 1;
	} else if (x > 1 && x <= 2) {
		y = 2;
	} else if (x > 2 && x <= 3) {
		y = pow(x, 2);
	} else if (x > 3) {
		y = pow(x, 3);
	}

	printf("Y = %d", y);
}