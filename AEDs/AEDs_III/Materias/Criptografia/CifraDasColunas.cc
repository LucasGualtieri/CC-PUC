#include <iostream>
#include <cmath>
#include <algorithm>
#include "Matrix.hpp"

// clear && g++ CifraDasColunas.cc && ./a.out

// Importante esclarecer que esse codigo implementa o algoritmo de cifragem de forma ineficiente (provavelmente tem formas melhores de fazer).
// O algoritmo de decifragem foi implementado de forma extremamente ineficiente.

using namespace std;

string Colunas(string msg, const string& key) {

	int height = ceil((float)msg.length() / key.length());
	int width = key.length();

	Matrix<char> matrix(height, width);

	int counter = 0;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {

			if (counter < msg.length()) {
				matrix[i][j] = msg[counter++];
			}

			else matrix[i][j] = '*';
		}
	}

	cout << matrix << endl;

	string sortedKey = key;
	sort(sortedKey.begin(), sortedKey.end());

	string result;

	for (char c : sortedKey) {
		int column = key.find(c);
		for (int i = 0; i < height; i++) {
			if (matrix[i][column] != '*') {
				result += matrix[i][column];
			}
		}
	}

	return result;
}

string Decypher(string msg, const string& key) {

	int height = ceil((float)msg.length() / key.length());
	int width = key.length();

	Matrix<char> matrix(height, width);

	int counter = 0;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (counter++ >= msg.length()) {
				matrix[i][j] = '*';
			}
		}
	}

	string sortedKey = key;
	sort(sortedKey.begin(), sortedKey.end());

	counter = 0;

	for (char c : sortedKey) {
		int column = key.find(c);
		for (int i = 0; i < height; i++) {
			if (counter >= msg.length() || matrix[i][column] == '*') {
				break;
			}
			matrix[i][column] = msg[counter++];
		}
	}

	// cout << matrix << endl;

	string result;

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (matrix[i][j] == '*') break;
			result += matrix[i][j];
		}
	}

	return result;
}

int main() {

	string msg = "PROVA NA SEGUNDA FEIRA";
	string key = "NOTAS";

	string cifra = Colunas(msg, key);
	cout << cifra << endl;

	cout << "---------------------------" << endl;
	
	cout << Decypher(cifra, key) << endl;

	return 0;
}