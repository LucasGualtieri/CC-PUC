#include <iostream>

// clear && g++ CifraDeViegenere.cc && ./a.out

using namespace std;

string Viegenere(string msg, const string& key) {

	int len = key.length();

	auto fn = [](char c, char key) {
		return (((c + key) % 26) + 'A');
	};

	for (int i = 0; i < msg.length(); i++) {
		msg[i] = fn(msg[i], key[i % len]);
	}

	return msg;
}

int main() {

	string msg = "FIMDESEMANA";
	string key = "CARO";

	string cifra = Viegenere(msg, key);

	cout << cifra << endl;

	return 0;
}

// string Viegenere(string msg, const string& key) {

// 	int len = key.length();

// 	auto fn = [=](char c, string key) {
// 		static int i = 0;
// 		return (((c + key[i++ % len]) % 26) + 'A');
// 	};

// 	for (char& c : msg) c = fn(c, key);

// 	return msg;
// }