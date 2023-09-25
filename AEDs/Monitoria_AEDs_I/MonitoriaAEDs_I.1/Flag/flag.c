#include <biblioteca_c.h>

int main() {

	int idade;

	bool invalido = true;

	do {
		printf("Digite idade: ");
		scanf("%d", &idade);
	} while ((invalido = idade < 0 || idade > 120));

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}