#include <biblioteca_c.h>

int lerDimensoes(char* string) {
	int dimensao;
	bool flag = false;

	printf("%s: ", string);
	do {
		if (flag) printf("%s (o valor deve ser > 0): ", string);
		scanf("%d", &dimensao);
		flag = true;
	} while (dimensao <= 0);

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