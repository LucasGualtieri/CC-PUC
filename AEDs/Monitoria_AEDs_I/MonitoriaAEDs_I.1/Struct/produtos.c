#include <stdio.h>
#include <string.h>

typedef struct descricao_produtos {
	int	  codigo;
	char  nome[30];
	float preco;
} produto;

void imprimir(produto produto, int i) {
	printf("Listagem: %d\n", i + 1);
	printf("Codigo: %d\n", produto.codigo);
	printf("Nome: %s\n", produto.nome);
	printf("Preco: %.2f\n", produto.preco);
}

float media_preco(produto vetorProdutos[], int tamanhoVetor) {
	float sum = 0;
	for (int i = 0; i < tamanhoVetor; i++) {
		sum += vetorProdutos[i].preco;
	}
	float mediaf = sum / (float)tamanhoVetor;
	return mediaf;
}

produto pesquisa(int codigo, const char nome[], float preco, produto vetorProdutos[], int tamanhoVetor) {
	for (int i = 0; i < tamanhoVetor; i++) {
		if (vetorProdutos[i].codigo == codigo && vetorProdutos[i].preco == preco && !strcmp(vetorProdutos[i].nome, nome)) return vetorProdutos[i];
	}
	return vetorProdutos[0];
}

// void flushSTDIN() {
// 	char c;

// 	while ((c = getchar()) != '\n') {
// 		continue;
// 	}
// }

// int readInt(const char* msg) {
// 	printf("%s", msg);
// 	int integer;
// 	scanf("%d", &integer);
// 	flushSTDIN();
// 	return integer;
// }

int main() {
	int tamanhoVetor;

	printf("Digite o número de produtos: ");
	scanf("%d", &tamanhoVetor);

	produto vetorProdutos[tamanhoVetor];

	for (int i = 0; i < tamanhoVetor; i++) {
		printf("Listagem: %d\n", i + 1);
		printf("Digite o codigo: ");
		scanf("%d%*c", &vetorProdutos[i].codigo);
		printf("Digite o nome: ");
		scanf("%[^\n]", vetorProdutos[i].nome);
		printf("Digite o preço: ");
		scanf("%f", &vetorProdutos[i].preco);
	}

	for (int i = 0; i < tamanhoVetor; i++) {
		imprimir(vetorProdutos[i], i);
	}

	float media = media_preco(vetorProdutos, tamanhoVetor);

	printf("Média dos preços: %.2f\n", media);

	printf("Nome: %s\n", pesquisa(1, "Computador", 20, vetorProdutos, tamanhoVetor).nome);

	printf("\n");

	return 0;
}