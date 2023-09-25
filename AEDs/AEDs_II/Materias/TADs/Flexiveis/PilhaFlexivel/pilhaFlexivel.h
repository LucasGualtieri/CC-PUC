#include <stdbool.h>
#include "../celula.h"

typedef struct PilhaFlex {
	Celula* topo;
	bool showOnUpdate;

	void (*Inserir)(int number, struct Pilha*);
	int (*Remover)(struct Pilha*);

	void (*ToggleShow) (struct Pilha*);
	void (*Mostrar)(struct Pilha);
	void (*Close)(struct Pilha*);

} PilhaFlex;

void InserirPilhaFlex(int value, Pilha* pilha) {

	Celula* newCell = newCelula(value, pilha.topo);
	if (!newCell) printf("Erro");
	pilha->topo = newCell;

	// --------------------------

	if (pilha->maxSize == 0) {
		puts("Erro ao inserir: Pilha fechada.");
		return;
	} else if (pilha->size == pilha->maxSize) {
		puts("Erro ao inserir: Pilha cheia.");
		return;
	}

	pilha->array[pilha->size++] = number;

	if (pilha->showOnUpdate) pilha->Mostrar(*pilha);

}

int RemoverPilhaFlex(Pilha* pilha) {

	// Em hexadecimal, cada dígito pode representar 4 bits.
	if (pilha->maxSize == 0) {
		puts("Erro ao remover: Pilha fechada.");
		return -0x7fffffff;
	} else if (pilha->size == 0) {
		puts("Erro ao remover: Pilha vazia.");
		return -0x7fffffff;
	}

	int removido = pilha->array[--pilha->size];

	if (pilha->showOnUpdate) pilha->Mostrar(*pilha);

	return removido;
}

void ToggleShowOnUpdatePilhaFlex(Pilha* pilha) {
	pilha->showOnUpdate = pilha->showOnUpdate ? false : true;
}

void MostrarPilhaFlex(Pilha pilha) {

	if (pilha.maxSize == 0) {
		puts("Erro ao mostrar: Pilha fechada.");
		return;
	} else if (pilha.size == 0) {
		puts("Erro ao mostrar: Fila vazia.");
		return;
	}

	printf("{ ");
	for (int i = 0; i < pilha.size; i++) {
		printf("%d ", pilha.array[i]);
	}
	printf("}\n");
}

void ClosePilhaFlex(Pilha* pilha) {
	free(pilha->array);
	pilha->maxSize = 0;
}

Pilha newPilha(size_t maxSize) {

	Pilha pilha;

	Celula cabeca = newCelula(NULL, NULL);

	pilha.topo = cabeca;
	pilha.showOnUpdate = false;

	pilha.Inserir = InserirPilhaFlex;
	pilha.Remover = RemoverPilhaFlex;

	pilha.ToggleShow = ToggleShowOnUpdatePilhaFlex;
	pilha.Mostrar = MostrarPilhaFlex;
	pilha.Close = ClosePilhaFlex;

	return pilha;
}