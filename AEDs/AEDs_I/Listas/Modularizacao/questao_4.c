#include <stdio.h>

// Essa função recebe um número inteiro n e retorna o valor ->
// do somatório dos n primeiros termos da sequência { 1/3, 1/5, 1/7, 1/9, 1/11, ... }.
double SomaUmSobreImpar(int n) {
	double resultado = 0, resAux = 2;

	for (int i = 0; i < n; i++) {
		resultado += 1 / (1 + resAux);
		resAux += 2;
	}

	return resultado;
}

// Esse procedimento lê o valor de n e chama a função.
void Exercicio04() {
	int n;

	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	printf("\nA soma dos %d primeiros números da sequência é:\n-> %.4lf", n, SomaUmSobreImpar(n));
}

int main() {

	Exercicio04();

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}