#include "biblioteca.h"

// Última atualização: 29/08 às 11:05
// https://replit.com/@LucasGualtieriF/ConversorEntreBases

// clear && gcc conversorEntreBases.c -lm && ./a.out

#define PRECISAO 5

#define escolhaParaBase(esc) esc == 1 ? 2 : esc == 2 ? 8 : esc == 3 ? 10 : 16

string baseEntradaParaDec(int baseEntrada, string valor) {

	size_t valorLen		 = strlen(valor);
	int	   indexDoPonto	 = indexOf(valor, '.');
	int	   maiorPotencia = indexDoPonto != -1 ? indexDoPonto - 1 : valorLen - 1;

	double resultado = 0;

	for (int i = 0; i < valorLen; i++) {
		if (valor[i] == '.') continue;
		resultado += ctoi(valor[i]) * pow(baseEntrada, maiorPotencia--);
	}

	string valorConvertido = (string)malloc(STR_MAX_LEN * sizeof(char));
	sprintf(valorConvertido, "%.*lf", PRECISAO, resultado);
	sprintf(valorConvertido, "%g", atof(valorConvertido));

	// trimZeros(valorConvertido);

	return valorConvertido;
}

string decParaBaseSaida(string valor, int baseSaida) {

	if (baseSaida == 10) return valor;

	float valorDecimal = atof(valor);

	string str = (string)malloc(STR_MAX_LEN * sizeof(char));

	// Convertendo a parte inteira.
	for (int i = valorDecimal; i >= 1; i /= baseSaida) {
		char aux[2];
		sprintf(aux, "%c", itoa(i % baseSaida));
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
			char aux[2];

			parteFracionaria *= baseSaida;

			sprintf(aux, "%d", (int)parteFracionaria);
			strcat(str, aux);

			if (parteFracionaria - (int)parteFracionaria == 0) break;

			parteFracionaria -= (int)parteFracionaria;
		}
	}

	trimZeros(str);

	return str;
}

// Esse método lê do teclado o valor a ser convertido, repare que o valor é sempre uma string
// para que possamos lidar com bases hexadecimais e com números binários muito extensos.
// Esse método também garante que nenhum dos caracteres que formam a string sejam maiores ou iguais à base.
string getValor(int base) {

	string valor;
	bool   valido = true;

	do {
		if (!valido) printf("Valor inválido, tente novamente: ");
		valor	   = getstr();
		size_t len = strlen(valor);
		valido     = len > 0;

		for (int i = 0; valido && i < len; i++) {
			if (valor[i] == '.') continue;
			valido = ctoi(valor[i]) < base;
		}
		if (!valido) free(valor);

	} while (!valido);

	return valor;
}

void conversor(int baseEntrada, int baseSaida) {
	clrscreen();

	printf("Convertendo da base %d para base %d\n\n", baseEntrada, baseSaida);

	printf("Digite o valor a ser convertido: ");
	string valorOriginal   = getValor(baseEntrada);
	string valorConvertido = strdup(valorOriginal);

	if (baseEntrada != 10) {
		valorConvertido = baseEntradaParaDec(baseEntrada, valorOriginal);
		valorConvertido = decParaBaseSaida(valorConvertido, baseSaida);
	} else {
		valorConvertido = decParaBaseSaida(valorOriginal, baseSaida);
	}

	printf("\n%s convertido para base %d é: %s\n\n", valorOriginal, baseSaida, valorConvertido);

	free(valorOriginal);
	free(valorConvertido);
}

int lendoEscolha(int limiteSuperior) {
	char escolha;
	bool valido = true;

	do {
		if (!valido) printf("Valor inválido, tente novamente: ");
		escolha = ctoi(readChar()); // Não sei pq está char
	} while (!(valido = 0 <= escolha && escolha <= limiteSuperior));

	return escolha;
}

// Nesse método faço algumas comparações baseado na primeira escolha (Base de entrada)
// para que que o menu "responda" de acordo com a escolha do usuário.
int escolhaBaseFinal(int baseEntrada) {

	clrscreen();

	printf("Convertendo da base %d para base...\n\n", baseEntrada);

	int contador = 1;
	if (baseEntrada != 2) printf("%d - Binário\n", contador++);
	if (baseEntrada != 8) printf("%d - Octal\n", contador++);
	if (baseEntrada != 10) printf("%d - Decimal\n", contador++);
	if (baseEntrada != 16) printf("%d - Hexadecimal\n", contador++);
	puts("0 - Voltar para o menu anterior\n");
	printf("Escolha uma das opções acima: ");

	int escolha = lendoEscolha(3);

	if (escolha == 0) return 5;

	if (baseEntrada == 2) {
		escolha++;
	} else if (baseEntrada == 8 && escolha >= 2) {
		escolha++;
	} else if (baseEntrada == 10 && escolha >= 3) {
		escolha++;
	}

	conversor(baseEntrada, escolhaParaBase(escolha));

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

	int escolha = lendoEscolha(4);

	if (escolha != 0) {
		return escolhaBaseFinal(escolhaParaBase(escolha));
	} else return 0;

}

int decidirContinuar() {
	bool valido = true;
	char resposta;

	printf("Deseja converter mais um número? [S/N]: ");

	do {
		if (!valido) {
			printf("Valor inválido, tente novamente. [S/N]: ");
		}
		resposta = toUpper(readChar());
		valido = resposta == 'S' || resposta == 'N';
	} while (!valido);

	return resposta == 'S' ? true : false;
}

int main() {

	int	 escolha;
	bool continuar = true;

	while (continuar && (escolha = escolhaBaseOrigem())) {
		if (escolha != 5) continuar = decidirContinuar();
	}

	puts("\n------- | FIM DO PROGRAMA | -------\n");
	return 0;
}

// switch (lendoEscolha(4)) {
// case 1:
// 	return escolhaBaseFinal(2);
// 	break;
// case 2:
// 	return escolhaBaseFinal(8);
// 	break;
// case 3:
// 	return escolhaBaseFinal(10);
// 	break;
// case 4:
// 	return escolhaBaseFinal(16);
// 	break;
// default:
// 	return 0;
// }

// switch (escolha) {
// case 1:
// 	conversor(baseEntrada, 2);
// 	break;
// case 2:
// 	conversor(baseEntrada, 8);
// 	break;
// case 3:
// 	conversor(baseEntrada, 10);
// 	break;
// case 4:
// 	conversor(baseEntrada, 16);
// 	break;
// }