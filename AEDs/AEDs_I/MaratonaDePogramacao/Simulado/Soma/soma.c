#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// clear && gcc soma.c -o soma.exe && ./soma.exe < pub.in > out.txt

int metodo(int somaVal, int* ptrInicio, int* array, int arrayLength) {
	int soma = 0, qtdRetangulos = 0;
	for (int i = *ptrInicio; i < arrayLength; i++) {
		if (array[i] <= somaVal) {
			if (array[i] + soma <= 4) {
				soma += array[i];
				if (soma == 4) qtdRetangulos++;
			} else {
				*ptrInicio = i;
				return qtdRetangulos;
			}
		} else {
			*ptrInicio = i + 1;
			return 0;
		}
	}
	return -1;
}

int main() {

	int arrayLength, soma, qtdRetangulos = 0, inicio = 0;

	scanf("%d %d", &arrayLength, &soma);

	// int array[arrayLength];
	int* array = (int*)malloc(arrayLength * sizeof(int));

	for (int i = 0; i < arrayLength; i++) {
		scanf("%d", &array[i]);
	}

	int resultado;
	while ((resultado = metodo(soma, &inicio, array, arrayLength)) != -1) {
		qtdRetangulos += resultado;
	}

	printf("QtdRetangulos: %d\n", qtdRetangulos);

	return 0;
}