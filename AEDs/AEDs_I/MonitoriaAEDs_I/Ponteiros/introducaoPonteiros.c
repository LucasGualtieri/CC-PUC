#include <biblioteca_c.h>

void alteraValor(int* ponteiro) {
	*ponteiro = 18;
}

int main() {

	int idade;
	int* ponteiro;

	idade = 20;
	ponteiro = &idade;

	if (ponteiro == &idade) {
		printf("ponteiro = &idade\n");
		printf("%p = %p\n", ponteiro, &idade);
	}

	printf("---------------------------------\n");

	if (*ponteiro == idade) {
		printf("*ponteiro = idade\n");
		printf("%d = %d\n", *ponteiro, idade);
	}

	printf("---------------------------------\n");

	if (*ponteiro == *&idade) {
		printf("*ponteiro = *&idade\n");
		printf("%d = %d\n", *ponteiro, *&idade);
	}

	printf("---------------------------------\n");

	// É necessario essa conversão, pois são endereços de tipos diferentes.
	if ((int*)&ponteiro != &idade) { // &ponteiro != (int**)&idade
		printf("&ponteiro != &idade\n");
		printf("%p != %p\n", &ponteiro, &idade);
	}

	printf("---------------------------------\n");

	alteraValor(&idade);

	printf("Idade: %d\n", idade);

	printf("---------------------------------\n");

	int x = 25;
	ponteiro = &x;

	printf("X: %d\n", *ponteiro);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}