#include "../../Lib.h"

// clear && gcc TP01Q09.c -o TP01Q09 && ./TP01Q09 < pub.in > result.txt

/*
	- Recebe o cursor virtual e o arquivo.
	- Volta com o cursor até o fim da linha de cima
	depois avança uma posição. Em outras palavras
	nos permite voltando no arquivo, indo sempre para
	o começo da linha de cima.
*/
void cursorReset(int* virtualCursor, FILE* file) {
	fseek(file, --(*virtualCursor), SEEK_SET);
	while (*virtualCursor >= 0 && fgetc(file) != '\n') {
		fseek(file, --(*virtualCursor), SEEK_SET);
	}
	fseek(file, *virtualCursor + 1, SEEK_SET);
}

int main() {

	/*
		- Inicialmente abro o arquivo para escrita.
		- Depois leio a quantidade de números a serem lidos.
		- Por último os escrevo normalmente no arquivo.
	*/

	String filePath = "TP01Q09_LucasGualtieri.txt";
	FILE* file = fopen(filePath, "w");

	int numberOfRealNumbers = getInt(stdin);

	for (int i = 0; i < numberOfRealNumbers; i++) {
		fprintf(file, "%g",  getFloat(stdin));
		if (i < numberOfRealNumbers - 1) fprintf(file, "\n");
	}

	fclose(file);

	// --------------------------------------------------------

	/*
		- Agora abro o arquivo para leitura.
		- Levo o curso para o começo do último número.
		- Por último leio os números de trás para frente
		voltando sempre sizeof(float) para ler o número de trás.
	*/

	file = fopen(filePath, "r");
	fseek(file, 0, SEEK_END);
	int virtualCursor = ftell(file);

	for (int i = 0; i < numberOfRealNumbers; i++) {
		cursorReset(&virtualCursor, file);
		printf("%g",  getFloat(file));
		if (i < numberOfRealNumbers - 1) puts("");
	}

	fclose(file);

	return 0;
}