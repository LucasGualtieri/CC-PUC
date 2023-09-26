#include <stdbool.h>
#include "../celula.h"

#define ERRO -0x7fffffff

typedef struct PilhaFlex {
	Celula* topo;
	bool showOnUpdate, isClosed;

	void (*Inserir)(int number, struct PilhaFlex*);
	int (*Remover)(struct PilhaFlex*);

	void (*ToggleShow) (struct PilhaFlex*);
	void (*Mostrar)(struct PilhaFlex);
	void (*Close)(struct PilhaFlex*);
	void (*Open)(struct PilhaFlex*);
	void (*Free)(struct PilhaFlex*);

} PilhaFlex;

void InserirPilhaFlex(int valor, PilhaFlex* pilha) {

	// printf("Valor: %d\n", valor);

	Celula* newCelulaTmp = newCelula(valor, pilha->topo);
	// printf("newCelulaTmp: %d\n", newCelulaTmp->valor);

	if (!newCelula) {
		fprintf(stderr, "Erro ao inserir.\n");
		return;
	} else if (pilha->isClosed) {
		fprintf(stderr, "Erro ao inserir: Pilha fechada.\n");
		return;
	}

	pilha->topo = newCelulaTmp;
	// printf("pilha->topo->valor: %d\n", pilha->topo->valor);

	if (pilha->showOnUpdate) pilha->Mostrar(*pilha);
}

int RemoverPilhaFlex(PilhaFlex* pilha) {

	// Em hexadecimal, cada dígito pode representar 4 bits.
	if (!pilha->topo->prox) {
		fprintf(stderr, "Erro ao remover: Pilha vazia.\n");
		return ERRO;
	} else if (pilha->isClosed) {
		fprintf(stderr, "Erro ao remover: Pilha fechada.\n");
		return ERRO;
	}

	int removidoValor = pilha->topo->valor;
	Celula* removidoCelula = pilha->topo;
	pilha->topo = pilha->topo->prox;
	free(removidoCelula);

	if (pilha->showOnUpdate) pilha->Mostrar(*pilha);

	return removidoValor;
}

void ToggleShowOnUpdatePilhaFlex(PilhaFlex* pilha) {
	pilha->showOnUpdate = pilha->showOnUpdate ? false : true;
}

void MostrarPilhaFlex(PilhaFlex pilha) {

	if (!pilha.topo->prox) {
		fprintf(stderr, "Erro ao mostrar: Pilha vazia.\n");
		return;
	}

	printf("{ ");
	for (Celula* i = pilha.topo; i->prox; i = i->prox) {
		printf("%d ", i->valor);
	}
	printf("}\n");
}

void OpenPilhaFlex(PilhaFlex* pilha) {
	if (!pilha->isClosed) {
		fprintf(stderr, "Pilha já está aberta.\n");
		return;
	}
	pilha->isClosed = false;
}

void ClosePilhaFlex(PilhaFlex* pilha) {
	if (pilha->isClosed) {
		fprintf(stderr, "Pilha já está fechada.\n");
		return;
	}
	pilha->isClosed = true;
}

void FreePilhaFlex(PilhaFlex* pilha) {
	Celula* tmp;
	for (Celula* i = pilha->topo; !i->prox; i = tmp) {
		tmp = i->prox;
		free(i);
	}
}

PilhaFlex newPilhaFlex() {

	PilhaFlex pilha;

	Celula* cabeca = newCelula(0, NULL);

	pilha.topo = cabeca;
	pilha.showOnUpdate = false;
	pilha.isClosed = false;

	pilha.Inserir = InserirPilhaFlex;
	pilha.Remover = RemoverPilhaFlex;

	pilha.ToggleShow = ToggleShowOnUpdatePilhaFlex;
	pilha.Mostrar = MostrarPilhaFlex;
	pilha.Close = ClosePilhaFlex;
	pilha.Open = OpenPilhaFlex;
	pilha.Free = FreePilhaFlex;

	return pilha;
}