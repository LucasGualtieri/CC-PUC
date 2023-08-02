#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Personagem {
	char nome[40];
	int altura;
	double peso;
	char corDoCabelo[40];
	char corDaPele[40];
	char corDosOlhos[40];
	char anoNascimento[40];
	char genero[40];
	char homeworld[40];
} Personagem;

void leituraAtributo(char atributo[], char descricaoPersonagem[], int index) {
	int i = 0;

	while (descricaoPersonagem[index] != '\'') {
		atributo[i] = descricaoPersonagem[index];

		i++;
		index++;
	}

	atributo[i] = '\0';
}

bool testaFim(char palavra[]) {
	bool teste = false;

	if (palavra[0] == 'F' && palavra[1] == 'I' && palavra[2] == 'M') {
		teste = true;
	}

	return teste;
}

Personagem montaPersonagem(char caminhoArquivo[]) {
	FILE* leitura = fopen(caminhoArquivo, "r");

	char descricaoPersonagem[1000];

	fscanf(leitura, " %[^\n]s", descricaoPersonagem);

	Personagem personagem;

	int contador = 0;

	for (int i = 0; i < strlen(descricaoPersonagem); i++) {
		if (descricaoPersonagem[i] == ':') {
			char atributo[50];
			contador++;

			switch (contador) {
			case 1:
				leituraAtributo(atributo, descricaoPersonagem, i + 3);
				strcpy(personagem.nome, atributo);
				break;
			case 2:
				leituraAtributo(atributo, descricaoPersonagem, i + 3);
				personagem.altura = atoi(atributo);
				break;
			case 3:
				leituraAtributo(atributo, descricaoPersonagem, i + 3);
				for (int i = 0; i < strlen(atributo); i++) {
					if (atributo[i] == ',') {
						atributo[i] = atributo[i - 1];
						atributo[i - 1] = '0';
					}
				}
				personagem.peso = atof(atributo);
				break;
			case 4:
				leituraAtributo(atributo, descricaoPersonagem, i + 3);
				strcpy(personagem.corDoCabelo, atributo);
				break;
			case 5:
				leituraAtributo(atributo, descricaoPersonagem, i + 3);
				strcpy(personagem.corDaPele, atributo);
				break;
			case 6:
				leituraAtributo(atributo, descricaoPersonagem, i + 3);
				strcpy(personagem.corDosOlhos, atributo);
				break;
			case 7:
				leituraAtributo(atributo, descricaoPersonagem, i + 3);
				strcpy(personagem.anoNascimento, atributo);
				break;
			case 8:
				leituraAtributo(atributo, descricaoPersonagem, i + 3);
				strcpy(personagem.genero, atributo);
				break;
			case 9:
				leituraAtributo(atributo, descricaoPersonagem, i + 3);
				strcpy(personagem.homeworld, atributo);

				i = strlen(descricaoPersonagem);
				break;
			default:
				break;
			}
		}
	}

	fclose(leitura);

	return personagem;
}

void printLog(time_t inicio, int numeroComparacoes) {
	float tempo;
	time_t final = time(NULL);

	tempo = difftime(final, inicio);

	FILE* log = fopen("matricula_bin.txt", "w");

	fprintf(log, "Matricula: 792421\tTempo Execucao: %fs\tNumero Comparacoes: %d\n", tempo, numeroComparacoes);

	fclose(log);
}

int main(void) {
	char caminhoArquivo[100], nomePersonagem[100];
	int contadorTamanho = 0, numeroComparacoes = 0;
	time_t inicio = time(NULL);
	Personagem listaPersonagem[100];

	scanf(" %[^\n]s", caminhoArquivo);
	getchar();

	while (testaFim(caminhoArquivo) == false) {
		listaPersonagem[contadorTamanho] = montaPersonagem(caminhoArquivo);
		contadorTamanho += 1;

		scanf(" %[^\n]s", caminhoArquivo);
		getchar();
	}

	scanf(" %[^\n]s", nomePersonagem);
	getchar();

	while (testaFim(nomePersonagem) == false) {
		bool comparaNomes = false;
		int esquerda = 0, direita = contadorTamanho - 1, meio;

		while (esquerda <= direita) {
			numeroComparacoes++;
			meio = (esquerda + direita) / 2;

			if ((strcmp(nomePersonagem, listaPersonagem[meio].nome)) == 0) {
				comparaNomes = true;
				numeroComparacoes++;
				esquerda = contadorTamanho;
			} else if ((strcmp(nomePersonagem, listaPersonagem[meio].nome)) < 0) {
				numeroComparacoes++;
				direita = meio - 1;
			} else {
				esquerda = meio + 1;
			}
		}

		if (comparaNomes == true)
			printf("SIM\n");
		else
			printf("NAO\n");

		scanf(" %[^\n]s", nomePersonagem);
		getchar();
	}

	numeroComparacoes++;

	printLog(inicio, numeroComparacoes);

	return 0;
}