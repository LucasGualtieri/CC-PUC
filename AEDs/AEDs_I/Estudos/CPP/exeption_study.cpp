#include <biblioteca_cpp.h>
#include <exception>

class ExcecaoCustomizada : public exception {
	string _msg;

public:
	ExcecaoCustomizada(string msg) {
		_msg = msg;
	}
	virtual string what() { // Sobrecarga de um metodo de exception
		return _msg;
	}
};

int half(int number) {
	if (number == 0) throw "Valor não pode ser igual a 0";
	return 2 / number;
}

int divisao(int nominador, int denominador) {
	if (denominador == 0) throw ExcecaoCustomizada("Divisão por 0!");
	return nominador / denominador;
}

int main() {
	SetConsoleOutputCP(65001);

	try {
		cout << half(0) << endl;
	} catch (const char* erro) {
		cout << "Erro: " << erro << endl;
	} catch (...) { // Não entendo bem essa parte. Parte opcional
		cout << "Erro inesperado ocorreu!" << endl;
	}

	try {
		cout << divisao(2, 0) << endl;
	} catch (ExcecaoCustomizada erro) {
		cout << "Erro: " << erro.what() << endl;
	}
	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}