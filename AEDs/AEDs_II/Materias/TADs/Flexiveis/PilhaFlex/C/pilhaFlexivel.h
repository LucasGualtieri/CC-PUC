#include <stdbool.h>
#include "CelulaPilha.h"

#define ERRO -0x7fffffff

typedef struct PilhaFlex {
	CelulaPilha* topo;
	bool showOnUpdate, isClosed;

	void (*Inserir)(int number, struct PilhaFlex*);
	int (*Remover)(struct PilhaFlex*);

	void (*ToggleShow) (struct PilhaFlex*);
	void (*Mostrar)(struct PilhaFlex);
	void (*MostrarEmOrdem)(struct PilhaFlex);
	void (*Close)(struct PilhaFlex*);
	void (*Open)(struct PilhaFlex*);
	void (*Free)(struct PilhaFlex*);

} PilhaFlex;

void InserirPilhaFlex(int value, PilhaFlex* pilha) {

	// printf("Valor: %d\n", value);

	CelulaPilha* newCelulaPilhaTmp = newCelulaPilha(value, pilha->topo);
	// printf("newCelulaPilhaTmp: %d\n", newCelulaPilhaTmp->value);

	if (!newCelulaPilha) {
		fprintf(stderr, "Erro ao inserir.\n");
		return;
	} else if (pilha->isClosed) {
		fprintf(stderr, "Erro ao inserir: Pilha fechada.\n");
		return;
	}

	pilha->topo = newCelulaPilhaTmp;
	// printf("pilha->topo->value: %d\n", pilha->topo->value);

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

	int removidoValor = pilha->topo->value;
	CelulaPilha* removidoCelulaPilha = pilha->topo;
	pilha->topo = pilha->topo->prox;
	free(removidoCelulaPilha);

	if (pilha->showOnUpdate) pilha->Mostrar(*pilha);

	return removidoValor;
}

void ToggleShowOnUpdatePilhaFlex(PilhaFlex* pilha) {
	pilha->showOnUpdate = pilha->showOnUpdate ? false : true;
}

void MostrarEmOrdemPilhaFlex(PilhaFlex pilha) {

	if (!pilha.topo->prox) {
		fprintf(stderr, "Erro ao mostrar: Pilha vazia.\n");
		return;
	}

	CelulaPilha* primeiro = pilha.topo;
	while (primeiro->prox != NULL) primeiro = primeiro->prox;

	printf("{ ");
	while (primeiro != pilha.topo) {
		CelulaPilha* i;
		for (i = pilha.topo; i->prox != primeiro; i = i->prox);
		printf("%d ", i->value);
		primeiro = i;
	}
	printf("}\n");
}

void MostrarPilhaFlex(PilhaFlex pilha) {

	if (!pilha.topo->prox) {
		fprintf(stderr, "Erro ao mostrar: Pilha vazia.\n");
		return;
	}

	printf("{ ");
	for (CelulaPilha* i = pilha.topo; i->prox; i = i->prox) {
		printf("%d ", i->value);
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
	CelulaPilha* tmp;
	for (CelulaPilha* i = pilha->topo; !i->prox; i = tmp) {
		tmp = i->prox;
		free(i);
	}
}

PilhaFlex newPilhaFlex() {

	PilhaFlex pilha;

	CelulaPilha* cabeca = newCelulaPilha(0, NULL);

	pilha.topo = cabeca;
	pilha.showOnUpdate = false;
	pilha.isClosed = false;

	pilha.Inserir = InserirPilhaFlex;
	pilha.Remover = RemoverPilhaFlex;

	pilha.ToggleShow = ToggleShowOnUpdatePilhaFlex;
	pilha.Mostrar = MostrarPilhaFlex;
	pilha.MostrarEmOrdem = MostrarEmOrdemPilhaFlex;
	pilha.Close = ClosePilhaFlex;
	pilha.Open = OpenPilhaFlex;
	pilha.Free = FreePilhaFlex;

	return pilha;
}