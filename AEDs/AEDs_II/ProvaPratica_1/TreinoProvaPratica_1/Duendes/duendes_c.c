#include "../../../Bibliotecas/biblioteca_c.h"

// clear && gcc duendes_c.c -o duendes_c && ./duendes_c < pub.in > out2.txt

typedef struct Duende Duende;
struct Duende {
	String nome;
	int idade;
};

void printTeam(Duende* duendes, int third, int i) {
	int numeroDoTime = i + 1;
	printf("Time %d\n", numeroDoTime);
	printf("%s %d\n", duendes[i].nome, duendes[i].idade);
	printf("%s %d\n", duendes[i + third].nome, duendes[i + third].idade);
	printf("%s %d", duendes[i + third * 2].nome, duendes[i + third * 2].idade);
}

bool ordemAlfabetica(String nome1, String nome2);

void sort(int arrayLength, Duende* duendes) {

	for (int i = 0; i < (arrayLength - 1); i++) {
		int maior = i;
		for (int j = (i + 1); j < arrayLength; j++) {
			if (duendes[maior].idade == duendes[j].idade) {
				if (ordemAlfabetica(duendes[maior].nome, duendes[j].nome)) {
					maior = j;
				}
			} else if (duendes[maior].idade < duendes[j].idade) {
				maior = j;
			}
		}
		Duende swap = duendes[maior];
		duendes[maior] = duendes[i];
		duendes[i] = swap;
	}
}

int main() {

	int N; // Quantidade de Duendes na lista
	scanf("%d", &N);

	// Duende* duendes = (Duende*)malloc(N * sizeof(Duende));
	Duende duendes[N];

	// Atribuindo os nomes e as idades aos Duendes
	for (int i = 0; i < N; i++) {
		String* nomeIdade = split(getstr(), " ");
		duendes[i].nome = nomeIdade[0];
		duendes[i].idade = atoi(nomeIdade[1]);
	}

	// Ordenando em ordem de idade
	sort(N, duendes);

	// Printando os times
	int third = N / 3;
	for (int i = 0; i < third; i++) {
		printTeam(duendes, third, i);
		printf("%s", i < third - 1 ? endl : "");
	}

	return 0;
}

bool ordemAlfabetica(String nome1, String nome2) {

	int nome1Length = strlen(nome1);
	int nome2Length = strlen(nome2);

	if (nome1Length > nome2Length) {
		for (int i = 0; i < nome2Length; i++) {
			if (toLower(nome1[0]) > toLower(nome2[0])) {
				return true;
			} else if (toLower(nome1[0]) < toLower(nome2[0])) {
				return false;
			}
		}
	} else if (nome1Length < nome2Length) {
		for (int i = 0; i < nome1Length; i++) {
			if (toLower(nome1[0]) > toLower(nome2[0])) {
				return true;
			} else if (toLower(nome1[0]) < toLower(nome2[0])) {
				return false;
			}
		}
	}

	return 0;
}