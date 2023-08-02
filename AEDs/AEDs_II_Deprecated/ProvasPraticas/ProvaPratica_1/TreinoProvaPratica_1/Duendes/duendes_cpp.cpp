#include <iostream>
#include <string>

using namespace std;

typedef struct Duende Duende;
struct Duende {
	string nome;
	int idade;
};

void printTeam(int third, int i, Duende* duendes) {
	// Third marca o começo do segundo terço do vetor de duendes
	// (Third * 2) marca o começo do terceiro terço do vetor de duendes
	cout << "Time " << i + 1; // Número do time
	cout << duendes[i].nome << " " << duendes[i].idade; // Líderes
	cout << duendes[i + third].nome << " " << duendes[i + third].idade; // Entregadores
	cout << duendes[i + third * 2].nome << " " << duendes[i + third * 2].idade; // Pilotos
	cout << "\n\n";
}

bool ordemAlfabetica(string nome1, string nome2) {
	if (nome1.length() > nome2.length()) {
		return true;
	} else if (nome1.length() < nome2.length()) {
		return false;
	} else {
		for (int i = 0; i < nome1.length(); i++) {
			if (tolower(nome1.at(i)) > tolower(nome2.at(i))) {
				return true;
			} else if (tolower(nome1.at(i)) < tolower(nome2.at(i))) {
				return false;
			}
		}
	}
	return 0; // Esse código é inalcançável, ele tá aqui pra não bugar
}

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
	cin >> N;

	Duende duendes[N];

	// Atribuindo os nomes e as idades aos Duendes
	for (int i = 0; i < N; i++) {
		getline(cin, duendes[i].nome, ' ');
		cin >> duendes[i].idade;
	}

	// Ordenando em ordem de idade
	sort(N, duendes);

	int third = N / 3; // Número de times a serem impressos
	for (int i = 0; i < third; i++) {
		printTeam(third, i, duendes);
	}

	return 0;
}