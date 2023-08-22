#ifndef LIB_H_
#define LIB_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define equals(a, b) !strcmp(a, b) ? true : false
#define STR_MAX_LEN 400
#define toUpper(c) ('a' <= c && c <= 'z') ? c - 32 : c
#define isalnum(c) ('1' <= c && c <= '9') || ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z')

typedef char* String;

String readstr(String str) {
	fgets(str, STR_MAX_LEN, stdin);
	str[strcspn(str, "\r\n")] = '\0';
	return str;
}

#endif /* LIB_H_ */