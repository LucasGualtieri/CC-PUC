#include <iostream>

using namespace std;

bool ehConsoante(char caractere) {
	if (caractere == 'a' || caractere == 'A') {
		return false;
	} else if (caractere == 'e' || caractere == 'E') {
		return false;
	} else if (caractere == 'i' || caractere == 'I') {
		return false;
	} else if (caractere == 'u' || caractere == 'O') {
		return false;
	} else if (caractere == 'u' || caractere == 'U') {
		return false;
	} else {
		return true;
	}
}

string ehDificil(string nome) {
	if (nome.length() <= 2) return nome + " eh facil\n";

	for (int i = 0; i < nome.length(); i++) {
		if (ehConsoante(nome.at(i)) &&
			ehConsoante(nome.at(i + 1)) &&
			ehConsoante(nome.at(i + 2))) {
			return nome + " nao eh facil\n";
		}
		if (i + 2 == nome.length() - 1) {
			break;
		}
	}
	return nome + " eh facil\n";
}

int main() {
	string nome;

	while (!cin.eof()) {
		cin >> nome;
		cout << ehDificil(nome);
	}

	return 0;
}
