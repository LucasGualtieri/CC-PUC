#ifndef SPLIT_H
#define SPLIT_H

#include <string>
#include <vector>

using namespace std;

class split {
	vector<string> array;

public:
	split(string str, string split) {
		size_t start = 0, found = str.find(split);

		while (found != string::npos) {
			array.push_back(str.substr(start, found - start));
			start = found + split.length();
			found = str.find(split, start);
		}

		array.push_back(str.substr(start));
	}

	int length() {
		return array.size();
	}

	string operator[](size_t index) {
		string error = "Error: Index [" + to_string(index) + "] is out of bounds!";
		if (index >= array.size()) return error;

		return array[index];
	}
};

#endif