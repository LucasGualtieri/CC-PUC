#include <biblioteca_cpp.h>

class Split : public string { // Talves chamar de string?
	string* split;

public:
	int indexOf(string str, string reference, int occurrence) {

		for (int i = 0; i <= str.length() - reference.length(); i++) {
			string substring = str.substr(i, reference.length());

			if (!substring.compare(reference)) {
				if (--occurrence == 0) return i;
			}
		}

		return -1;
	}

	// string* Split(string regex) {
	// 	this->split = nullptr;
	// 	int sizeOfArray = 0;

	// 	string* position = this->split; // Tracks the position within the buffer

	// 	while (true) {
	// 		this->split = (string*)realloc(this->split, (sizeOfArray + 1) * sizeof(string));

	// 		if (indexOf(position, regex, 1) != -1) {
	// 			array[sizeOfArray] = (char*)malloc(indexOf(position, regex, 1) * sizeof(char));
	// 			strcpy(array[sizeOfArray], substr(position, 0, indexOf(position, regex, 1)));
	// 		} else {

	// 			int sizeOfAllocation;
	// 			if (sizeOfArray == 0) {
	// 				sizeOfAllocation = strlen(string); //  Only string available
	// 			} else {
	// 				sizeOfAllocation = strlen(array[sizeOfArray - 1]); // Last string read
	// 			}

	// 			array[sizeOfArray] = (char*)malloc(sizeOfAllocation * sizeof(char));
	// 			strcpy(array[sizeOfArray++], substr(position, 0, strlen(position)));

	// 			break;
	// 		}

	// 		position += strlen(array[sizeOfArray++]) + 1;
	// 	}

	// 	array = (char**)realloc(array, (sizeOfArray + 1) * sizeof(char*));
	// 	array[sizeOfArray] = nullptre;

	// 	if (freeBuffer) free(string);

	// 	return array;
	// }

	~Split() {
		for (int i = 0; this->split[i] != nullptr; i++) {
			free(split[i]);
		}
		free(split);
	}
};

int main() {

	cout << "Olá mundo!\n";

	// Split teste;

	string nome = "Lucas Gualtieri";

	cout << indexOf(nome, "ucas", 1) << endl;

	cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}