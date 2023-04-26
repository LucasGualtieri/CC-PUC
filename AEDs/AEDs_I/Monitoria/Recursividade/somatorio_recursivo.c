#include "Bibliotecas/biblioteca_c.h"

int Calcule(int i, int s) {
	if (i == s) return s;
	// printf("I: %i\n", i);
	return i + Calcule(i + 1, s);
}

int main() {

	printf("Calcule(2,6): %i\n", Calcule(2, 6));

	printf("\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}