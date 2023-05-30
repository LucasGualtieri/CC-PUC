#include <biblioteca_c.h>

int QuantidadeDePalavras(char* frase) {
	int QuantidadeDePalavras = 1;

	for (int i = 0; i < strlen(frase); i++) {
		if (frase[i] == ' ') QuantidadeDePalavras++;
	}

	return QuantidadeDePalavras;
}

int main() {

	char* frase1 = "Hoje esta um belo dia";
	char* frase2 = "Talvez chova amanha";

	char** frase1Array = split(frase1, " ", 0);
	char** frase2Array = split(frase2, " ", 0);

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
		printf("%s ", frase1Array[i]);
		if (i < maiorFrase - diferenca) printf("%s ", frase2Array[i]);
	}

	puts("\n\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}