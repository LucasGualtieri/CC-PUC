#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

void flush() {
	char c;
	while ((c = fgetc(stdin)) != '\n' && c != '\r') continue;
}

void clrscreen() {
	system("clear");
}

void replaceAllCommas(string str) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == ',') str[i] = '.';
	}
}

string getstr() {

	string str = (string)malloc(50 * sizeof(char));
	fgets(str, 50, stdin);
	str[(int)strcspn(str, "\r\n")] = '\0';

	str = (string)realloc(str, (strlen(str) + 1) * sizeof(char));

	replaceAllCommas(str);

	return str;
}

#endif /* BIBLIOTECA_H */