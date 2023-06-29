#ifndef SPLIT_H
#define SPLIT_H

#include <string>
#include <vector>

using namespace std;

class Split {
	vector<string> array;

  public:
	Split(string str, string splitAt) {
		split(str, splitAt);
	}

	Split() { }

	void split(string str, string split) {
		size_t start = 0, found = str.find(split);

		while (found != string::npos) {
			array.push_back(str.substr(start, found - start));
			start = found + split.length();
			found = str.find(split, start);
		}

		string last = str.substr(start);

		bool valid = !last.empty() && (last[0] != '\r' && last[0] != '\n' && last[0] != EOF);

		if (valid) array.push_back(last);

		if (array.size() == 0) throw string(RED + "Error on Split: " + RESET + "Unable to split line: \"" + str + "\"\n");
	}

	int length() {
		return array.size();
	}

	void trimAll(char trimC = ' ') {
		for (int i = 0; i < array.size(); i++) {
			trim(array[i], trimC);
		}
	}

	void trim(string& str, char trim = ' ') {

		if (str.empty()) return;

		for (int i = 0; str.at(0) == trim; i++) {
			str.erase(0, 1);
		}

		for (int i = str.length() - 1; str.at(i) == trim; i--) {
			str.erase(i, 1);
		}
	}

	string operator[](size_t index) {
		string error = "Error: Index [" + to_string(index) + "] is out of bounds!";
		if (index >= array.size() || index < 0) throw error;

		return array[index];
	}
};

#endif