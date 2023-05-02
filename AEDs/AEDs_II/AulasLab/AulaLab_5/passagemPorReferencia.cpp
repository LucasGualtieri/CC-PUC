#include <iostream>

using namespace std;

void trocarNome(string nome) {
	nome = "Gualtieri";
	cout << nome << endl;
}

void trocarNomeRef(string& nome) {
	nome = "Gualtieri";
	cout << nome << endl;
}

int main() {

	string nome = "Lucas";
	cout << nome << endl;

	trocarNome(nome);

	cout << nome << endl;

	trocarNomeRef(nome);
	cout << nome << endl;

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}