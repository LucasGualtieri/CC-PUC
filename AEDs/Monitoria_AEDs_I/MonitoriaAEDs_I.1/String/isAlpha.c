#include <biblioteca_c.h>

int isAlpha2(char c) {
	if (c >= 'A' && c <= 'Z') return 1;
	if (c >= 'a' && c <= 'z') return 2;
	return 0;
}

int main() {

	char c;
	c = 'Q';
	printf("\nResult when uppercase alphabet is passed: %d", isAlpha2(c));

	c = 'q';
	printf("\nResult when lowercase alphabet is passed: %d", isAlpha2(c));

	c = '+';
	printf("\nResult when non-alphabetic character is passed: %d", isAlpha2(c));

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}