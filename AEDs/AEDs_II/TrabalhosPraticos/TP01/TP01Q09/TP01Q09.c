#include "../LibCTP01.h"

// clear && gcc TP01Q09.c -o TP01Q09 && ./TP01Q09 < pub.in > result.txt

void cursorReset(int* virtualCursor, FILE* file) {
	fseek(file, --(*virtualCursor), SEEK_SET);
	while (*virtualCursor >= 0 && fgetc(file) != '\n') {
		fseek(file, --(*virtualCursor), SEEK_SET);
	}
	fseek(file, *virtualCursor + 1, SEEK_SET);
}

int main() {

	String filePath = "TP01Q09_LucasGualtieri.txt";
	FILE* file = fopen(filePath, "w");

	int numberOfRealNumbers = getInt(stdin);

	for (int i = 0; i < numberOfRealNumbers; i++) {
		fprintf(file, "%g",  getFloat(stdin));
		if (i < numberOfRealNumbers - 1) fprintf(file, "\n");
	}

	fclose(file);

	// --------------------------------------------------------

	file = fopen(filePath, "r");
	fseek(file, 0, SEEK_END);
	int virtualCursor = ftell(file);

	for (int i = 0; i < numberOfRealNumbers; i++) {
		cursorReset(&virtualCursor, file);
		printf("%g",  getFloat(file));
		if (i < numberOfRealNumbers - 1) puts("");
	}

	fclose(file);

	return 0;
}