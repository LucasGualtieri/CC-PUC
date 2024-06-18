#include <cmath>
#include <iostream>
#include <algorithm>
#include <memory>
#include "Matrix.hpp"

// clear && g++ ComboCriptografico.cc && ./a.out

using namespace std;

#define implements public
#define extends public
#define interface struct
#define pure = 0

/*
	https://chatgpt.com/share/431fbe20-e0bf-4dad-8a22-95c1eb069fe8
	In summary, a pure virtual function is defined by appending = 0
	to its declaration, indicating that the function must be
	implemented by derived classes, and the class containing it
	becomes an abstract class.
*/

// Cipher Interface
interface CipherStrategy {
	virtual ~CipherStrategy() = default;
	virtual string cipher(string msg, const string& key) const pure;
	virtual string decipher(string msg, const string& key) const pure;
};

// Concrete Strategy A: Cipher with Viegenere
struct ViegenereCipher : implements CipherStrategy {

	int mod(int x, int y) const {
		return x % y >= 0 ? x % y : y + x;
	}

	string cipher(string msg, const string& key) const override {

		int len = key.length();

		for (int i = 0; i < msg.length(); i++) {
			msg[i] = 'A' + mod(msg[i] + key[i % len], 26);
		}

		return msg;
	}

	string decipher(string msg, const string& key) const override {

		int len = key.length();

		auto fn = [*this](char c, char key) {
			return 'A' + mod(c - key, 26);
		};

		for (int i = 0; i < msg.length(); i++) {
			msg[i] = 'A' + mod(msg[i] + key[i % len], 26);
		}

		return msg;
	}

};

// Concrete Strategy A: Cipher with ViegenereModified
struct ViegenereModifiedCipher : implements CipherStrategy {

	vector<int> foo(string key) const {

		string sortedKey = key;
		sort(sortedKey.begin(), sortedKey.end());

		vector<int> indices;

		for (char c : sortedKey) {
			indices.push_back(key.find(c) + 1);
		}

		return indices;
	}

	string cipher(string msg, const string& key) const override {

		vector<int> indices = foo(key);

		int len = key.length();

		for (int i = 0; i < msg.length(); i++) {
			msg[i] += indices[i % len];
		}

		return msg;
	}

	string decipher(string msg, const string& key) const override {

		vector<int> indices = foo(key);

		int len = key.length();

		for (int i = 0; i < msg.length(); i++) {
			msg[i] -= indices[i % len];
		}

		return msg;
	}

};

// Concrete Strategy B: Cipher with Columns
struct ColumnsCipher : implements CipherStrategy {

	string cipher(string msg, const string& key) const override {

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

		// cout << matrix << endl;

		string sortedKey = key;
		sort(sortedKey.begin(), sortedKey.end());

		string result;

		for (char c : sortedKey) {
			int column = key.find(c);
			for (int i = 0; i < height; i++) {
				if (matrix[i][column] == '*') break;
				result += matrix[i][column];
			}
		}

		return result;
	}

	string decipher(string msg, const string& key) const override {

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

};

// Context
class Cipher {

  private:
	unique_ptr<CipherStrategy> strategy;

  public:

	Cipher(unique_ptr<CipherStrategy> strategy = nullptr) : strategy(move(strategy)) {}
	
	void setStrategy(unique_ptr<CipherStrategy> strategy) {
		this->strategy = move(strategy);
	}

	string cipher(string msg, const string& key) const {

		if (!strategy) throw runtime_error("Strategy not set!");

		return strategy->cipher(msg, key);
	}

	string decipher(string msg, const string& key) const {

		if (!strategy) throw runtime_error("Strategy not set!");

		return strategy->decipher(msg, key);
	}

};

int main() {

	string key = "CANO";
	string msg = "O RATO ROEU A ROUPA DO REI DE ROMA";

	cout << msg << endl;

	Cipher cipher(make_unique<ColumnsCipher>());

	msg = cipher.cipher(msg, key);
	// cout << msg << endl;

	cipher.setStrategy(make_unique<ViegenereModifiedCipher>());

	msg = cipher.cipher(msg, key);
	cout << msg << endl;

	cipher.setStrategy(make_unique<ViegenereModifiedCipher>());

	msg = cipher.decipher(msg, key);
	cout << msg << endl;

	cipher.setStrategy(make_unique<ColumnsCipher>());

	msg = cipher.decipher(msg, key);
	cout << msg << endl;

	return 0;
}