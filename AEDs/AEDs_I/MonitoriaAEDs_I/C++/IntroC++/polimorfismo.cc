#include <biblioteca_cpp.h>

int leInteiro() {
	int aux;
	cin >> aux; // Scanf
	return aux;
}

int leInteiro(string msg) {

	cout << msg;

	int aux;

	cin >> aux; // Scanf

	return aux;
}

int main() {

	int idade = leInteiro("Digite sua idade: ");
	cout << idade << endl; // Printf

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}