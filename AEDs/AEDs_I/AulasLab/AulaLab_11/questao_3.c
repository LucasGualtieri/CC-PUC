#include <stdio.h>

typedef struct Carro Carro;
struct Carro {
	char marca[15];
	int ano;
	float price;
};

int main(void) {
	int p;

	Carro vetor[5] = {
		{ "Marca1", 2012, 2000 },
		{ "Marca2", 2013, 3000 },
		{ "Marca3", 2014, 4000 },
		{ "Marca4", 2015, 5000 },
		{ "Marca5", 2016, 6000 }
	};

	do {
		printf("Digite um valor: ");
		scanf("%d", &p);

		for (int i = 0; i < 5; i++) {
			if (vetor[i].price < p) {
				printf("\n");
				printf("Marca: %s\n", vetor[i].marca);
				printf("Ano: %d\n", vetor[i].ano);
				printf("Preço: %.2f\n", vetor[i].price);
				printf("\n***************\n");
			}
		}

	} while (p != 0);

	printf("\n ******** FIM DO PROGRAMA ********\n");
	return 0;
}