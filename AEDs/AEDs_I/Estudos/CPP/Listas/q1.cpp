#include "D:\Lucas\PUC\AED\workspace\C.CPP\Bibliotecas\biblioteca_cpp.h"
#include <iomanip>

class FormaGeometrica {
	string _cor;

public:
	void _SetCor(string cor) {
		_cor = cor;
	}
	string _GetCor() {
		return _cor;
	}

	float _getArea() { return 0; };
	float _GetPerim() { return 0; }
};

class Circulo : public FormaGeometrica {
	const double _pi = 3.14159265359;
	float _raio;

public:
	float _getArea() {
		return _pi * (_raio * _raio);
		// return pi * pow(raio, 2);
	}
	float _GetPerim() {
		return 2 * _pi * _raio;
	}
};

class Retangulo : public FormaGeometrica {
	int _altura, _largura;

public:
	void _SetAltura(int altura) {
		_altura = altura;
	}
	int _GetAltura() {
		return _altura;
	}
	void _SetLargura(int largura) {
		_largura = largura;
	}
	int _Getlargura() {
		return _largura;
	}

	float _getArea() {
		return _altura * _largura;
	}
	float _GetPerim() {
		return (2 * _altura) + (2 * _largura);
	}
};

class Carro {
	const int _eficiencia = 15;
	const float _consumoPorKm = 1.0 / _eficiencia;
	float _combustivel;
	int _quilometragem;

public:
	Carro() {
		_combustivel = 0;
		_quilometragem = 0;
	}
	Carro(short combustivel) {
		_SetCombustivel(combustivel);
		_quilometragem = 0;
	}

	void _SetCombustivel(short combustivel) {
		if (combustivel >= 0) {
			if (_combustivel < 50) {
				if (_combustivel + combustivel > 50) {
					cout << (50 - _combustivel) << " litros adicionados." << endl;
					cout << "Tanque cheio! Tanque: 50/50 litros." << endl;
					_combustivel = 50;
				} else {
					_combustivel += combustivel;
					cout << combustivel << " litros adicionados. Tanque: " << _combustivel << "/50" << endl;
				}
			} else {
				cout << "0 litros adicionados" << endl;
				cout << "Tanque cheio! Tanque: 50/50 litros." << endl;
			}
		} else {
			cout << "Valor inválido de combustível" << endl;
		}
	}

	float _GetCombustivel() { return _combustivel; }

	int _GetQuilometragem() { return _quilometragem; }

	void _Mover(int distKm) {

		if (distKm * _consumoPorKm > _combustivel) {
			_quilometragem += distKm;
			cout << "Carro deslocado " << _combustivel * _eficiencia << " km. Tanque: 0/50" << endl;
			_combustivel = 0;
		} else {
			_combustivel -= distKm * _consumoPorKm;
			_quilometragem += distKm;
			cout << "Carro deslocado " << distKm << " km. Tanque: " << _combustivel << "/50" << endl;
		}
	}
};

int main() {
	SetConsoleOutputCP(65001);

	cout << fixed;
	cout << setprecision(2);

	Carro c1, c2;
	c1._SetCombustivel(20);
	c2._SetCombustivel(30);

	c1._Mover(200);
	c2._Mover(400);

	// cout << c1._GetCombustivel() << endl;
	// cout << c1._GetQuilometragem() << endl;

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}