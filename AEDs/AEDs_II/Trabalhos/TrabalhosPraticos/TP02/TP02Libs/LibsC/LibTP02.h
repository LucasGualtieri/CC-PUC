#ifndef LIB_TP02_H
#define LIB_TP02_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STR_MAX_LEN 80
#define BD_SIZE 3923 // Quantidade Jogadores

typedef const char* const literal;
typedef char* String;

typedef struct Resultado {
	int comparacoes, movimentacoes;
} Resultado;

char* readStr(FILE* stream, String input) {
	if (!stream) stream = stdin;

	fgets(input, STR_MAX_LEN, stream);
	input[(int)strcspn(input, "\n")] = '\0';
	return input;
}

#include "Lista.h"
#include "Timer.h"

#endif