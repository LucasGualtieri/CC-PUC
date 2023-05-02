#include <biblioteca_c.h>

int MultRec(int fator, int multiplicador) {
	if (multiplicador == 1) {
		return fator;
	} else {
		return fator + MultRec(fator, multiplicador - 1);
	}
}

/*
	int MultIterativo(int fator, int multiplicador) {
		int soma = fator;
		for (int i = 0; i < multiplicador - 1; i++) {
			soma = soma + fator;
		}
		return soma;
	}
*/

int main() {

	int fator = 2;
	int multiplicador = 4;
	int resultado = MultRec(fator, multiplicador);

	printf("%d x %d = %d\n", fator, multiplicador, resultado);

	// printf("%d x %d = %d\n", fator, multiplicador, MultIterativo(fator, multiplicador));

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}