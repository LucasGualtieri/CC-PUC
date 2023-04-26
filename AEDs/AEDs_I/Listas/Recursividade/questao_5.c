#include <stdio.h>

/* Fazer um método recursivo que multiplique dois números naturais, através de somas sucessivas */

int MultRec(int x, int y) {
	return y == 0 ? 0 : x + MultRec(x, --y);
}

int main() {

	int x, y;

	printf("Digite um número natural: ");
	scanf("%d", &x);
	printf("Digite outro número natural: ");
	scanf("%d", &y);

	printf("%d * %d = %d", x, y, MultRec(x, y));

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}