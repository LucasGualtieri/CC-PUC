#include <stdio.h>

void fibonacci(int l) {
	int a = 0, b = 1, c = 0;

	printf("{ 0, 1, ");
	for (int i = 2; c < l; i++) {
		c = a + b;
		a = b;
		b = c;
		if (c < l) {
			printf("%d, ", c);
		}
	}
	printf("... }\n");
}

int main(void) {
	int l;

	printf("L: ");
	scanf("%d", &l);
	fibonacci(l);

	return 0;
}