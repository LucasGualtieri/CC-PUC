#include <biblioteca_c.h>

int lerDimensoes(const char* string) {
	int dimensao;
	bool invalid = false;

	do {
		printf("%s: %s", string, invalid ? "(valor deve ser > 0): " : "");
		scanf("%d", &dimensao);
	} while (invalid = dimensao <= 0);

	return dimensao;
}

void mostrarRetangulo(int base, int altura) {
	printf("\nAs dimensões do retângulo são:\n");
	printf("Base: ..... %dcm\n", base);
	printf("Altura: ... %dcm\n", altura);
}

int areaDoRetangulo(int base, int altura) {
	return base * altura;
}

int main() {

	printf("Digite as dimensões de um retângulo:\n");

	int base = lerDimensoes("Valor da base");
	int altura = lerDimensoes("Valor da altura");

	mostrarRetangulo(base, altura);

	printf("\nA área do retângulo é: %dcm²\n", areaDoRetangulo(base, altura));

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}