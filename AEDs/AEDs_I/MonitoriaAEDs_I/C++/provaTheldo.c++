#include <biblioteca_cpp.h>

typedef struct Fracao* ref_Fracao;

class Fracao {
	int		   n, d;
	ref_Fracao link;

  public:
	Fracao() {
		this->n = 0;
		this->d = 1;
	}

	Fracao(int a, int b) {
		this->n = a;
		this->d = b;
	}

	Fracao(int a, int b, ref_Fracao proxima) {
		this->n	   = a;
		this->d	   = b;
		this->link = proxima;
	}

	int getN() {
		return n;
	}

	int getD() {
		return d;
	}

	ref_Fracao somar(ref_Fracao f) {
		float soma = n / d;
		soma += f->getN() / f->getD();
	}
	ref_Fracao simplificar() { }

	ref_Fracao proxima() {
		return link;
	}

	ref_Fracao maior(ref_Fracao f[], int n) {
		int maiorN = -200'000, maiorD = -200'000;

		int maiorIndice;

		for (int i = 0; i < 5; i++) {
			if (f[i]->getN() > maiorN) maiorN = f[i]->getN();
			if (f[i]->getD() > maiorD) maiorD = f[i]->getD();

			if (f[i]->getN() == maiorN && f[i]->getD() == maiorD) {
				maiorIndice = i;
			}
		}

		return f[maiorIndice];
	}

	ref_Fracao conectar(ref_Fracao f) {
		this->link = f;
	}

	ref_Fracao conectar() { }

	int mdc() { }

	int comparar(ref_Fracao f) {
		return 1;
	}

	void ler(string nome, int n, ref_Fracao f[]) {
		fstream file(nome, ios::in);

		int numerador, denominador;

		for (int i = n - 1; i >= 0; i++) {
			file >> numerador;
			file >> denominador;

			if (i > 0) {
				f[i] = new Fracao(numerador, denominador, f[i - 1]);
			} else {
				f[i] = new Fracao(numerador, denominador, nullptr);
			}
		}
	}

	string to_String() {
		string aux;

		aux += to_string(n);
		aux += '/';
		aux += to_string(d);

		return aux;
	}
};

int main() {

	ref_Fracao f1 = new Fracao(2, 3);
	ref_Fracao f2 = new Fracao(4, 9);
	ref_Fracao f3 = new Fracao();
	ref_Fracao f4[5];
	ref_Fracao f5 = new Fracao(1, 1, nullptr);

	f4[0]->ler("AO3.txt", 5, f4);

	for (int x = 0; x < 5; x++) {
		f5 = f5->conectar(f4[x]); // f5 = f5->conectar(f4[4]);
	}

	cout << "01. f1=" << f1->to_String() << "\n";
	cout << "02. f2=" << f2->to_String() << "\n";
	cout << "02. f3=" << f3->to_String() << "\n";

	f3 = f3->somar(f1);
	cout << "04. f3=" << f3->to_String() << "\n";
	f3 = f3->somar(f2);
	cout << "05. f3=" << f3->to_String() << "\n";

	cout << "06. MDC=" << f3->mdc() << "\n";
	cout << "07. f3=" << f3->simplificar()->to_String() << "\n";

	cout << "08. ? =" << f1->comparar(f2) << "\n";
	cout << "09. > =" << f4[0]->maior(f4, 5)->to_String() << "\n";

	while (f5) { // while (f5 != nullptr)
		cout << "10. f5=" << f5->to_String() << "\n";
		f5 = f5->proxima();
	}

	return 0;
}