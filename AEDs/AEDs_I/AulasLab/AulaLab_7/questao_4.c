#include <stdio.h>

void Inverte(int* num1, int* num2, int* num3, int* num4) {
	int a = *num1, b = *num2;

	*num1 = *num4;
	*num2 = *num3;
	*num3 = b;
	*num4 = a;
}

int main(void) {
	int num1 = 1, num2 = 2, num3 = 3, num4 = 4;

	printf("Num1: %d\n", num1);
	printf("Num2: %d\n", num2);
	printf("Num3: %d\n", num3);
	printf("Num4: %d\n", num4);

	Inverte(&num1, &num2, &num3, &num4);

	printf("--------\n");

	printf("Num1: %d\n", num1);
	printf("Num2: %d\n", num2);
	printf("Num3: %d\n", num3);
	printf("Num4: %d\n", num4);

	return 0;
}