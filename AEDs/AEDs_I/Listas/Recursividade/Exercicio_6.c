#include <stdio.h>

/*
	Fazer um método recursivo que calcule o MDC (máximo divisor comum)
	de dois inteiros positivos m e n
*/

int Mdc(int m, int n, int x) {
	if (x == 0)
		return 1;
	if (m % x == 0 && n % x == 0)
		return x;
	return Mdc(m, n, --x);
}

// Achei essa solução na internet, inverter o n com o m em cada chamada é genial ->
// -> nunca teria pensado nisso, porém a minha forma é mais legal, tem ternário...
// int Mdc(int m, int n) {
// 	if (m == n) return m;
//    if (m < n) return Mdc(n, m);
//    return Mdc(m - n, n);
// }

int main() {
	int m, n, x;

	printf("Digite um número natural*: ");
	scanf("%d", &m);

	printf("Digite outro número natural*: ");
	scanf("%d", &n);

	x = m > n ? m : n;

	printf("O MDC de %d e %d é: %d", m, n, Mdc(m, n, x));

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}