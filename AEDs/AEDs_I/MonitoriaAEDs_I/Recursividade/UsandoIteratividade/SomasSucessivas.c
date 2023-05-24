#include <biblioteca_c.h>

// for (int i = multiplicador; i > 0; i--) {
// 	resultado += multiplicando;
// }

int SomasSucessivasIterativo(int multiplicando, int multiplicador) {
	int resultado = 0;

	for (int i = 0; i < multiplicador; i++) {
		resultado += multiplicando;
	}

	return resultado;
}

int SomasSucessivas(int multiplicando, int multiplicador, int i) {
	int resultado = 0;

	if (i < multiplicador) {
		resultado = multiplicando + SomasSucessivas(multiplicando, multiplicador, ++i);
	} else {
		return 0;
	}

	return resultado;
}

int SomasSucessivasTernario(int multiplicando, int multiplicador) {
	return (multiplicador == 0) ? 0 : multiplicando + SomasSucessivasTernario(multiplicando, multiplicador - 1);
}

int main() {

	// Faça um programa que imprima X * Y -> 5 x 3 = 15.
	// Sem usar multiplicação, usando somas sucessivas. 5 + 5 + 5

	// int multi = SomasSucessivas(5, 3, 0);
	int multi = SomasSucessivasTernario(5, 3);
	// int multi = SomasSucessivasIterativo(5, 3);

	printf("multi: %d\n", multi);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}