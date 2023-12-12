class funcionario {
protected:
	int salario, saldo;
public:
	void receberSalario();
};

class Gerente : public funcionario {
	void receberSalario(int bonus) {
		saldo += salario + bonus;
	}
};