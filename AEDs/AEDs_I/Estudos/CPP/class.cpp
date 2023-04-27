#include <biblioteca_cpp.h>

class Pessoa {
private:
	int idade;
	string cpf;

public:
	void setIdade(int arg) {
		if (arg > 0) {
			idade = arg;
		} else {
			printf("Idade deve ser maior que 0");
		}
	}

	void setCPF(string arg) {
		cpf = arg;
	}

	int getIdade() {
		return idade;
	}
	string getCPF() {
		return MaskCPF(cpf);
	}
};

int main() {
	Pessoa Lucas;

	Lucas.setIdade(20);

	Lucas.setCPF("13605269605");

	cout << Lucas.getIdade() << endl;
	cout << Lucas.getCPF() << endl;

	printf("\n\n******* | FIM DO PROGRAMA | *******\n\n");
	return 0;
}