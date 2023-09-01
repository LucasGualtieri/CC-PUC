#include "../LibCTP01.h"

// clear && gcc TP01Q09.c -o TP01Q09 && ./TP01Q09 < pub.in > result.txt

void cursorReset(int* currentPosition, FILE* file) {
	fseek(file, --(*currentPosition), SEEK_SET);
	while (*currentPosition >= 0 && fgetc(file) != '\n') {
		fseek(file, (*currentPosition)--, SEEK_SET);
	}
	fseek(file, ++(*currentPosition), SEEK_SET);
}

int main() {

	FILE* file = fopen("TP01Q09_LucasGualtieri.txt", "w");

	int numberOfRealNumbers = getFloat(0);

	for (int i = 0; i < numberOfRealNumbers; i++) {
		fprintf(file, "%g",  getFloat(0));
		fprintf(file, "%s", i < numberOfRealNumbers - 1 ? "\n" : "");
	}

	fclose(file);

	// --------------------------------------------------------

	file = fopen("TP01Q09_LucasGualtieri.txt", "r");
	fseek(file, 0, SEEK_END);
	int currentPosition = ftell(file);

	for (int i = 0; i < numberOfRealNumbers; i++) {
		cursorReset(&currentPosition, file);
		printf("%g",  getFloat(file));
		printf("%s", i < numberOfRealNumbers - 1 ? "\n" : "");
	}

	fclose(file);

	return 0;
}
