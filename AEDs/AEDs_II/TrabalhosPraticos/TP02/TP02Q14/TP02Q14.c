#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definição do registro do personagem
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

// Função para retornar o resto da divisão com double
double fmod(double x, double y) {
	return x - (int)(x / y) * y;
}

// Capturar o atributo entre aspas simples
void leituraAtributo(char atributo[], char descricaoPersonagem[], int index) {
	int i = 0;

	while (descricaoPersonagem[index] != '\'') {
		atributo[i] = descricaoPersonagem[index];

		i++;
		index++;
	}

	atributo[i] = '\0';
}

// Função para testar o fim do arquivo
bool testaFim(char palavra[]) {
	bool teste = false;

	if (palavra[0] == 'F' && palavra[1] == 'I' && palavra[2] == 'M') {
		teste = true;
	}

	return teste;
}

// Função para estruturar o personagem
Personagem montaPersonagem(char caminhoArquivo[]) {
	FILE* leitura = fopen(caminhoArquivo, "r");

	char descricaoPersonagem[1000];

	fscanf(leitura, " %[^\n]s", descricaoPersonagem);

	Personagem personagem; // Cria a variável struct

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

				i = strlen(descricaoPersonagem); // Encerra os ciclos de repetição desnecessários
				break;
			default:
				break;
			}
		}
	}

	fclose(leitura);

	return personagem;
}

// Função para trocar os elementos de lugar
void trocaElementos(Personagem listaPersonagem[], int posicaoA, int posicaoB, int* ptrMov) {
	Personagem personagemTemporario = listaPersonagem[posicaoA];
	listaPersonagem[posicaoA] = listaPersonagem[posicaoB];
	listaPersonagem[posicaoB] = personagemTemporario;

	*ptrMov += 3;
}

// Função para Ordenação por Quicksort
void ordenaPorQuicksort(Personagem listaPersonagem[], int esq, int dir, int* ptrComp, int* ptrMov) {
	int i = esq, j = dir;
	Personagem pivo = listaPersonagem[(esq + dir) / 2];
	while (i <= j) {
		while (strcmp(listaPersonagem[i].corDoCabelo, pivo.corDoCabelo) < 0) {
			i++;

			*ptrComp += 1;
		}

		while (strcmp(listaPersonagem[j].corDoCabelo, pivo.corDoCabelo) > 0) {
			j--;

			*ptrComp += 1;
		}

		if (i <= j) {
			trocaElementos(listaPersonagem, i, j, ptrMov);
			i++;
			j--;

			*ptrComp += 1;
		}

		*ptrComp += 1;
	}

	*ptrComp += 1; // Incremento para quando não entrar na repetição

	if (esq < j) {
		*ptrComp += 1;

		ordenaPorQuicksort(listaPersonagem, esq, j, ptrComp, ptrMov);
	}
	if (i < dir) {
		*ptrComp += 1;

		ordenaPorQuicksort(listaPersonagem, i, dir, ptrComp, ptrMov);
	}
}

// Função para Ordenação por Inserção
void ordenaPorInsercao(Personagem listaPersonagem[], int tamanhoVetor, int* ptrComp, int* ptrMov) {
	for (int i = 1; i < tamanhoVetor; i += 1) {
		Personagem personagemTemporario = listaPersonagem[i];
		int j = i - 1;
		while ((j >= 0) && ((strcmp(listaPersonagem[j].corDoCabelo, personagemTemporario.corDoCabelo) == 0) && (strcmp(listaPersonagem[j].nome, personagemTemporario.nome) > 0))) {
			*ptrComp += 3;
			*ptrMov += 1;
			listaPersonagem[j + 1] = listaPersonagem[j];
			j -= 1;
		}

		*ptrComp += 1; // Essa pode variar mais do que 1 [???]
		*ptrMov += 1;

		listaPersonagem[j + 1] = personagemTemporario;
	}

	*ptrComp += 1; // Incremento pela comparação ao sair da repetição
}

// Imprimir os resultados
void imprimirAtributos(Personagem listaPersonagens[], int tamanhoTotal) {
	for (int i = 0; i < tamanhoTotal; i++) {
		printf(" ## %s", listaPersonagens[i].nome);
		printf(" ## %d", listaPersonagens[i].altura);
		if (fmod(listaPersonagens[i].peso, 1) == 0)
			printf(" ## %.0lf", listaPersonagens[i].peso);
		else
			printf(" ## %.1lf", listaPersonagens[i].peso);
		printf(" ## %s", listaPersonagens[i].corDoCabelo);
		printf(" ## %s", listaPersonagens[i].corDaPele);
		printf(" ## %s", listaPersonagens[i].corDosOlhos);
		printf(" ## %s", listaPersonagens[i].anoNascimento);
		printf(" ## %s", listaPersonagens[i].genero);
		printf(" ## %s", listaPersonagens[i].homeworld);
		printf(" ## \n");
	}
}

// Função para criar arquivo de log
void criarLog(time_t inicio, int numeroComparacoes, int numeroMovimentacoes) {
	float tempo;
	time_t final = time(NULL); // Marcar o final da execução

	tempo = difftime(final, inicio);

	FILE* log = fopen("matricula_quicksort.txt", "w");

	fprintf(log, "Matricula: 790052\tNumero Comparacoes: %d\tNumero Movimentacoes: %d\tTempo Execucao: %fs\n", numeroComparacoes, numeroMovimentacoes, tempo);

	fclose(log);
}

int main(void) {
	char caminhoArquivo[100], nomePersonagem[100];
	int contadorTamanho = 0, numeroComparacoes = 0, numeroMovimentacoes = 0;
	int *ptrComp = &numeroComparacoes, *ptrMov = &numeroMovimentacoes;
	time_t inicio = time(NULL); // Marcar o início da execução
	Personagem listaPersonagem[100];

	scanf(" %[^\n]s", caminhoArquivo);
	getchar();

	// Testa o fim do arquivo
	while (testaFim(caminhoArquivo) == false) {
		listaPersonagem[contadorTamanho] = montaPersonagem(caminhoArquivo);
		contadorTamanho += 1;

		scanf(" %[^\n]s", caminhoArquivo);
		getchar();
	}

	ordenaPorQuicksort(listaPersonagem, 0, (contadorTamanho - 1), ptrComp, ptrMov); // Ordena peso por Quicksort, mas não troca os nomes, por ser instável

	ordenaPorInsercao(listaPersonagem, contadorTamanho, ptrComp, ptrMov); // Ordena cor do cabelo e nome por Inserção, por ser estável

	imprimirAtributos(listaPersonagem, contadorTamanho); // Imprimir os resultados

	criarLog(inicio, numeroComparacoes, numeroMovimentacoes);

	return 0;
}