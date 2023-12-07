#ifndef LIB_AVL_H
#define LIB_AVL_H

#include "Celulas/No.h"
#include "LibTP04.h"

typedef struct AVL {
	No* raiz;
	void (*Inserir) (Jogador, struct AVL*);
	void (*Mostrar) (struct AVL);
	void (*Close) (struct AVL*);

} AVL;

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

int CompareToAVL(String nome, No* raiz, Log* log) {
	log->comparacoes++;
	return strcmp(nome, raiz->jogador.nome);
}

No* Balancear(No* raiz);

#define getFator(raiz)(alturaDir(raiz) - alturaEsq(raiz))
#define alturaDir(raiz)(raiz->dir == NULL ? 0 : raiz->dir->nivel)
#define alturaEsq(raiz)(raiz->esq == NULL ? 0 : raiz->esq->nivel)

No* InserirAVLAux(Jogador jogador, No* raiz, Log* log) {

	if (raiz == NULL) {
		raiz = newNo(jogador, NULL, NULL);
	} else if (CompareToAVL(jogador.nome, raiz, log) < 0) {
		raiz->esq = InserirAVLAux(jogador, raiz->esq, log);
	} else if (CompareToAVL(jogador.nome, raiz, log) > 0) {
		raiz->dir = InserirAVLAux(jogador, raiz->dir, log);
	} else {
		errx(1, "Erro ao inserir na Árvore: Jogador '%s' repetido.", jogador.nome);
	}

	raiz->nivel = (alturaDir(raiz) - alturaEsq(raiz)) + 1;

	return Balancear(raiz);
}

No* Balancear(No* raiz) {

	int fator = getFator(raiz);

	// if (fator == 2 || fator == -2) puts("Vai ter que balancear");

	if (fator == 2) {
		if (getFator(raiz->dir) == 1) {
			// raiz = RotacaoSimplesEsq(raiz);
		} else {
			// raiz = RotacaoDuplaDirEsq(raiz);
		}
	} else if (fator == -2) {
		if (getFator(raiz->esq) == -1) {
			// raiz = RotacaoSimplesDir(raiz);
		} else {
			// raiz = RotacaoDuplaEsqDir(raiz);
		}
	}

	return raiz;
} 

void InserirAVL(Jogador jogador, AVL* arvore) {
	Log log;
	arvore->raiz = InserirAVLAux(jogador, arvore->raiz, &log);
}

void MostrarAux(No* raiz) {

	if (raiz != NULL) {
		MostrarAux(raiz->esq);
		puts(raiz->jogador.nome);
		MostrarAux(raiz->dir);
	}
}

void MostrarAVL(AVL arvore) {

	if (arvore.raiz == NULL) {
		errx(1, "Erro ao printar na Árvore: Árvore vazia.");
	}

	puts("---- Mostrar Arvore ----");
	MostrarAux(arvore.raiz);
}

void CloseAVLAux(No* i) {
	CloseAVLAux(i->esq);
	CloseAVLAux(i->dir);
	free(i);
}

void CloseAVL(AVL* arvore) {
	CloseAVLAux(arvore->raiz);
	arvore->raiz = NULL;
}

AVL newAVL() {

	AVL arvore;

	arvore.raiz = NULL;

	arvore.Inserir = InserirAVL;
	arvore.Mostrar = MostrarAVL;

	arvore.Close = CloseAVL;

	return arvore;
}

#endif