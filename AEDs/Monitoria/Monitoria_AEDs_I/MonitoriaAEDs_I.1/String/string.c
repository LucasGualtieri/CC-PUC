#include <biblioteca_c.h>

int strlength(char string[]) {
	int contador = 0;

	for (int i = 0; string[i] != '\0'; i++) {
		contador++;
	}

	return contador;
}

int main() {

	char string[5] = { 'R', 'O', 'M', 'A', '\0' };

	// 0 1 2 3 4
	// R O M A \0

	int index = 4;
	if (string[index] == '\0') {
		printf("string[%d]: \\0\n", index);
	} else {
		printf("string[%d]: %c\n", index, string[index]);
	}

	int tamanho = strlength(string);
	printf("Tamanho da minha string: %d\n", tamanho);

	printf("String: %s\n", string);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}