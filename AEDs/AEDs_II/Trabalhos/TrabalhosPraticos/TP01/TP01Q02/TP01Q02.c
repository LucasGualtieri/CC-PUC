#include "../LibTP01.h"

// clear && gcc TP01Q02.c -o TP01Q02 && ./TP01Q02 < pub.in > result.txt

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
bool isPalindromo(String str) {

	int left = -1, right = strlen(str);

	bool result = true;

	while (left++ <= right--) {
		char cLeft = str[left], cRight = str[right];

		// Conferindo caracteres Alphanuméricos.
		if (isSingleChar(cLeft) || isSingleChar(cRight)) {
			if (cLeft != cRight) {
				left = right;
				result = false;
			}
		} else if (cLeft == SPECIAL_CHAR) {
			// Conferindo characteres especias (e.g., ç, á, à, ã, etc).
			if (str[left + 1] != cRight) {
				left = right;
				result = false;
			}
			left++, right--;
		}
	}

	return result;
}

int main() {

	char str[STR_MAX_LEN];

	while (!isEqual(readstr(str), "FIM")) {
		printf("%s\n", isPalindromo(str) ? "SIM" : "NAO");
	}

	return 0;
}