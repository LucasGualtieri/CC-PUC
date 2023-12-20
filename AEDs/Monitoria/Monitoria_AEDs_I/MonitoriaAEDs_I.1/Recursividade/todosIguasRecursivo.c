#include <biblioteca_c.h>

// ........................  Começo   e  Fim -> da Busca
bool Iguais(int vetor[], int comeco, int fim) {

	if (comeco < fim) { // Se ele não chegou no fim, faça...
		if (vetor[comeco] != vetor[fim]) { // Se é diferente, retorne que é diferente.
			return false; // Condição de parada.
		} else { // Se é igual, continue buscando.
			return Iguais(vetor, comeco + 1, fim - 1); // Chamada recursiva. Aonde damos seguimento à nossa busca.
		}
	} else { // Se chegou ao fim podemos concluir que todos são iguais!
		return true; // Condição de parada.
	}
}

int main() {
	int vetor[] = { 1, 1, 1, 1 };
	int tamanho = 4;

	int primeiro = 0; // O vetor começa no 0, então começamos a busca no começo
	int ultimo = tamanho - 1; // Último número do vetor

	bool iguais = Iguais(vetor, primeiro, ultimo); // Retorna true se todos forem iguais

	if (iguais == true) {
		printf("Todos os números são iguais\n");
	} else {
		printf("Nem todos os números são iguais\n");
	}

	// puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}