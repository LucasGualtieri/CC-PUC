#include <math.h>
#include <stdio.h>

// Essa função recebe um número inteiro n e retorna o n-ésimo termo da sequência { 2, 4, 6, 8, 10, 12... }
int par(int n) {
	return n * 2;
}

// Essa função recebe um número inteiro n e retorna o valor ->
// do somatório dos n primeiros termos da sequência { 1/3, 1/5, 1/7, 1/9, 1/11, ... }.
double UmSobreImpar(int n) {
	int resultado = 1;

	for (int i = 0; i < n; i++) {
		resultado += 2;
	}

	return resultado;
}

// Função recebe um número inteiro n e retorna ->
// o n-ésimo termo da sequência {2/3, 4/5, 6/7, 8/9, 10/11 ... }
double ParSobreImpar(int n, float x) {
	return (par(n) * pow(x, n)) / UmSobreImpar(n);
}

// Esse procedimento lê o valor de n e de x e chama a função.
void Exercicio06() {

	int n;
	float x;

	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	printf("Digite um número real: ");
	scanf("%f", &x);

	printf("O %d° termo da sequência é: %.3lf", n, ParSobreImpar(n, x));
}

int main() {

	Exercicio06();

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}