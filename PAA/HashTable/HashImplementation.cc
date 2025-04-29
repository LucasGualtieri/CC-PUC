#include <iostream>
#include "HashMap.hpp"

using namespace std;

// clear && g++ HashImplementation.cc -std=c++23 && ./a.out

int main() {

	auto compare = [](const string& key) {
		int soma = 0;
		for (const char& c : key) soma += c;
		return soma;
	};

	HashMap<string, int> hash(compare);

	hash.add({"lucas", 22});
	cout << "hash.valueOf(\"lucas\"): " << hash.get("lucas") << endl;
	hash.add({"sacul", 25});
	cout << "hash.valueOf(\"sacul\"): " << hash.get("sacul") << endl;
	hash.add({"arjuna", 22});
	cout << "hash.valueOf(\"arjuna\"): " << hash.get("arjuna") << endl;
	hash.add({"anujra", 20});
	cout << "hash.valueOf(\"anujra\"): " << hash.get("anujra") << endl;

	cout << hash << endl;

	return 0;
}

