#ifndef SPLIT_H
#define SPLIT_H

#include "LibTP02.h"

#define MAX_ATTRIBUTES 8

typedef struct Split {
	int size;
	char array[MAX_ATTRIBUTES][STR_MAX_LEN];
} Split;

Split newSplit(FILE* CSV) {

	Split split = { 8 }; // Inicializa o size com 8

	char valor[STR_MAX_LEN];
	for (int i = 0; i < MAX_ATTRIBUTES; i++) {
		if (fscanf(CSV, "%[^,\n]", valor) == 0) {
			strcpy(split.array[i], "nao informado");
		} else {
			strcpy(split.array[i], valor);
		}
		fgetc(CSV); // Despresando a virgula
	}

	return split;
}

// Split newSplit(FILE* CSV) {

// 	Split split = { 8 }; // Inicializa o size com 8

// 	for (int i = 0; i < MAX_ATTRIBUTES; i++) {
// 		if (fscanf(CSV, "%[^,\n]", split.array[i]) == 0) {
// 			strcpy(split.array[i], "nao informado");
// 		}
// 		fgetc(CSV); // Despresando a virgula
// 	}

// 	return split;
// }

#endif