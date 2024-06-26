#include <iostream>

// clear && g++ CifraDeViegenere.cc && ./a.out

using namespace std;

// #define MOD 'Z' - 'A'

int mod(int x, int y) {
	return x % y >= 0 ? x % y : y + x;
}

string Viegenere(string msg, const string& key) {

	int len = key.length();

	auto fn = [](char c, char key) {
		return 'A' + mod(c + key, 26);
	};

	for (int i = 0; i < msg.length(); i++) {
		msg[i] = fn(msg[i], key[i % len]);
	}

	return msg;
}

string Decypher(string msg, const string& key) {

	int len = key.length();

	auto fn = [](char c, char key) {
		return 'A' + mod(c - key, 26);
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
	
	cout << Decypher(cifra, key) << endl;

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