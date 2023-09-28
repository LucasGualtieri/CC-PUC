#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "LibTP02.h"
#include "Jogador.h"
#include "Split.h"

#define STR_MAX_LEN 500

typedef const char* const literal;

const Jogador ERRO = { -0x7fffffff }; // Setta o Id

typedef struct Fila {

	Jogador *array;
	int maxSize, size;
	bool showOnUpdate;

	void (*Inserir)(Jogador jogador, struct Fila*);
	Jogador (*Remover)(struct Fila*);

	void (*ImportDataBase) (literal filePath, struct Fila*);

	void (*ToggleShow) (struct Fila*);
	void (*Mostrar)(struct Fila);
	void (*Close)(struct Fila*); // Implementar o Jogador.close(); Para dar free nas strings

} Fila;

void InserirFila(Jogador jogador, Fila* fila) {

	if (fila->maxSize == 0) {
		puts("Erro ao inserir: Fila fechada.");
		return;
	} else if (fila->size == fila->maxSize) {
		puts("Erro ao inserir: Fila cheia.");
		return;
	}

	fila->array[fila->size++] = jogador;

	if (fila->showOnUpdate) fila->Mostrar(*fila);

}

Jogador RemoverFila(Fila* fila) {

	// Em hexadecimal, cada dígito pode representar 4 bits.
	if (fila->maxSize == 0) {
		puts("Erro ao remover: Fila fechada.");
		return ERRO;
	} else if (fila->size == 0) {
		puts("Erro ao remover: Fila vazia.");
		return ERRO;
	}

	Jogador removido = fila->array[0];

	for (int i = 0; i < fila->size - 1; i++) {
		fila->array[i] = fila->array[i + 1];
	}

	fila->size--;

	if (fila->showOnUpdate) fila->Mostrar(*fila);

	return removido;
}

void ToggleShowOnUpdateFila(Fila* fila) {
	fila->showOnUpdate = fila->showOnUpdate ? false : true;
}

void MostrarFila(Fila fila) {

	// listaJogadores.printPlayer(id, BD); // Loopar pelo id

	if (fila.maxSize == 0) {
		puts("Erro ao mostrar: Fila fechada.");
		return;
	} else if (fila.size == 0) {
		puts("Erro ao mostrar: Fila vazia.");
		return;
	}

	printf("{ ");
	for (int i = 0; i < fila.size; i++) {
		fila.array[i].Mostrar(fila.array[i]);
	}
	printf("}\n");
}

void CloseFila(Fila* fila) {
	free(fila->array);
	// For pra dar free em todos os jogadores
	fila->maxSize = 0;
}

void ImportDataBaseBD(literal filePath, Fila* fila) {

	printf("filePath: %s\n", filePath);

	FILE* CSV = fopen(filePath, "r");
	char inputCSV[STR_MAX_LEN];
	
	while (!feof(CSV)) {

		readStr(CSV, inputCSV);
		printf("inputCSV: %s\n", inputCSV);

		// Split array = newSplit(readStr(CSV, inputCSV), ",");
		Jogador jogador = newJogador();
		// jogador.Construtor(array);

		fila->Inserir(jogador, fila);
	}
}

Fila newFila(size_t maxSize) {

	Fila fila;

	if (maxSize == 0) maxSize = 80;

	fila.size = 0;
	fila.maxSize = maxSize;
	fila.array = (Jogador*)malloc(maxSize * sizeof(Jogador));
	fila.showOnUpdate = false;

	fila.Inserir = InserirFila;
	fila.Remover = RemoverFila;

	fila.ImportDataBase = ImportDataBaseBD;

	fila.ToggleShow = ToggleShowOnUpdateFila;
	fila.Mostrar = MostrarFila;
	fila.Close = CloseFila;

	return fila;
}