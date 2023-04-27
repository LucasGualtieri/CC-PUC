#include <biblioteca_cpp.h>

typedef unsigned long long big_int;

class InteiroGigante {
	// int* _bigInt = (int*)calloc(40, sizeof(int)); Isso funciona, não precisa de construtor! Pra que construtor?
	int _bigInt[40];
	int _bigIntUsedLength = 0; // Isso funciona, não precisa de construtor! Pra que construtor?
	// Talvez eu poderia usar 2 big_int pra fazer um função que de fato faz subtrações e somas.
	// big_int gigaton = 12'312'313'123'123'111'111; // 20 digitos.

public:
	void _leiaInteiroGigante(string bigIntStr) {
		for (int i = 0; i < bigIntStr.length(); i++) {
			if (bigIntStr.at(i) >= '0' && bigIntStr.at(i) <= '9') {
				_bigInt[_bigIntUsedLength++] = bigIntStr.at(i) - '0'; // Pós incremento
			}
		}
	}

	void _imprimeInteiroGigante() {
		for (int i = 0; i < _bigIntUsedLength; i++) {
			cout << _bigInt[i];
		}
		cout << endl;
	}

	void _adicioneInteiroGigante(string str) {
		if (str.length() + _bigIntUsedLength < 40) {
			for (int i = 0; i < str.length(); i++) {
				_bigInt[_bigIntUsedLength++] = str.at(i) - '0'; // Pós incremento
			}
		}
	}

	void _subtraiaInteiroGigante(int arg) {
		for (int i = 0; i < arg; i++) {
			_bigInt[_bigIntUsedLength--] = 0; // Pós decremento
		}
	}

	bool _isEqual(InteiroGigante comparing) {
		if (_bigIntUsedLength == comparing._getBigIntLength()) {
			for (int i = 0; i < _bigIntUsedLength; i++) {
				if (_bigInt[i] != comparing._getBigInt()[i]) return false;
			}
		} else {
			return false;
		}

		return true;
	}

	bool _isLowerThan(InteiroGigante comparing) {
		if (_bigIntUsedLength < comparing._getBigIntLength()) {
			return true;
		} else if (_bigIntUsedLength == comparing._getBigIntLength()) {
			if (_bigInt[_bigIntUsedLength - 1] >= comparing._getBigInt()[_bigIntUsedLength - 1]) {
				return false;
			} else {
				return true;
			}
		} else {
			return false;
		}
	}

	bool _isGreaterThan(InteiroGigante comparing) {
		if (_bigIntUsedLength > comparing._getBigIntLength()) {
			return true;
		} else if (_bigIntUsedLength == comparing._getBigIntLength()) {
			if (_bigInt[_bigIntUsedLength - 1] <= comparing._getBigInt()[_bigIntUsedLength - 1]) {
				return false;
			} else {
				return true;
			}
		} else {
			return false;
		}
	}

	int* _getBigInt() { return _bigInt; }

	int _getBigIntLength() { return _bigIntUsedLength; }
};

int main() {
	SetConsoleOutputCP(65001);

	InteiroGigante i1, i2;

	i1._leiaInteiroGigante("12as1234132412341234d24f341234123");
	i2._leiaInteiroGigante("12as1234132412341234d24f341234123");

	cout << "_isEqual: " << i1._isEqual(i2) << endl;
	cout << "_isLowerThan: " << i1._isLowerThan(i2) << endl;
	cout << "_isGreaterThan: " << i1._isGreaterThan(i2) << endl;

	i1._adicioneInteiroGigante("1");
	i1._subtraiaInteiroGigante(3);
	i1._imprimeInteiroGigante();

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}