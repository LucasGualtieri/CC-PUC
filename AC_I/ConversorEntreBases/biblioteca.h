#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_MAX_LEN 50

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

int indexOf(string str, char reference) {

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == reference) return i;
	}
	return -1;
}

void trimZeros(string str) {

	int ponto = indexOf(str, '.');

	if (ponto == -1) return;

	for (int i = strlen(str) - 1; i >= ponto; i--) {
		if (str[i] == '0') {
			str[i] = 0;
		} else if (str[i] == '.') {
			str[i] = 0;
		} else {
			return;
		}
	}
}

void trimSpaces(string str) {
	for (int i = strlen(str) - 1; i >= 0; i--) {
		if (str[i] == ' ') {
			str[i] = 0;
		} else {
			return;
		}
	}
}

string getstr() {

	string str = (string)malloc(STR_MAX_LEN * sizeof(char));
	fgets(str, STR_MAX_LEN, stdin);
	str[(int)strcspn(str, "\r\n")] = '\0';

	// str = (string)realloc(str, (strlen(str) + 1) * sizeof(char));

	replaceAllCommas(str);
	trimSpaces(str);

	return str;
}

char toUpper(char c) {
	return (char)('a' <= c && c <= 'z' ? c - 32 : c);
}

int ctoi(char c) {
	if (!isalnum(c)) return 16; // Maior base de conversão
	return 'A' <= (c = toUpper(c)) && c <= 'F' ? c - 55 : c - 48;
}

char itoa(int val) {
	return 10 <= val && val <= 15 ? val + 55 : val + 48;
}

#endif /* BIBLIOTECA_H */