#include <biblioteca_c.h>

/*
	Definição do Fatorial recursivo:
	N! = N * N-1! ou Fat(N) = N * Fat(N-1)
	1! = 1 ou Fat(1) = 1 // Condição de parada
*/

// Nos retorna o !N
int fat(int N) {
	if (N == 1) return 1;
	return N * fat(N - 1);
}

int main() {

	int N = 5;
	printf("%d! = %d\n", N, fat(N));

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}