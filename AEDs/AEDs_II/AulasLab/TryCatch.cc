#include <iostream>
// #include <exception>

using namespace std;

class Exception {
	string msg;
  public:
	Exception(string msg) {
		this->msg = msg;
	}
	string what() {
		return msg;
	}
};

int teste(int x, int y) {
	if (y == 0) {
		// throw string("Erro: Divisão por 0");
		// throw runtime_error("Erro: Divisão por 0");
		// throw Platform::Exception(1, "Erro: Divisão por 0");
		// throw Exception("Erro: Minha propria excecao");
		throw out_of_range("Erro!!!!!");
	}
	return x / y;
}

int main() {
	int x = 2;
	int y = 0;
	try {
		teste(x, y);
	} catch (const char* erro) {
		cout << erro << endl; 	
	} catch (Exception e) {
		// cout << "OLAAAA Divisão por 0" << endl;
		cout << e.what() << endl; 	
	} catch(string erro) {
		cout << erro << endl;
	} catch(out_of_range e) {
		cout << e.what();
	} catch (...) {
		cout << "Divisão por 0" << endl;
	}
	// cout << y / x;
	return 0;
}