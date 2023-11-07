#include <stdio.h>

// clear && gcc teste.c && ./a.out

int MaiorPotencia(int N) {
	int contador = 1;
	while ((N /= 10) > 0) contador++;

	int pot;
	for (pot = 1; contador > 1; pot *= 10, contador--);

	return pot;
}

int InverteRec(int pontencia, int N) {
	if (pontencia > 0) {
		return (N % 10) * pontencia + InverteRec(pontencia / 10, N / 10);
	} else {
		return 0;
	}
}

int Inverte(int N) {
	int pontencia = MaiorPotencia(N);
	return InverteRec(pontencia, N);
}

int main() {
	int N = 1090761;
	N = Inverte(N);
	printf("N: %d\n", N);
}