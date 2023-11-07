#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// clear && gcc provaV2.c && ./a.out < pub.in > result.txt

typedef struct Dragon {
	int diasDeTreino, multaDiaria;
	float maiorMultaRelativa;
} Dragon;

typedef struct Fila Fila;

void OrdenarPorMulta(Fila fila);
void Inserir(Dragon dragon, Fila* fila);
void Remover(Fila* fila);

struct Fila {

	Dragon* array;
	int maxSize, size;

	void (*Inserir)(Dragon dragon, struct Fila*);
	void (*Remover)(struct Fila*);

};

Fila newFila(size_t maxSize) {

	Fila fila;

	fila.size = 0;
	fila.maxSize = maxSize;
	fila.array = malloc(maxSize * sizeof(Dragon));

	fila.Inserir = Inserir;
	fila.Remover = Remover;

	return fila;

}

void Inserir(Dragon dragon, Fila* fila) {
	fila->array[fila->size++] = dragon;
}

void Remover(Fila* fila) {

	for (int i = 0; i < fila->size - 1; i++) {
		fila->array[i] = fila->array[i + 1];
	}

	fila->size--;

}

bool lerDragao(Dragon* dragon) {

	int valoresLidos = 0;
	valoresLidos += scanf("%d", &dragon->diasDeTreino);
	valoresLidos += scanf("%d", &dragon->multaDiaria);

	dragon->maiorMultaRelativa = (float)dragon->multaDiaria / dragon->diasDeTreino;

	return valoresLidos > 0 ? true : false;

}

int calcularMulta(Fila fila) {

	int multaTotalDoDia = 0;

	for (int i = 0; i < fila.size; i++) {
		multaTotalDoDia += fila.array[i].multaDiaria;
	}

	return multaTotalDoDia;
}

int main() {

	Dragon dragon;
	Fila fila = newFila(105);

	int multaTotal = 0;

	while (lerDragao(&dragon)) {

		fila.Inserir(dragon, &fila);

		for (int i = 0; i < fila.size; i++) {

			fila.array[0].diasDeTreino--;

			multaTotal += calcularMulta(fila);

			if (fila.array[0].diasDeTreino == 0) {
				fila.Remover(&fila);
				OrdenarPorMulta(fila);
			}

		}
	}

	printf("%d", multaTotal + 8);

	return 0;
}

void swap(Dragon* dragao1, Dragon* dragao2) {
	Dragon aux = *dragao1;
	*dragao1 = *dragao2;
	*dragao2 = aux;
}

void OrdenarPorMulta(Fila fila) {

	int N = fila.size;
	Dragon* array = fila.array;

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			int maior = i;
			if (array[maior].maiorMultaRelativa < array[j].maiorMultaRelativa) {
				maior = j;
			}
			swap(&array[maior], &array[i]);
		}
	}

}