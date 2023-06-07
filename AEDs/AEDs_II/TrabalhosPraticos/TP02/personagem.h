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

	friend ostream& operator<<(ostream& cout, const Personagem obj) {
		cout << " ## " << obj.name;
		cout << " ## " << obj.height;
		cout << " ## " << obj.weight;
		cout << " ## " << obj.hairColor;
		cout << " ## " << obj.skinColor;
		cout << " ## " << obj.eyeColor;
		cout << " ## " << obj.birthYear;
		cout << " ## " << obj.gender;
		cout << " ## " << obj.homeworld;
		cout << " ## ";
		return cout;
	}

	float birthYearValue() {
		int end = getBirthYear().find("BB", 0, 2);
		if (end == string::npos) end = getBirthYear().find("AB", 0, 2);
		if (end == string::npos) return end;

		char beforeAfter = getBirthYear().at(end + 2);

		float birthYear = stof(getBirthYear().substr(0, end));

		if (beforeAfter == 'A') {
			return birthYear;
		} else {
			return -birthYear;
		}
	}

	shared_ptr<Personagem> clone() {
		shared_ptr<Personagem> clone = make_shared<Personagem>();

		clone->setName(this->name);
		clone->setHeight(this->height);
		clone->setWeight(this->weight);
		clone->setHairColor(this->hairColor);
		clone->setSkinColor(this->skinColor);
		clone->setEyeColor(this->eyeColor);
		clone->setBirthYear(this->birthYear);
		clone->setGender(this->gender);
		clone->setHomeworld(this->homeworld);

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
void List<shared_ptr<Personagem>>::InsertionSort(int& numberOfComparisons, int& numberOfSwaps) {

	numberOfComparisons = 1;
	numberOfSwaps = 0;

	for (int i = 1, j; i < size; i++) {
		numberOfComparisons++;
		if (array[i - 1]->getBirthYear() > array[i]->getBirthYear()) {
			shared_ptr<Personagem> temp = array[i];
			for (j = i - 1; j >= 0; j--) {
				numberOfComparisons++;
				if (array[j]->getBirthYear() > temp->getBirthYear()) {
					numberOfComparisons++;
					array[j + 1] = array[j];
				} else {
					numberOfComparisons++;
					break;
				}
			}
			numberOfComparisons++;
			array[j] = temp;
			numberOfSwaps++;
		}
		numberOfComparisons++;
	}
	numberOfComparisons++;
}

template <>
int List<shared_ptr<Personagem>>::RecursiveSelectionSort(int& numberOfSwaps, int minIndex, int i, int j) {
	int numberOfComparisons = 0;

	if (j < size) {
		if (array[minIndex]->getName() > array[j]->getName()) {
			minIndex = j;
		}
		if (++j < size) {
			numberOfComparisons += RecursiveSelectionSort(numberOfSwaps, minIndex, i, j);
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
			numberOfComparisons += RecursiveSelectionSort(numberOfSwaps, i, i, i + 1);
		}
		numberOfComparisons += 4;
	}
	return numberOfComparisons += (j == size) ? 2 : 1;
}

template <>
void List<shared_ptr<Personagem>>::SelectionSort(int& numberOfComparisons, int& numberOfSwaps) {

	numberOfComparisons = 1;
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
void List<shared_ptr<Personagem>>::print(bool printIndices) {
	for (int i = 0; i < size; i++) {
		if (printIndices) printf("[%d] ", i);
		array[i]->print();
		// if (i < size - 1) cout << endl; // To ovoid /n at the very last print();
	}
}

void printLog(Timer timer, string fileName, int numberOfComparisons, int numberOfSwaps = -1) {

	ofstream log(fileName);

	log << "Matrícula: 794989\t";
	log << "Tempo de execução: " << timer.result() << "ms\t";
	if (numberOfComparisons >= 0) log << "Número de movimentações: " << numberOfSwaps << "\t";
	log << "Número de comparações: " << numberOfComparisons;

	log.close();
}

#endif