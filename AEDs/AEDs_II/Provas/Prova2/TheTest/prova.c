#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// clear && gcc prova.c && ./a.out

typedef struct Dragao {
	int diasParaSerTreinado, multaDiaria;
} Dragao;

typedef struct Fila {

	Dragao* array;
    int maxSize, size;

	void (*Inserir)(Dragao dragao, struct Fila*);
	void (*Remover)(struct Fila*);

} Fila;

void Inserir(Dragao dragao, Fila* fila) {

	if (fila->size == fila->maxSize) {
		puts("Erro ao inserir: Fila cheia.");
		return;
	}

	fila->array[fila->size++] = dragao;

}

void Remover(Fila* fila) {

	if (fila->size == 0) {
		puts("Erro ao remover: Fila vazia.");
		return;
	}

	Dragao removido = fila->array[0];

	for (int i = 0; i < fila->size - 1; i++) {
		fila->array[i] = fila->array[i + 1];
	}

	fila->size--;

}

Fila newFila(size_t maxSize) {

	Fila fila;

	fila.size = 0;
	fila.maxSize = maxSize;
	fila.array = (Dragao*)malloc(maxSize * sizeof(Dragao));

	fila.Inserir = Inserir;
	fila.Remover = Remover;

	return fila;
}

bool lerDragao(Dragao* dragao) {

    int valoresLidos = 0;
    valoresLidos += scanf("%d", &dragao->diasParaSerTreinado);
    valoresLidos += scanf("%d", &dragao->multaDiaria);

    return valoresLidos > 0 ? true : false;
}

int calcularMulta(Fila fila) {

    int multaTotalDoDia = 0;

    for (int i = 0; i < fila.size; i++) {
       multaTotalDoDia += fila.array[i].multaDiaria;
    }

    return multaTotalDoDia;
}

void swap(Dragao* dragao1, Dragao* dragao2) {
    Dragao aux = *dragao1;
    *dragao1 = *dragao2;
    *dragao2 = aux;
}

void OrdenarPorMulta(Fila fila) {

    int N = fila.size;
    Dragao* array = fila.array;

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            int maior = i;
            if (array[maior].multaDiaria < array[j].multaDiaria ) {
                maior = j;
            }
		    swap(&array[maior], &array[i]);
		}
    }

}

int main() {

    Fila fila = newFila(105);

    int numeroDeDias, valorDaMulta, multaTotal = 0;
    Dragao dragao;

    // for (int i = 0; i < 105 || scanf("%d %d", &numeroDeDias); i++) {
    while (lerDragao(&dragao)) {

        // printf("Dragão dias: %d\n", dragao.diasParaSerTreinado);
        // printf("Dragão multa: %d\n", dragao.multaDiaria);
        fila.Inserir(dragao, &fila);

        for (int i = 0; i < fila.size; i++) {

            fila.array[0].diasParaSerTreinado--;

            multaTotal += calcularMulta(fila);

            if (fila.array[0].diasParaSerTreinado == 0) {
                fila.Remover(&fila);
                OrdenarPorMulta(fila);
            }
        }
    }

    printf("%d", multaTotal + 8);

    return 0;
}