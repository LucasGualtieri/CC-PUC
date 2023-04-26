#include <stdio.h>

int par(int n) {
	return n * 2;
}

double UmSobreImpar(int n) {
	double resultado, resAux = 3;

	for (int i = 0; i < n; i++) {
		resultado += 1 / resAux;
		resAux += 2;
	}

	return resultado;
}

double ParSobreImpar(int n) {
	return (par(n) * UmSobreImpar(n));
}

void Exercicio05(int n) {
	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	printf("\nO n-ésimo termo da sequência é: %lf", UmSobreImpar(n));
}

int main() {
	int n;

	Exercicio05(n);

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}