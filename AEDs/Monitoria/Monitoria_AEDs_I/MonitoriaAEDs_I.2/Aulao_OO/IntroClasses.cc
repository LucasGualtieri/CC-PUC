#include <iostream>

using namespace std;

// clear && g++ IntroClasses.cc && ./a.out

class Funcionario {
private: // Encapsulamento
	double salario;
	double saldo;
public: // Encapsulamento
	
	// Construtor da Classe
	Funcionario() {
		cout << "Funcionario criado" << endl;
		saldo = 0;
		salario = 0;
	}

	Funcionario(int saldo_par, int salario) {
		cout << "Funcionario criado com parametros" << endl;
		saldo = saldo_par;
		this->salario = salario;
	}

	~Funcionario() {
		cout << "Funcionario sendo destruído" << endl;
	}
	
	// Getters & Setters

	double getSaldo() { return saldo; }

	void setSalario(int horasTrab, int alunosAtendidos) {
		if (alunosAtendidos < 0) {
			cout << "Erro, número invalido" << endl;
		} else if (horasTrab > 20) {
			int bonus = 50;
			saldo += bonus;
		}
	}

	void RecebeSalario() {
		saldo += salario;
	}
};

int main() {

	if (true) {
		Funcionario monitor(15, 20);
	}

	cout << "TESTE" << endl;

	// monitor.setSalario(100000, 2);

	// for (int i = 0; i < 5; i++) {
	// 	monitor.RecebeSalario();
	// }

	// cout << monitor.getSaldo() << endl;

	return 0;
}