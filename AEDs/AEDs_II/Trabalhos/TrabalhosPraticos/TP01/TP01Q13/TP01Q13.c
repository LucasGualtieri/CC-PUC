#include "../LibTP01.h"
#include <time.h>
#include <math.h>

// clear && gcc TP01Q13.c -o TP01Q13 && ./TP01Q13 < pub.in > result.txt

char randomChar() {
	return (char)('a' + (abs(rand()) % 26));
}

/*
	- Escolhe aleatóriamente dois caracteres.
	- Recebe uma string e modifica todas as
	ocorrências do primeiro caractere pelo
	segundo caractere gerado.
*/
String aleatorio(String str) {
	
	char baseChar = randomChar();
	char newChar = randomChar();
	
	int len = strlen(str);
	
	for (int i = 0; i < len; i++) {
		char c = str[i];
		str[i] = c == baseChar ? newChar : c;
	}

	return str;
}

int main() {

	char str[STR_MAX_LEN];

	srand(4);
	while (!isEqual(readstr(str), "FIM")) {
		printf("%s\n", aleatorio(str));
	}

	return 0;
}
