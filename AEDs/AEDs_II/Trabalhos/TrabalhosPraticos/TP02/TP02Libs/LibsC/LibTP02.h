#ifndef LibTP02_H
#define LibTP02_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define STR_MAX_LEN 500
#define BD_SIZE 3922 // Quantidade Jogadores

typedef const char* const literal;
typedef char* String;

char* readStr(FILE* stream, String input) {
	if (!stream) stream = stdin;

	fgets(input, STR_MAX_LEN, stream);
	input[(int)strcspn(input, "\r\n")] = '\0';
	return input;
}

#include "Fila.h"

#endif