#include <biblioteca_c.h>

int QuantidadeDePalavras(char* frase) {
	int QuantidadeDePalavras = 1;

	for (int i = 0; i < strlen(frase); i++) {
		if (frase[i] == ' ') QuantidadeDePalavras++;
	}

	return QuantidadeDePalavras;
}

int printPalavra(char* string) {
	int i;
	for (i = 0; i < strlen(string) && string[i] != ' '; i++) {
		printf("%c", string[i]);
	}
	printf(" ");
	return i + 1;
}

int main() {

	char* frase1 = "Hoje esta um belo dia";
	char* frase2 = "Talvez chova amanha";

	int qtdPalavrasFrase1 = QuantidadeDePalavras(frase1);
	int qtdPalavrasFrase2 = QuantidadeDePalavras(frase2);

	int maiorFrase, menorFrase;

	if (qtdPalavrasFrase1 > qtdPalavrasFrase2) {
		maiorFrase = qtdPalavrasFrase1;
		menorFrase = qtdPalavrasFrase2;
	} else {
		maiorFrase = qtdPalavrasFrase2;
		menorFrase = qtdPalavrasFrase1;
	}

	int diferenca = maiorFrase - menorFrase;

	for (int i = 0; i < maiorFrase; i++) {
		frase1 += printPalavra(frase1);
		if (i < maiorFrase - diferenca) frase2 += printPalavra(frase2);
	}

	puts("\n\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}