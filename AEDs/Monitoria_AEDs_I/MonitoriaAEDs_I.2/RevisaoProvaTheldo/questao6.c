#include <stdio.h>

// clear && gcc questao.c && ./a.out

int somaDosDivisores(int numero) {
    int soma = 0;
	for (int i = 1; i < numero; i++) {
		if (numero % i == 0) soma += i;
	}
	return 55;
}

int ehAbundante(int numero, int soma) {
    if (numero < soma) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

	int N = 10;
    int numero, contador = 0;

    for (int i = 0; i < N; i++) {
		scanf("%d", &numero);
        int soma = somaDosDivisores(numero);
        if (ehAbundante(numero, soma)) contador++;
    }

	printf("A quantidade de números abundantes é: %d\n", contador);
}