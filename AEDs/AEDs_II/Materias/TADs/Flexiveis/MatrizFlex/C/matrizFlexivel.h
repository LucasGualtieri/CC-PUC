#include <stdio.h>
#include <stdbool.h>
#include "matrixCell.h"

#ifndef MATRIZ_FLEX_H
#define MATRIZ_FLEX_H

#define MAX 0x7fffffff

typedef struct MatrizFlex {
	int nRows, nCols;
	MatrixCell* start;
	// bool showOnUpdate, isClosed;
	
	// void (*Inserir)(int number, struct MatrizFlex*); // ALOCAR CELULAS?

	// void (*Inserir)(int number, struct MatrizFlex*);
	// int (*Remover)(struct MatrizFlex*);

	// void (*ToggleShow) (struct MatrizFlex*);
	void (*Print)(struct MatrizFlex);
	// void (*Close)(struct MatrizFlex*);
	// void (*Open)(struct MatrizFlex*);
	// void (*Free)(struct MatrizFlex*);

} MatrizFlex;

// void ToggleShowOnUpdateMatrizFlex(MatrizFlex* pilha) {
// 	pilha->showOnUpdate = pilha->showOnUpdate ? false : true;
// }

void PrintMatrizFlex(MatrizFlex matrix) {

	// if (!pilha.topo->prox) {
	// 	fprintf(stderr, "Erro ao mostrar: Pilha vazia.\n");
	// 	return;
	// }

	// printf("{ ");
	MatrixCell *i, *j;
	for (i = matrix.start; i != NULL; i = i->bottom) {
		for (j = i; j != NULL; j = j->right) {
			printf("%d ", j->value);
		}
		printf("\n");
	}
	// printf("}\n");
}

// void CloseMatrizFlex(MatrizFlex* pilha) {
// 	if (pilha->isClosed) {
// 		fprintf(stderr, "Pilha já está fechada.\n");
// 		return;
// 	}
// 	pilha->isClosed = true;
// }

// void FreeMatrizFlex(MatrizFlex* pilha) {
// 	Celula* tmp;
// 	for (Celula* i = pilha->topo; !i->prox; i = tmp) {
// 		tmp = i->prox;
// 		free(i);
// 	}
// }

// void AlocarCelulas(MatrizFlex* matrix) {
	
// 	MatrixCell *auxLeft, *auxTop = NULL, *tmp;

// 	int contador = 1;

// 	matrix->start = tmp = auxLeft = newMatrixCell(contador++, NULL, auxTop);

// 	for (int i = 0; i < matrix->nRows; i++) {
// 		for (int j = 0; j < matrix->nCols - 1; j++) {
// 			tmp = tmp->right = newMatrixCell(contador++, tmp, auxTop);
// 			if (i != 0) auxTop = auxTop->right;
// 		}
// 		auxTop = auxLeft;
// 		if (i < matrix->nRows - 1) {
// 			tmp = auxLeft = auxLeft->bottom = newMatrixCell(contador++, NULL, auxTop);
// 		}
// 	}

// }

void AlocarCelulas(MatrizFlex* matrix) {

	MatrixCell *auxLeft, *auxTop = NULL, *tmp;

	int contador = 10;

	matrix->start = tmp = auxLeft = auxTop = newMatrixCell(contador++, NULL, NULL);

	for (int i = 0; i < matrix->nCols - 1; i++) {
		tmp = tmp->right = newMatrixCell(contador++, tmp, NULL);
	}

	for (int i = 0; i < matrix->nRows - 1; i++) {
		auxTop->bottom = tmp = auxLeft = auxLeft->bottom = newMatrixCell(contador++, NULL, auxTop);
		for (int j = 0; j < matrix->nCols - 1; j++) {
			auxTop = auxTop->right;
			auxTop->bottom = tmp = tmp->right = newMatrixCell(contador++, tmp, auxTop);
		}
		auxTop = auxLeft;
	}

}

MatrizFlex newMatrizFlex(int nRows, int nCols) {

	MatrizFlex matrix;

	matrix.nRows = nRows;
	matrix.nCols = nCols;
	matrix.start = NULL;

	AlocarCelulas(&matrix);

	// MatrixCell* start = newMatrixCell(0, NULL, NULL);

	// pilha.topo = cabeca;
	// pilha.showOnUpdate = false;
	// pilha.isClosed = false;

	// pilha.Inserir = InserirMatrizFlex;
	// pilha.Remover = RemoverMatrizFlex;

	// pilha.ToggleShow = ToggleShowOnUpdateMatrizFlex;
	matrix.Print = PrintMatrizFlex;
	// pilha.Close = CloseMatrizFlex;
	// pilha.Open = OpenMatrizFlex;
	// pilha.Free = FreeMatrizFlex;

	return matrix;
}

#endif