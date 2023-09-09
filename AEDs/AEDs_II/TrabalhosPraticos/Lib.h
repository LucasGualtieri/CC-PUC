#ifndef LIB_H_
#define LIB_H_

#include <stdio.h>
#include <stdlib.h>

#define bool short
#define TRUE 1
#define true 1
#define FALSE 0
#define false 0

#define equals(a, b) !strcmp(a, b) ? true : false
#define STR_MAX_LEN 400
#define toUpper(c) ('a' <= c && c <= 'z') ? c - 32 : c
#define isalnum(c) ('1' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')

typedef char* String;

size_t strlen(const char* str) {
	int len = 0;
	while (str[len++] != 0);
	return len - 1;
}

bool isEqual(const char* str1, const char* str2) {
	size_t len;
	if ((len = strlen(str1)) != strlen(str2)) return false;

	bool isEqual = true;

	for (int i = 0; i < len; i++) {
		if (str1[i] != str2[i]) {
			isEqual = false;
			i		= len;
		}
	}

	return isEqual;
}

int indexOf(String str, char c) {
	int len = strlen(str) + 1;
	for (int i = 0; i < len - 1; i++) {
		if (str[i] == c) len = i;
	}

	return len;
}

String readstr(String str) {
	fgets(str, STR_MAX_LEN, stdin);
	str[indexOf(str, '\n')] = '\0';
	return str;
}

float getFloat(FILE* stream) {
	if (!stream) stream = stdin;
	float floatValue;
	fscanf(stream, "%f", &floatValue);
	// flush();
	return floatValue;
}

int getInt(FILE* stream) {
	if (!stream) stream = stdin;
	int integer;
	fscanf(stream, "%d", &integer);
	return integer;
}

#endif /* LIB_H_ */
