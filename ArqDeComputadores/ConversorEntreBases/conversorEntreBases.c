#include "biblioteca.h"

void conversor(int baseOrigem, int baseFinal) {
	clrscreen();

	printf("Convertendo da base %d para base %d\n", baseOrigem, baseFinal);

	printf("Digite o valor a ser convertido: ");
	string valorOriginal   = getstr();
	string valorConvertido = strdup(valorOriginal);

	// switch (baseOrigem) {
	// case 2:
	// 	valorConvertido = baseXParaDec(2, valorOriginal);
	// 	break;
	// case 8:
	// 	valorConvertido = baseXParaDec(8, valorOriginal);
	// 	break;
	// case 10:
	// 	if (baseFinal == 16) {
	// 		valorConvertido = decParaHex(valorOriginal);
	// 	} else {
	// 		valorConvertido = decParaBaseX(valorOriginal, baseFinal);
	// 	}
	// 	break;
	// case 16:
	// 	valorConvertido = hexParaDec(valorOriginal);
	// 	break;
	// }

	clrscreen();

	// if (baseFinal != 10 && baseOrigem != 10) valorConvertido = DecParaBaseX(valorConvertido, baseFinal);
	// printf("O valor %s(%d) convertido para base %d é: %s\n", valorOriginal, baseOrigem, baseFinal, valorConvertido);

	free(valorOriginal);
	free(valorConvertido);
}

int ReadingChoice() {
	int	 choice;
	bool invalid = false;

	do {
		if (invalid) {
			printf("Valor inválido, tente novamente: ");
		}
		scanf("%d", &choice);
		flush();
	} while ((invalid = choice < 0 || 4 < choice));

	return choice;
}

int escolhaBaseFinal(int baseOrigem) {

	clrscreen();

	printf("Convertendo da base %d para -> ...\n", baseOrigem);

	puts("Escolha a base final:");
	puts("0 - Sair do programa");
	puts("1 - Binário");
	puts("2 - Octal");
	puts("3 - Decimal");
	puts("4 - Hexadecimal");
	printf("Escolha uma das opções acima: ");

	int escolha = ReadingChoice();

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

	puts("Escolha a base de conversão:");
	puts("0 - Sair do programa");
	puts("1 - Binário");
	puts("2 - Octal");
	puts("3 - Decimal");
	puts("4 - Hexadecimal");
	printf("Escolha uma das opções acima: ");

	switch (ReadingChoice()) {
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

int main() {

	while (escolhaBaseOrigem()) continue;

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}