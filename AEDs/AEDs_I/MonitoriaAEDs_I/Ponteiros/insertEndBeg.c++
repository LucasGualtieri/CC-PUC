#include <biblioteca_cpp.h>

void fn(char* String) {
	char c = 'Z';

	int ultimo = strlen(String);

	String[ultimo]	   = c;
	String[ultimo + 1] = '\0';
}

void insertBeg(char c, char* String, int arrayLength) {
	if (strlen(String) == arrayLength) {
		cout << "Impossível fazer a inserção: Array cheio!" << endl;
		return;
	}

	for (int i = strlen(String); i >= 0; i--) {
		// String[i + 1] = String[i];
		*(String + (i + 1)) = *(String + i);
	}

	String[0] = c;
}

int main() {

	int arrayLength = 50;

	char* String = new char[arrayLength];
	char  string[50];

	cin >> String;
	cout << String << endl;

	insertBeg('Z', String, arrayLength);
	cout << String;
	// String = fn(String);

	delete[] String;

	cout << "\n------- | FIM DO PROGRAMA | -------\n\n";
	return 0;
}