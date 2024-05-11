#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef unsigned char byte;

// clear && gcc -O0 TesteTempo.c && ./a.out
// clear && clang -O0 TesteTempo.c && ./a.out
// clear && g++ -O0 TesteTempo.c && ./a.out

int main() {
	clock_t inicio, fim, T;
	float Tempo, media = 0;
	int i, j;

	// Aqui troca o tipo de variável
	float num1 = 1, num2 = 3;

	T = CLOCKS_PER_SEC;

	int qtd = 500;

	for (i = 0; i < qtd; i++) {

		inicio = clock();
		for (j = 0; j < 10000000; j++) num1 *= num2;
		fim = clock();

		Tempo = ((fim - inicio) * 1000.0 / CLOCKS_PER_SEC);
		printf("\nTempo: %gms.", Tempo);
		media += Tempo;
	}

	printf("\nTempo gasto media: %g ms.", media / qtd);
}