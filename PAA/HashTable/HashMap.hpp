#ifndef HASH_MAP_HPP
#define HASH_MAP_HPP

#include <functional>
#include <iostream>
#include <format>
#include <cmath>
#include <functional>
#include <sstream>
#include <string>
#include <vector>

template <typename K, typename V>
class HashMap {

	int* indicesTable = nullptr;
	std::vector<std::pair<K, V>> valuesTable;

	std::function<int(K key)> hashFunction;

	size_t m, n;
	const float maxRatio = 2.0 / 3.0;

	bool IsPrime(long long n) {

		if (n == 2 || n == 3) return true;
		if (n < 2 || n % 2 == 0 || n % 3 == 0) return false;

		const long long LS = sqrt(n);

		for (long long i = 5; i <= LS; i += 6) {
			if (n % i == 0 || n % (i + 2) == 0) return false;
		}

		return true;
	}

	void foo() {

		if (indicesTable) {
			delete[] indicesTable;
		}

		indicesTable = (int*)calloc(m, sizeof(int));
	}

	void resize() {

		m = m * 2 + 1;

		while (!IsPrime(m)) m += 2;

		foo();

		n = 0;

		bool deuRuim = false;

		for (auto p : valuesTable) {

			int i = 0;
			int h = hash(p.first);
			int index = h + i * i;
			int start = index;

			while (indicesTable[index] != 0) {

				index = (h + i * i) % m;
				i++;

				if (index == start) {
					deuRuim = true;
					std::cout << "DEU RUIM NO RE SIZE!" << std::endl;
					resize();
					break;
				}
			}

			if (deuRuim) break;

			// NOTE: Isso vai dar problema se houverem remocoes
			indicesTable[index] = n;
			n++;
		}
	}

public:

	HashMap(size_t m = 11) : m(m), n(0) {
		foo();
		valuesTable.push_back({});
	}

	HashMap(std::function<int(K key)> lambda, size_t m = 11) : hashFunction(lambda), m(m), n(0) {
		foo();
		valuesTable.push_back({});
	}

	~HashMap() { if (indicesTable) delete[] indicesTable; }

	int hash(K key) { return hashFunction(key) % m; }

	void add(std::pair<K, V> keyValue) {
		
		if (((n + 1) / (float)m) > maxRatio) resize();

		int i = 0;
		int h = hash(keyValue.first);
		int index = h + i * i;
		int start = index;

		while (indicesTable[index] != 0) {

			index = (h + i * i) % m;
			i++;

			if (index == start) {
				std::cout << "DEU RUIM BIG TIME!" << std::endl;
				// resize();
				// break;
			}
		}

		indicesTable[index] = valuesTable.size();
		valuesTable.push_back(keyValue);

		n++;
	}

	V get(K key) {

		int i = 0;
		int h = hash(key);
		int index = h + i * i;
		int start = index;

		while (valuesTable[indicesTable[index]].first != key) {
			index = (h + i * i) % m;
			i++;
			if (index == start) return V();
		}

		return valuesTable[indicesTable[index]].second;
	}

	std::string str() const {

		std::ostringstream os;

		for (int i = 1; i < valuesTable.size(); i++) {
			auto p = valuesTable[i];
			os << std::format("{{{}, {}}})", p.first, p.second) << std::endl;
		}

		return os.str();
	}

	friend std::ostream& operator<<(std::ostream& os, const HashMap& hash) {
		os << hash.str();
		return os;
	}
};

#endif
