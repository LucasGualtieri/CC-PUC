#ifndef LIB_AVL_H
#define LIB_AVL_H

#define max(val1, val2) (val1 > val2 ? val1 : val2)
#define getFator(raiz) (alturaDir(raiz) - alturaEsq(raiz))
#define alturaDir(raiz) (raiz->dir == NULL ? 0 : raiz->dir->nivel)
#define alturaEsq(raiz) (raiz->esq == NULL ? 0 : raiz->esq->nivel)

#include "Celulas/No.h"
#include "LibTP04.h"

typedef struct AVL {

	No* raiz;

	void (*Inserir) (Jogador, struct AVL*);
	bool (*Pesquisar) (Jogador, Log*, struct AVL);

	int (*Altura) (struct AVL);
	void (*Mostrar) (struct AVL);

	void (*Close) (struct AVL*);

} AVL;

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

int CompareToNomeAVL(Jogador jogador, No* raiz, Log* log) {
	log->comparacoes++;
	return strcmp(jogador.nome, raiz->jogador.nome);
}

No* Balancear(No* raiz);

No* InserirAVLAux(Jogador jogador, No* raiz, Log* log) {

	if (raiz == NULL) {
		raiz = newNo(jogador, NULL, NULL);
	} else if (CompareToNomeAVL(jogador, raiz, log) < 0) {
		raiz->esq = InserirAVLAux(jogador, raiz->esq, log);
	} else if (CompareToNomeAVL(jogador, raiz, log) > 0) {
		raiz->dir = InserirAVLAux(jogador, raiz->dir, log);
	} else {
		errx(1, "Erro ao inserir na Árvore: Jogador '%s' repetido.", jogador.nome);
	}

	return Balancear(raiz);
}

void InserirAVL(Jogador jogador, AVL* arvore) {
	Log log;
	arvore->raiz = InserirAVLAux(jogador, arvore->raiz, &log);
}

bool PesquisarAVLAux(Jogador jogador, No* raiz, Log* log) {

	bool resultado;

	if (raiz == NULL) {
		resultado = false;
	} else if (CompareToNomeAVL(jogador, raiz, log) < 0) {
		resultado = PesquisarAVLAux(jogador, raiz->esq, log);
	} else if (CompareToNomeAVL(jogador, raiz, log) > 0) {
		resultado = PesquisarAVLAux(jogador, raiz->dir, log);
	} else {
		resultado = true;
	}

	return resultado;
}

bool PesquisarAVL(Jogador jogador, Log* log, AVL arvore) {

	if (arvore.raiz == NULL) {
		// errx(1, "Erro ao pesquisar na árvore: Árvore vazia.");
	}

	return PesquisarAVLAux(jogador, arvore.raiz, log);
}

No* RotacaoSimplesEsq(No* raiz) {

	No* aux = raiz->dir;
	raiz->dir = aux->esq;
	aux->esq = raiz;

	raiz->setNivel(raiz);
	aux->setNivel(aux);

	return aux;
}

No* RotacaoSimplesDir(No* raiz) {

	No* aux = raiz->esq;
	raiz->esq = aux->dir;
	aux->dir = raiz;

	raiz->setNivel(raiz);
	aux->setNivel(aux);

	return aux;
}

No* RotacaoDuplaDirEsq(No* raiz) {
	raiz->dir = RotacaoSimplesDir(raiz->dir);
	return RotacaoSimplesEsq(raiz);
}

No* RotacaoDuplaEsqDir(No* raiz) {
	raiz->esq = RotacaoSimplesEsq(raiz->esq);
	return RotacaoSimplesDir(raiz);
}

No* Balancear(No* raiz) {

	raiz->setNivel(raiz);

	if (getFator(raiz) == 2) {

		if (getFator(raiz->dir) == 1) {
			raiz = RotacaoSimplesEsq(raiz);
		} else {
			raiz = RotacaoDuplaDirEsq(raiz);
		}
	}
	
	else if (getFator(raiz) == -2) {

		if (getFator(raiz->esq) == -1) {
			raiz = RotacaoSimplesDir(raiz);
		} else {
			raiz = RotacaoDuplaEsqDir(raiz);
		}
	}

	return raiz;
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

int AlturaAVL(AVL arvore) {

	if (arvore.raiz == NULL) {
		errx(0, "Erro ao printar árvore: Árvore vazia.");
	}

	int esq = alturaEsq(arvore.raiz);
	int dir = alturaDir(arvore.raiz);

	return esq > dir ? esq : dir;
}

void CloseAVLAux(No* i) {
	if (i != NULL) {
		CloseAVLAux(i->esq);
		CloseAVLAux(i->dir);
		i->Close(i);
	}
}

void CloseAVL(AVL* arvore) {
	CloseAVLAux(arvore->raiz);
	arvore->raiz = NULL;
}

AVL newAVL() {

	AVL arvore;

	arvore.raiz = NULL;

	arvore.Inserir = InserirAVL;
	arvore.Pesquisar = PesquisarAVL;

	arvore.Altura = AlturaAVL;
	arvore.Mostrar = MostrarAVL;

	arvore.Close = CloseAVL;

	return arvore;
}

#endif