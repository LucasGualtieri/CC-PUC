#include <cmath>
#include <functional>
#include <iostream>
#include <sstream>
#include <vector>
#include <format>

using namespace std;

// clear && g++ edgeClassification.cc -std=c++23 && ./a.out

template <typename K, typename V>
class HashMap {

	int* indicesTable = nullptr;
	vector<pair<K, V>> valuesTable;

	function<int(K key)> hashFunction;

	size_t m, n;
	const float maxRatio = 2.0 / 3.0;

	size_t h(int value) { return value; }

	bool IsPrime(long long n) {

		if (n == 2 || n == 3) return true;
		if (n < 2 || n % 2 == 0 || n % 3 == 0) return false;

		const long long LS = sqrt(n);

		for (long long i = 5; i <= LS; i += 6) {
			if (n % i == 0 || n % (i + 2) == 0) return false;
		}

		return true;
	}

	void resize() {

		m = m * 2 + 1;

		while (!IsPrime(m)) m += 2;

		delete[] indicesTable;
		indicesTable = new int[m];

		for (int i = 0; i < m; i++) indicesTable[i] = -1;

		n = 0;
		for (auto p : valuesTable) add(p);
	}

public:

	HashMap(size_t m = 11) : m(m), n(0) {
		indicesTable = new int[m];
		for (int i = 0; i < m; i++) indicesTable[i] = -1;
	}

	HashMap(function<int(K key)> lambda, size_t m = 11) : hashFunction(lambda), m(m), n(0) {
		indicesTable = new int[m];
		for (int i = 0; i < m; i++) indicesTable[i] = -1;
	}

	HashMap(function<int(K key)> lambda, initializer_list<pair<K, V>> list, size_t m = 11) : hashFunction(lambda), m(m), n(0) {
		indicesTable = new int[m];
		for (int i = 0; i < m; i++) indicesTable[i] = -1;

		for (auto p : list) add(p);
	}

	~HashMap() { if (indicesTable) delete[] indicesTable; }

	int hash(K key) { return hashFunction(key) % m; }

	void add(pair<K, V> keyValue) {

		if (((n + 1) / (float)m) > maxRatio) resize();

		int i = 0;
		int h = hash(keyValue.first);
		int index = h + i * i;

		// Qual a garantia de que mesmo depois de um resize esse while n vai rodar pra sempre?
		while (indicesTable[index] != -1) {
			index = (h + i * i) % m;
			i++;
			// TODO: Got figure out an better upper limmit and what to do with it
			// if (i > m) return V();
		}

		// i = valuesTable += keyValue;
		valuesTable.push_back(keyValue);

		for (i = 0; i < valuesTable.size(); i++) {
			if (valuesTable[i] == keyValue) break;
		}

		indicesTable[index] = i;
		n++;
	}

	V get(const K& key) {

		int i = 0;
		int h = hash(key);
		int index = h + i * i;

		while (valuesTable[indicesTable[index]].first != key) {
			index = (h + i * i) % m;
			i++;
			// TODO: Got figure out a better upper limmit and a better return value;
			if (i > m) return V();
		}

		return valuesTable[indicesTable[index]].second;
	}

	string str() const {

		ostringstream os;

		for (auto p : valuesTable) {
			os << format("({}, {})", p.first, p.second) << endl;
		}

		return os.str();
	}

	friend ostream& operator<<(ostream& os, const HashMap& hash) {
		os << hash.str();
		return os;
	}

	V operator[](const K& key) {

		int i = 0;
		int h = hash(key);
		int index = h + i * i;

		while (valuesTable[indicesTable[index]].first != key) {
			index = (h + i * i) % m;
			i++;
			// TODO: Got figure out a better upper limmit and a better return value;
			if (i > m) return V();
		}

		return valuesTable[indicesTable[index]].second;
	}
};

int main() {

	HashMap<int, string> hash {[](int a) { return a; }, {
		{0, "\"white\""},
		{1, "blue"},
		{2, "red"}
	}};

	cout << hash[0] << endl;
	cout << hash[1] << endl;
	cout << hash[2] << endl;
	cout << hash[3] << endl;

	cout << hash << endl;

	return 0;
}

