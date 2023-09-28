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

	char teste[500];
	for (int i = 0; i < MAX_ATTRIBUTES; i++) {
		if (fscanf(CSV, "%[^,\n\r]", teste) == 0) {
			strcpy(split.array[i], "nao informado");
		} else {
			strcpy(split.array[i], teste);
		}
		fgetc(CSV); // Despresando a virgula
	}

	return split;
}

#endif