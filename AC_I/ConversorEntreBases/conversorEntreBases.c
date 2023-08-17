#include "biblioteca.h"

// Última atualização: 16/08 às 22:35
// https://replit.com/@LucasGualtieriF/ConversorEntreBases

#define PRECISAO 5

string baseXParaDec(int baseX, string valor) {

	size_t valorLen		 = strlen(valor);
	int	   indexDoPonto	 = indexOf(valor, '.');
	int	   maiorPotencia = indexDoPonto != -1 ? indexDoPonto - 1 : valorLen - 1;

	float resultado = 0;

	for (int i = 0; i < valorLen; i++) {
		if (valor[i] == '.') continue;
		resultado += ctoi(valor[i]) * pow(baseX, maiorPotencia--);
	}

	string valorConvertido = (string)malloc(STR_MAX_LEN * sizeof(char));
	sprintf(valorConvertido, "%.*f", PRECISAO, resultado);

	trim(valorConvertido);

	return valorConvertido;
}

string decParaBaseX(string valor, int baseX) {

	if (baseX == 10) return valor;

	float valorDecimal = atof(valor);

	string str = (string)malloc(STR_MAX_LEN * sizeof(char));

	// Convertendo a parte inteira.
	for (int i = valorDecimal; i >= 1; i /= baseX) {
		char aux[2];
		sprintf(aux, "%c", itoa(i % baseX));
		strcat(str, aux);
	}

	if ((int)valorDecimal == 0) {
		strcat(str, "0"); // Para evitar resultados como ".5"
	} else {
		// Invertendo a string.
		size_t len = strlen(str);
		for (int i = 0; i < len / 2; i++) {
			char aux		 = str[i];
			str[i]			 = str[len - 1 - i];
			str[len - 1 - i] = aux;
		}
	}

	// Convertendo a parte fracionária.

	int	  parteInteira	   = (int)valorDecimal;
	float parteFracionaria = valorDecimal - parteInteira;

	if (parteFracionaria > 0) {
		strcat(str, ".");
		for (int i = 0; i < PRECISAO; i++) {
			char aux[PRECISAO];

			parteFracionaria *= baseX;

			if (parteFracionaria - (int)parteFracionaria == 0) i = PRECISAO;

			sprintf(aux, "%d", (int)parteFracionaria);
			strcat(str, aux);

			parteFracionaria -= (int)parteFracionaria;
		}
	}

	return str;
}

string getValor(int base) {

	string valor;
	bool   invalido = false;

	do {
		if (invalido) printf("Valor inválido, tente novamente: ");
		valor	   = getstr();
		size_t len = strlen(valor);
		invalido   = len == 0;

		for (int i = 0; !invalido && i < len; i++) {
			if (valor[i] == '.') continue;
			invalido = ctoi(valor[i]) >= base;
		}
		if (invalido) free(valor);

	} while (invalido);

	return valor;
}

void conversor(int baseOrigem, int baseFinal) {
	clrscreen();

	printf("Convertendo da base %d para base %d\n\n", baseOrigem, baseFinal);

	printf("Digite o valor a ser convertido: ");
	string valorOriginal   = getValor(baseOrigem);
	string valorConvertido = strdup(valorOriginal);

	if (baseOrigem != 10) {
		valorConvertido = baseXParaDec(baseOrigem, valorOriginal);
		valorConvertido = decParaBaseX(valorConvertido, baseFinal);
	} else {
		valorConvertido = decParaBaseX(valorOriginal, baseFinal);
	}

	printf("\n%s convertido para base %d é: %s\n\n", valorOriginal, baseFinal, valorConvertido);

	free(valorOriginal);
	free(valorConvertido);
}

int lendoEscolha(int limiteSuperior) {
	int	 escolha;
	bool invalido = false;

	do {
		if (invalido) printf("Valor inválido, tente novamente: ");
		scanf("%d", &escolha);
		flush();
	} while ((invalido = escolha < 0 || limiteSuperior < escolha));

	return escolha;
}

int escolhaBaseFinal(int baseOrigem) {

	clrscreen();

	printf("Convertendo da base %d para base...\n\n", baseOrigem);

	int contador = 1;
	if (baseOrigem != 2) printf("%d - Binário\n", contador++);
	if (baseOrigem != 8) printf("%d - Octal\n", contador++);
	if (baseOrigem != 10) printf("%d - Decimal\n", contador++);
	if (baseOrigem != 16) printf("%d - Hexadecimal\n", contador++);
	puts("0 - Voltar para o menu anterior\n");
	printf("Escolha uma das opções acima: ");

	int escolha = lendoEscolha(3);

	if (escolha == 0) return 5;

	if (baseOrigem == 2) {
		escolha++;
	} else if (baseOrigem == 8 && escolha >= 2) {
		escolha++;
	} else if (baseOrigem == 10 && escolha >= 3) {
		escolha++;
	}

	switch (escolha) {
	case 1:
		conversor(baseOrigem, 2);
		break;
	case 2:
		conversor(baseOrigem, 8);
		break;
	case 3:
		conversor(baseOrigem, 10);
		break;
	case 4:
		conversor(baseOrigem, 16);
		break;
	}

	return escolha;
}

int escolhaBaseOrigem() {

	clrscreen();

	puts("Escolha a base de conversão:\n");
	puts("1 - Binário");
	puts("2 - Octal");
	puts("3 - Decimal");
	puts("4 - Hexadecimal");
	puts("0 - Sair do programa\n");
	printf("Escolha uma das opções acima: ");

	switch (lendoEscolha(4)) {
	case 1:
		return escolhaBaseFinal(2);
		break;
	case 2:
		return escolhaBaseFinal(8);
		break;
	case 3:
		return escolhaBaseFinal(10);
		break;
	case 4:
		return escolhaBaseFinal(16);
		break;
	default:
		return 0;
	}
}

int continuarExecucao() {
	bool invalido = false;
	char resposta;

	printf("Deseja converter mais um número? [S/N]: ");

	do {
		if (invalido) {
			printf("Valor inválido, tente novamente. [S/N]: ");
		}
		scanf("%c", &resposta);
		resposta = toUpper(resposta);
		flush();
	} while ((invalido = resposta != 'S' && resposta != 'N'));

	return resposta == 'S' ? true : false;
}

int main() {

	int	 escolha;
	bool continuar = true;

	while (continuar && (escolha = escolhaBaseOrigem())) {
		if (escolha != 5) continuar = continuarExecucao();
	}

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}
