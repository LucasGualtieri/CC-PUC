#include "../../Lib.h"

// clear && gcc TP01Q11.c -o TP01Q11 && ./TP01Q11 < pub.in > result.txt

/*
	"a�a"					- SIM
	"a��a"					- SIM
	"a�a�a"					- SIM
	"a´b´a"					- SIM
	"a´b`a"					- NAO
	"aça"					- SIM
	"açça"					- SIM
	"açaça"					- SIM
	"açéa"					- NAO
	"açéaaéça"				- SIM
	"açéaéça"				- SIM
	"marrocos - socorram" 	- SIM
*/

#define STR_MAX_LEN 400
#define SPECIAL_CHAR -61 // characteres especias (e.g., ç, á, à, ã, etc)
#define isSingleChar(c) (c > 0)

/*
	- Retorna true ou false se a palavra é ou não um palíndromo.
	- Faço isso testando as extremidades da palavra até chegar no meio da palavra.
	- Em C, os caracteres são representados com apenas 1 byte,
	ao contrário de Java, que utiliza 2 bytes. Isso faz com
	que caracteres especiais (por exemplo, ç, á, à, ã, etc.)
	sejam representados por DOIS SUBCARACTERES. Sendo assim,
	certas manipulações especiais são necessárias para determinar
	se a palavra é ou não um palíndromo.
*/
bool isPalindromoRec(String palavra, int left, int right) {
	char cLeft = palavra[left], cRight = palavra[right];
	if (isSingleChar(cLeft) || isSingleChar(cRight)) {
		if (cLeft != cRight) return false;	
	} else if (cLeft == SPECIAL_CHAR) {
		if (palavra[left + 1] != cRight) return false;
		left++, right--;
	}
	return (left > right) ? true : isPalindromoRec(palavra, left + 1, right - 1);
}

bool isPalindromo(String palavra) {
	return isPalindromoRec(palavra, 0, strlen(palavra) - 1);
}

int main() {

	char str[STR_MAX_LEN];

	while (!isEqual(readstr(str), "FIM")) {
		printf("%s\n", isPalindromo(str) ? "SIM" : "NAO");
	}

	return 0;
}
