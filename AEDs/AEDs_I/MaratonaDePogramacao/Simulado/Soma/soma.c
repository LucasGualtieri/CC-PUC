#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// clear && gcc soma.c -o soma.exe && ./soma.exe < pub.in > out.txt

// Essa questão está incompleta, a forma correta é MUITO mais difícil e eu não sei fazer :(
// https://olimpiada.ic.unicamp.br/pratique/pu/2019/f1/soma/

int metodo(int targetSoma, int* array, int arraySize) {

	int soma = 0, qtdRetangulos = 0;
	static int inicio = 0;
	if (inicio >= arraySize) return -1;

	for (int i = inicio; i < arraySize; i++, inicio++) {
		if (array[i] <= targetSoma) {
			if (array[i] + soma <= 4) {
				soma += array[i];
				if (soma == targetSoma) qtdRetangulos++;
			} else {
				inicio = i;
				return qtdRetangulos;
			}
		} else {
			inicio = i + 1;
			return qtdRetangulos;
		}
	}
	return qtdRetangulos;
}

int main() {

	int arraySize, targetSoma, qtdRetangulos = 0;

	scanf("%d %d", &arraySize, &targetSoma);

	int array[arraySize];

	for (int i = 0; i < arraySize; i++) {
		scanf("%d", &array[i]);
	}

	int resultado;
	while ((resultado = metodo(targetSoma, array, arraySize)) != -1) {
		qtdRetangulos += resultado;
	}

	// printf("qtdRetangulos: %d\n", qtdRetangulos);
	printf("%d", qtdRetangulos);

	return 0;
}