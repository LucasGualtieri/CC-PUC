#include <iostream>

using namespace std;

class Relogio {
	int hora;
	int minuto;
	int segundo;

  public:
	void setHora(int hora, int minuto, int segundo) {
		this->hora	  = hora;
		this->minuto  = minuto;
		this->segundo = segundo;
	}

	string getHora() {
		string str;
		str = to_string(hora) + ":" + to_string(minuto) + ":" + to_string(segundo);
		return str;
	}
};

int main() {

	Relogio relogio;
	relogio.setHora(12, 20, 30);

	cout << relogio.getHora() << endl;

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}