#include <stdio.h>
#include <string.h>

char convert(char c) {
	if (c == '-') {
		return '-';
	}
	if (c >= 'A' && c <= 'C' || c >= 'a' && c <= 'c') {
		return '2';
	}
	if (c >= 'D' && c <= 'F' || c >= 'd' && c <= 'f') {
		return '3';
	}
	if (c >= 'G' && c <= 'I' || c >= 'g' && c <= 'i') {
		return '4';
	}
	if (c >= 'J' && c <= 'L' || c >= 'j' && c <= 'l') {
		return '5';
	}
	if (c >= 'M' && c <= 'O' || c >= 'm' && c <= 'o') {
		return '6';
	}
	if (c >= 'P' && c <= 'S' || c >= 'p' && c <= 's') {
		return '7';
	}
	if (c >= 'T' && c <= 'V' || c >= 't' && c <= 'v') {
		return '8';
	}
	if (c >= 'W' && c <= 'Z' || c >= 'w' && c <= 'z') {
		return '9';
	}
	return 0;
}

int main(void) {
	char str[16];
	scanf("%s", str);
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] >= '0' && str[i] <= '9') {
			printf("%c", str[i]);
		} else {
			printf("%c", convert(str[i]));
		}
	}
	return 0;
}