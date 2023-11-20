#ifndef LIB_C_PILHA_FLEX
#define LIB_C_PILHA_FLEX

#include "Celulas/CelulaPilha.h"

typedef struct PilhaFlex {

	CelulaPilha *topo;
	int size;

	void (*Mostrar) (struct PilhaFlex);

	void (*Inserir) (Jogador, struct PilhaFlex*);
	Jogador (*Remover) (struct PilhaFlex*);

	void (*Close) (struct PilhaFlex*);

} PilhaFlex;

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

void InserirPilhaFlex(Jogador jogador, PilhaFlex* pilha) {
	pilha->topo = newCelulaPilha(jogador, pilha->topo);
	pilha->size++;
}

Jogador RemoverPilhaFlex(PilhaFlex* pilha) {

	if (pilha->topo == NULL) {
		fprintf(stderr, "Erro ao remover: Pilha Flex vazia.\n");
		exit(0);
	}

	pilha->size--;
	CelulaPilha* removida = pilha->topo;
	pilha->topo = removida->baixo;
	Jogador removido = removida->jogador.Clone(removida->jogador);
	removida->Close(removida);

	return removido;

}

void MostrarPilhaFlexRec(int contador, CelulaPilha* i) {
	if (i->baixo != NULL) MostrarPilhaFlexRec(contador - 1, i->baixo);
	printf("[%d] ## ", contador);
	i->jogador.Mostrar(i->jogador);
}

void MostrarPilhaFlex(PilhaFlex pilha) {

	if (pilha.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Pilha Flex vazia.\n");
		exit(0);
	}

	MostrarPilhaFlexRec(pilha.size - 1, pilha.topo);

}

void ClosePilhaFlex(PilhaFlex* pilha) {
	
	CelulaPilha* i = pilha->topo;
	while (i != NULL) {
		CelulaPilha* tmp = i;
		i = i->baixo;
		tmp->Close(tmp);
	}

	pilha->size = 0;

}

PilhaFlex newPilhaFlex() {

	PilhaFlex pilha;

	pilha.size = 0;
	pilha.topo = NULL;

	pilha.Mostrar = MostrarPilhaFlex;

	pilha.Inserir = InserirPilhaFlex;
	pilha.Remover = RemoverPilhaFlex;

	pilha.Close = ClosePilhaFlex;

	return pilha;
}

#endif