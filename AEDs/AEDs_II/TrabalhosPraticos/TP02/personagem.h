#ifndef PERSONAGEM_H
#define PERSONAGEM_H

#include <fstream>
#include <iostream>
#include <list.h>
#include <split.h>
#include <string>
#include <timer.h>

using namespace std;

class Personagem {
	string name;
	int height;
	double weight;
	string hairColor;
	string skinColor;
	string eyeColor;
	string birthYear;
	string gender;
	string homeworld;

public:
	Personagem() {
		setName("(null)");
		setHeight(0);
		setWeight(0.0);
		setHairColor("(null)");
		setSkinColor("(null)");
		setEyeColor("(null)");
		setBirthYear("(null)");
		setGender("(null)");
		setHomeworld("(null)");
	}

	Personagem(string fileDir) {

		setName("(null)");
		setHeight(0);
		setWeight(0.0);
		setHairColor("(null)");
		setSkinColor("(null)");
		setEyeColor("(null)");
		setBirthYear("(null)");
		setGender("(null)");
		setHomeworld("(null)");

		ReadData(fileDir);
	}

	~Personagem() {
		// cout << "My name is " << getName() << " and I'm being deallocated!" << endl;
	}

	// Setter and Getter of name
	void setName(string name) {
		this->name = name;
	}

	string getName() {
		return name;
	}

	// -------------------------------

	// Setter and Getter of height
	void setHeight(int height) {
		this->height = height;
	}

	int getHeight() {
		return height;
	}

	// -------------------------------

	// Setter and Getter of weight
	void setWeight(double weight) {
		this->weight = weight;
	}

	double getWeight() {
		return weight;
	}

	// -------------------------------

	// Setter and Getter of hairColor
	void setHairColor(string hairColor) {
		this->hairColor = hairColor;
	}

	string getHairColor() {
		return hairColor;
	}

	// -------------------------------

	// Setter and Getter of skinColor
	void setSkinColor(string skinColor) {
		this->skinColor = skinColor;
	}

	string getSkinColor() {
		return skinColor;
	}

	// -------------------------------

	// Setter and Getter of eyeColor
	void setEyeColor(string eyeColor) {
		this->eyeColor = eyeColor;
	}

	string getEyeColor() {
		return eyeColor;
	}

	// -------------------------------

	// Setter and Getter of birthYear
	void setBirthYear(string birthYear) {
		this->birthYear = birthYear;
	}

	string getBirthYear() {
		return birthYear;
	}

	// -------------------------------

	// Setter and Getter of gender
	void setGender(string gender) {
		this->gender = gender;
	}

	string getGender() {
		return gender;
	}

	// -------------------------------

	// Setter and Getter of homeworld
	void setHomeworld(string homeworld) {
		this->homeworld = homeworld;
	}

	string getHomeworld() {
		return homeworld;
	}

	// -------------------------------

	void ReadData(string fileDir) { // Um jeito meio cambiarroso de parsear o json

		ifstream file(fileDir);
		if (!file.is_open()) throw runtime_error("Failed to open file: " + fileDir);
		string jsonstring = readString(file);
		file.close();

		// Separando keys e values e atribuindo a suas variaveis
		ReplaceAll(jsonstring, "{}", "");
		split pairs(jsonstring, ", '");
		for (int i = 0; i < pairs.length(); i++) {

			split keyValue(pairs[i], ": ");

			string key = keyValue[0];
			string value = keyValue[1];
			ReplaceAll(key, "'", "");
			ReplaceAll(value, "'", "");

			if (!key.compare("name")) {
				setName(value);
			} else if (!key.compare("height")) {
				if (value.compare("unknown")) {
					setHeight(stoi(value));
				}
			} else if (!key.compare("mass")) {
				if (value.compare("unknown")) {
					ReplaceAll(value, ",", "");
					setWeight(stod(value));
				}
			} else if (!key.compare("hair_color")) {
				setHairColor(value);
			} else if (!key.compare("skin_color")) {
				setSkinColor(value);
			} else if (!key.compare("eye_color")) {
				setEyeColor(value);
			} else if (!key.compare("birth_year")) {
				setBirthYear(value);
			} else if (!key.compare("gender")) {
				setGender(value);
			} else if (!key.compare("homeworld")) {
				setHomeworld(value);
			} else {
				break;
			}
		}
	}

	void print() {
		cout << " ## " << name;
		cout << " ## " << height;
		cout << " ## " << weight;
		cout << " ## " << hairColor;
		cout << " ## " << skinColor;
		cout << " ## " << eyeColor;
		cout << " ## " << birthYear;
		cout << " ## " << gender;
		cout << " ## " << homeworld;
		cout << " ## " << endl;
		// cout << " ## ";
	}

