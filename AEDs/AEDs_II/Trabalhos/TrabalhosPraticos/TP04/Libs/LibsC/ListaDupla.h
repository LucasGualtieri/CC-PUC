#ifndef LIB_LISTA_DUPLA_H
#define LIB_LISTA_DUPLA_H

#include "Celulas/Celula.h"
#include "LibTP04.h"

typedef struct ListaDupla {

	int size;
	Celula *primeiro, *ultimo;

	void (*Mostrar) (struct ListaDupla);
	bool (*CompareTo) (Jogador, Jogador, Log*);
	void (*InserirFim) (Jogador, struct ListaDupla*);
	bool (*Pesquisar) (Jogador, Log*, struct ListaDupla);
	void (*Close) (struct ListaDupla*);

} ListaDupla;

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

bool CompareToListaDupla(Jogador jog1, Jogador jog2, Log* log) {

	log->comparacoes++;

	int strComp = strcmp(jog1.nome, jog2.nome);

	return strComp == 0;
}

void InserirFimListaDupla(Jogador jogador, ListaDupla* lista) {
	lista->ultimo = lista->ultimo->prox = newCelula(jogador, NULL, NULL);
	lista->size++;
}

bool PesquisarListaDupla(Jogador jogador, Log* log, ListaDupla lista) {

	bool resultado = false;

	for (Celula* i = lista.primeiro->prox; i != NULL; i = i->prox) {
		if (CompareToListaDupla(jogador, i->jogador, log)) {
			resultado = true;
			i = lista.ultimo;
		}
	}

	return resultado;
}

void MostrarListaDupla(ListaDupla lista) {
	if (lista.size == 0) {
		// errx(1, "Erro ao mostrar: Lista Dupla vazia.\n");
	}

	for (Celula* i = lista.primeiro->prox; i != NULL; i = i->prox) {
		puts(i->jogador.nome);
	}

}

void CloseListaDupla(ListaDupla* lista) {
	
	Celula* i = lista->primeiro;
	while (i != NULL) {
		Celula* tmp = i;
		i = i->prox;
		tmp->Close(tmp);
	}

	lista->size = 0;
}

ListaDupla newListaDupla() {

	ListaDupla lista;

	lista.size = 0;
	Celula* new = malloc(sizeof(Celula));
	new->jogador = newJogador();
	new->ant = NULL;
	new->prox = NULL;
	new->Close = CloseCelula;
	lista.primeiro = lista.ultimo = new;

	lista.CompareTo = CompareToListaDupla;

	lista.InserirFim = InserirFimListaDupla;
	lista.Pesquisar = PesquisarListaDupla;

	lista.Mostrar = MostrarListaDupla;
	lista.Close = CloseListaDupla;

	return lista;
}

#endif