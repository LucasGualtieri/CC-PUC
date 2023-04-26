#include <stdio.h>

int main(void) {
	int num;
	float e = 1, umSobreFat, fat = 1;

	do {
		printf("Digite um numero Positivo e Inteiro: ");
		scanf("%d", &num);
	} while (num < 1);

	for (int loop = 1; loop <= num; loop++) {
		fat *= loop;
		umSobreFat = 1 / fat;
		e += umSobreFat;
		printf("\nE = %f", e);
	}

	return 0;
}