	// T operator<<() {
	// 	if (index >= size) {
	// 		throw string("Error: Index [" + to_string(index) + "] is out of bounds!");
	// 	}

	// 	print();
	// }

	Personagem clone() {
		Personagem clone;

		clone.name = this->name;
		clone.height = this->height;
		clone.weight = this->weight;
		clone.hairColor = this->hairColor;
		clone.skinColor = this->skinColor;
		clone.eyeColor = this->eyeColor;
		clone.birthYear = this->birthYear;
		clone.gender = this->gender;
		clone.homeworld = this->homeworld;

		return clone;
	}
};

shared_ptr<Personagem> NewPersonagem() {
	return make_shared<Personagem>();
}

shared_ptr<Personagem> NewPersonagem(string fileDir) {
	return make_shared<Personagem>(fileDir);
}

template <>
int List<shared_ptr<Personagem>>::SelectionRecSort(int& numberOfSwaps, int minIndex, int i, int j) {
	int numberOfComparisons = 0;

	if (j < size) {
		if (array[minIndex]->getName() > array[j]->getName()) {
			minIndex = j;
		}
		if (++j < size) {
			numberOfComparisons += SelectionRecSort(numberOfSwaps, minIndex, i, j);
		}
		numberOfComparisons += 2;
	}
	numberOfComparisons++;

	if (i < size - 1 && j == size) {
		if (array[minIndex] != array[i]) {
			shared_ptr<Personagem> swap = array[minIndex];
			array[minIndex] = array[i];
			array[i] = swap;

			numberOfSwaps++;
		}

		if (++i < size - 1) {
			numberOfComparisons += SelectionRecSort(numberOfSwaps, i, i, i + 1);
		}
		numberOfComparisons += 4;
	}
	return numberOfComparisons += (j == size) ? 2 : 1;
}

template <>
int List<shared_ptr<Personagem>>::SelectionSort(int& numberOfSwaps) {
	int numberOfComparisons = 1;
	numberOfSwaps = 0;

	for (int i = 0; i < size - 1; i++) {
		int minIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (array[minIndex]->getName() > array[j]->getName()) minIndex = j;
			numberOfComparisons += 2;
		}
		if (array[minIndex] != array[i]) {
			shared_ptr<Personagem> swap = array[minIndex];
			array[minIndex] = array[i];
			array[i] = swap;

			numberOfSwaps++;
		}

		numberOfComparisons += 3;
	}

	return numberOfComparisons;
}

template <>
template <>
bool List<shared_ptr<Personagem>>::BinarySearch(string searching, int& numberOfComparisons) {
	bool found = false;

	int start = 0, end = size - 1;

	while (!found && start <= end) {
		int middle = (start + end) / 2;

		if (searching == array[middle]->getName()) {
			found = true;
			numberOfComparisons++;
		} else if (searching > array[middle]->getName()) {
			start = ++middle;
			numberOfComparisons += 2;
		} else {
			end = --middle;
			numberOfComparisons += 2;
		}

		numberOfComparisons += 2;
		// this_thread::sleep_for(chrono::milliseconds(1));
	}

	numberOfComparisons += found ? 1 : 2;

	return found;
}

template <>
template <>
bool List<shared_ptr<Personagem>>::SequentialSearch(string searching, int& numberOfComparisons) {

	bool found = false;
	for (int i = 0; !found && i < size; i++) {
		found = array[i]->getName() == searching;
		numberOfComparisons += 3;
		// this_thread::sleep_for(chrono::milliseconds(1));
	}
	numberOfComparisons += found ? 1 : 2;
	return found;
}

template <>
void List<shared_ptr<Personagem>>::populate() {
	string fileDir;
	while ((fileDir = readString()) != "FIM") {
		insertEnd(NewPersonagem(fileDir));
	}
}

template <>
void List<shared_ptr<Personagem>>::print(bool printIndex) {
	for (int i = 0; i < size; i++) {
		if (printIndex) printf("[%d] ", i);
		// array[i]; // once << overload is implemented
		array[i]->print(); // ai esse vai de berço
		// if (i < size - 1) cout << endl; // To ovoid /n at the very last print();
	}
}

// template <>
// void List<shared_ptr<Personagem>>::sort() {
// 	for (int i = 0; i < size - 1; i++) {
// 		int menor = i;
// 		for (int j = i + 1; j < size; j++) {
// 			if (array[menor]->getAge() > array[j]->getAge()) menor = j;
// 		}
// 		shared_ptr<Personagem> swap = array[menor];
// 		array[menor] = array[i];
// 		array[i] = swap;
// 	}
// }

#endif