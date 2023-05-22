#include <biblioteca_c.h>

void PreencheVetor(int vetor[], int tamanhoVetor) {
	for (int i = 0; i < tamanhoVetor; i++) {
		if (i % 2 == 0) { // Se i for PAR
			vetor[i] = -i;
		} else {
			vetor[i] = i;
		}
	}
}

int* metodo(int vetor[], int tamanhoVetor, int* qtdNegativos) {
	// { , , , , , , , , , , }
	int* vetorDeNegativos = (int*)malloc(tamanhoVetor * sizeof(int));

	for (int i = 0; i < tamanhoVetor; i++) {
		if (vetor[i] < 0) {
			vetorDeNegativos[*qtdNegativos] = vetor[i];
			*qtdNegativos = *qtdNegativos + 1;
		}
	}

	// {  ,  , -2,  , -4,  , -6,  , -8,  }
	// { -2, -4, -6, -8 }

	vetorDeNegativos = (int*)realloc(vetorDeNegativos, *qtdNegativos * sizeof(int));

	return vetorDeNegativos;
}

void PrintaVetor(int* vetor, int tamanho) {
	printf("{ ");
	for (int i = 0; i < tamanho; i++) {
		printf("%d", vetor[i]);
		printf("%s", i < tamanho - 1 ? ", " : " }\n");
	}
}

int main() {

	int tamanho = 10;
	int vetor[tamanho]; // { , , , , , , , , , , }

	PreencheVetor(vetor, tamanho); // { 0, 1, -2, 3, -4, 5, -6, 7, -8, 9 }

	int qtdNegativos = 0;
	int* vetorDeNegativos = metodo(vetor, tamanho, &qtdNegativos);

	PrintaVetor(vetor, tamanho);

	PrintaVetor(vetorDeNegativos, qtdNegativos);

	puts("\n******* | FIM DO PROGRAMA | *******\n");

	return 0;
}