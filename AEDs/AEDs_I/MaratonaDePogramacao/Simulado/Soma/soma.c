#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// clear && gcc soma.c -o soma.exe && ./soma.exe < pub.in > out.txt

int metodo(int somaVal, int* array, int arrayLength) {
	int soma = 0, qtdRetangulos = 0;
	static int inicio = 0;

	for (int i = inicio; i < arrayLength; i++) {
		if (array[i] <= somaVal) {
			if (array[i] + soma <= 4) {
				soma += array[i];
				if (soma == 4) qtdRetangulos++;
				if (i == arrayLength - 1) {
					inicio = i + 1;
					return qtdRetangulos;
				}
			} else {
				inicio = i;
				return qtdRetangulos;
			}
		} else {
			inicio = i + 1;
			return qtdRetangulos;
		}
	}
	return -1;
}

int main() {

	int arrayLength, soma, qtdRetangulos = 0;

	scanf("%d %d", &arrayLength, &soma);

	// int array[arrayLength];
	int* array = (int*)malloc(arrayLength * sizeof(int));

	for (int i = 0; i < arrayLength; i++) {
		scanf("%d", &array[i]);
	}

	int resultado;
	while ((resultado = metodo(soma, array, arrayLength)) != -1) {
		qtdRetangulos += resultado;
	}

	printf("qtdRetangulos: %d\n", qtdRetangulos);

	free(array);

	return 0;
}