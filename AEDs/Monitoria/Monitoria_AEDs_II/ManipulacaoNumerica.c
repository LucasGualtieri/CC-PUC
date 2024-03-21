#include <stdio.h>
#include <math.h>

// clear && gcc ManipulacaoNumerica.c -lm && ./a.out

int numberLength(int n) {
	int len = 1;
	while ((n /= 10) > 0) len++;
	return len;
}

int foo(int pos, int numero) {

    int potencia = 0;
	int resultado = 0;
	int n = numberLength(numero);

	for (int i = 0; i < n; numero /= 10, i++) {
		if (i != pos) {
			resultado += (numero % 10) * pow(10, potencia++);
		}
	}

	return resultado;
}

void main() {

	int resultado = foo(2, 1234);

    printf("%d\n", resultado);
}