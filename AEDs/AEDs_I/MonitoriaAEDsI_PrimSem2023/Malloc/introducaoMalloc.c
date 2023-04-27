#include <biblioteca_c.h>

/*
	Faça um programa que crie e preencha um vetor de inteiros[2]
	dentro de uma função, MAS printe esses valores na main;
*/

int* preencheVetor(/*parametros*/) {
	// Criando um vetor de tamanho 2, usando malloc
	int* vetor = malloc(2 * sizeof(2)); // Mesma coisa que int vetor[2];

	// Atribuindo valores às duas posições do vetor
	scanf("%d %d", &vetor[0], &vetor[1]);

	// Retornando o endereço de vetor
	return vetor;
}

int main() {

	/*
		Criando um ponteiro para inteiros
		Que receberá o endereço de memória
		de um vetor;
	*/
	int* vetor = preencheVetor();

	printf("P1: %d\n", vetor[0]);
	printf("P2: %d\n", vetor[1]);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}