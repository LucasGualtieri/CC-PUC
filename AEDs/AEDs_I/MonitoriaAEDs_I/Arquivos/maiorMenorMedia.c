#include <biblioteca_c.h>

int main() {

	int qtdNumeros = 0;
	float numero, soma = 0, menor = (float)INT_MAX, maior = (float)INT_MIN;
	FILE* file = fopen("maiorMenorMedia.txt", "r");

	while (fscanf(file, "%f", &numero) != EOF) {
		qtdNumeros++;
		soma += numero;

		if (numero > maior) maior = numero;
		if (numero < menor) menor = numero;
	}

	float media = soma / qtdNumeros;

	printf("Maior: %.1f\n", maior);
	printf("Menor: %.1f\n", menor);
	printf("Média: %.1f\n", media);

	fclose(file);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}