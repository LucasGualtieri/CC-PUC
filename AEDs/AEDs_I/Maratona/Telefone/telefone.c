#include <stdio.h>
#include <string.h>

char convert(char c) {
	if (c >= '0' && c <= '9' || c == '-') return c;
	if (strchr("abcABC", c)) return '2';
	if (strchr("defDEF", c)) return '3';
	if (strchr("ghiGHI", c)) return '4';
	if (strchr("jklJKL", c)) return '5';
	if (strchr("mnoMNO", c)) return '6';
	if (strchr("pqrsPQRS", c)) return '7';
	if (strchr("tuvTUV", c)) return '8';
	if (strchr("wxyzWXYZ", c)) return '9';
	return 0;
}

int main(void) {

	char str[16]; // 15 + 1 para considerar o '\0'
	scanf("%15s", str);

	for (int i = 0; i < strlen(str); i++) {
		putchar(convert(str[i]));
	}

	return 0;
}