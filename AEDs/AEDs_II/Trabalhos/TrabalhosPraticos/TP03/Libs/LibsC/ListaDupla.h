#ifndef LIB_LISTA_DUPLA_H
#define LIB_LISTA_DUPLA_H

#include "CelulaDupla.h"
#include "LibTP03.h"

typedef struct ListaDupla {

	int size;
	Celula *primeiro, *ultimo;

	void (*Mostrar) (struct ListaDupla);
	int (*CompareTo) (Celula* jog1, Celula* jog2, Log* log);
	void (*InserirInicio) (Jogador, struct ListaDupla*);
	void (*InserirFim) (Jogador, struct ListaDupla*);
	void (*Close) (struct ListaDupla*);

} ListaDupla;

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

int CompareToListaDupla(Celula* cel1, Celula* pivot, Log* log) {

	log->comparacoes++;

	Jogador jog1 = cel1->jogador, pivotJog = pivot->jogador;

	int strComp = strcmp(jog1.estadoNascimento, pivotJog.estadoNascimento);

	if (strComp == 0) {
		log->comparacoes++;
		strComp = strcmp(jog1.nome, pivotJog.nome);
	}

	return strComp;
}

void InserirInicioListaDupla(Jogador jogador, ListaDupla* lista) {

	Celula* new = newCelula(jogador, NULL, NULL);
	
	if (lista->primeiro == NULL) lista->primeiro = lista->ultimo = new;

	else {
		new->prox = lista->primeiro;
		lista->primeiro = lista->primeiro->ant = new;
	}

	lista->size++;

}

void InserirFimListaDupla(Jogador jogador, ListaDupla* lista) {

	Celula* new = newCelula(jogador, NULL, NULL);
	
	if (lista->ultimo == NULL) lista->ultimo = lista->primeiro = new;

	else {
		new->ant = lista->ultimo;
		lista->ultimo = lista->ultimo->prox = new;
	}

	lista->size++;

}

void MostrarListaDupla(ListaDupla lista) {
	if (lista.size == 0) {
		errx(1, "Erro ao mostrar: Lista Dupla vazia.\n");
	}

	for (Celula* i = lista.primeiro; i != NULL; i = i->prox) {
		printf("[%d ## ", i->jogador.id);
		printf("%s ## ", i->jogador.nome);
		printf("%d ## ", i->jogador.altura);
		printf("%d ## ", i->jogador.peso);
		printf("%d ## ", i->jogador.anoNascimento);
		printf("%s ## ", i->jogador.universidade);
		printf("%s ## ", i->jogador.cidadeNascimento);
		printf("%s]\n", i->jogador.estadoNascimento);
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
	lista.primeiro = lista.ultimo = NULL;

	lista.CompareTo = CompareToListaDupla;

	lista.InserirInicio = InserirInicioListaDupla;
	lista.InserirFim = InserirFimListaDupla;

	lista.Mostrar = MostrarListaDupla;
	lista.Close = CloseListaDupla;

	return lista;
}

#endif