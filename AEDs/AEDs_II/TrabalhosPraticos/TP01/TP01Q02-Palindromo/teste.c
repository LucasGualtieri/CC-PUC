#include <biblioteca_c.h>

int main() {

	int idade;

	printf("Digite sua idade: ");
	scanf("%d", &idade);
	printf("Idade: %d\n", idade);

	pause(1);

	printf("Digite seu nome: ");
	String nome = getstr(0);
	printf("Nome: %s\n", nome);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}