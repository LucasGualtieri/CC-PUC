#include "../Libs/LibsC/LibTP04.h"
#include "../Libs/LibsC/AVL.h"

// clear && gcc TP04Q03.c && ./a.out < pub.in > result.txt

bool PesquisarAux(No* raiz, String chave, Log* log);

bool Pesquisar(AVL arvore, String chave, Log* log) {

	if (arvore.raiz == NULL) {
		errx(1, "Erro ao Pesquisar na árvore: Árvore vazia.");
	}

	printf("%s raiz ", chave);
	return PesquisarAux(arvore.raiz, chave, log);
}

bool PesquisarAux(No* raiz, String chave, Log* log) {

	bool resultado;
	
	if (raiz == NULL) {
		resultado = false;
	} else if (CompareToStrAVL(chave, raiz, log) < 0) {
		printf("esq ");
		resultado = PesquisarAux(raiz->esq, chave, log);
	} else if (CompareToStrAVL(chave, raiz, log) > 0) {
		printf("dir ");
		resultado = PesquisarAux(raiz->dir, chave, log);
	} else {
		resultado = true;
	}

	return resultado;
}

void main() {

	BD BD = newBD(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);
	AVL arvore = newAVL();

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		arvore.Inserir(BD.Get(id, BD), &arvore);
	}

	Timer timer = newTimer();
	Log log = newLog();

	timer.Start(&timer);
	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		bool resultado = Pesquisar(arvore, inputPUBIN, &log);
		puts(resultado ? "SIM" : "NAO");
	}
	timer.Stop(&timer);

	log.RegistroPesquisa("794989_avl.txt", timer, log);

	arvore.Close(&arvore);
	BD.Close(&BD);
}