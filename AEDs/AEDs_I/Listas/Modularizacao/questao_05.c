#include <math.h>
#include <stdio.h>

// Essa função recebe um número inteiro n e retorna o n-ésimo termo da sequência { 2, 4, 6, 8, 10, 12... }
int par(int n) {
	return n * 2;
}

// Essa função recebe um número inteiro n e retorna o valor ->
// do somatório dos n primeiros termos da sequência { 1/3, 1/5, 1/7, 1/9, 1/11, ... }.
double UmSobreImpar(int n, int x) {
	int resultado = 1;

	for (int i = 0; i < n; i++) {
		resultado += 2;
	}

	return x != 0 ? 1 / (double)resultado : resultado;
}

// Função recebe um número inteiro n e retorna ->
// o n-ésimo termo da sequência {2/3, 4/5, 6/7, 8/9, 10/11 ... }
double ParSobreImpar(int n, int x) {
	double base = UmSobreImpar(n, 1) * pow(UmSobreImpar(n, 0), 2);

	if (x == 1) printf("\nO %d° termo da sequência é %d/%.0lf ou ", n, par(n), base);
	return par(n) * UmSobreImpar(n, 1);
}

// Essa função recebe um número inteiro n e retorna o ->
// valor do somatório dos n primeiros termos da sequência {2/3, 4/5, 6/7, 8/9, 10/11 ... }
double SomaParSobreImpar(int n) {
	double soma;

	for (int i = 1; i <= n; i++) {
		soma += ParSobreImpar(i, 0);
	}
	return soma;
}

// Esse procedimento lê o valor de n e chama a função.
void Exercicio05() {
	int n;

	printf("Digite um número inteiro: ");
	scanf("%d", &n);

	printf("%.4lf", ParSobreImpar(n, 1));

	printf("\n\nA soma dos %d primeiros números da sequência é %.3lf", n, SomaParSobreImpar(n));
}

int main() {

	Exercicio05();

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}