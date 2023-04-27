#include <stdio.h>

/*
	Fazer um método recursivo que calcule o MDC (máximo divisor comum)
	de dois inteiros positivos m e n
*/

int Mdc(int m, int n, int x) {
	if (x == 0) return 1;
	if (m % x == 0 && n % x == 0) return x;
	return Mdc(m, n, --x);
}

int main() {

	int m, n;

	printf("1° número natural*: ");
	scanf("%d", &m);

	printf("2° número natural*: ");
	scanf("%d", &n);

	printf("O MDC de %d e %d é: %d", m, n, Mdc(m, n, m > n ? m : n));

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}

/*
	Achei essa solução na internet, inverter o n com o m
	em cada chamada é genial nunca teria pensado nisso,
	porém a minha forma é mais legal, tem ternário...

	int Mdc(int m, int n) {
		if (m == n) return m;
		if (m < n) return Mdc(n, m);
		return Mdc(m - n, n);
	}
*/