#include <cmath>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ofstream leitor("file.txt", ios::out | ios::binary);
	int numEntradas = 0;
	double aux = 0.0;

	cin >> numEntradas;

	for (int i = 0; i < numEntradas; i++) {
		cin >> aux;
		leitor.write((char*)&aux, sizeof(double));
	}

	leitor.close();

	ifstream file("file.txt", ios::in | ios::binary);
	file.seekg((numEntradas * 8) - 8);

	for (int i = 0; i < numEntradas; i++) {
		file.read((char*)&aux, sizeof(double));
		if (fmod(aux, 1.0) == 0) {
			cout << (int)aux << endl;
		} else {
			cout << aux << endl;
		}
		if (file.tellg() >= 16) {
			file.seekg(file.tellg() - 16);
		}
	}

	file.close();

	return 0;
}