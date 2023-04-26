#include <stdio.h>

double umSobreImpar(int n) {
	double resultado, resAux = 3;

	for (int i = 0; i < n; i++) {
		resultado += 1 / resAux;
		resAux += 2;
	}

	return resultado;
}

void Exercicio04(int n) {
	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	printf("\nA soma dos n primeiros números da sequência é: %lf", umSobreImpar(n));
}

int main() {
	int n;

	Exercicio04(n);

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}