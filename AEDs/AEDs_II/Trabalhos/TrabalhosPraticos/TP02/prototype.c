#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// #include <stdlib.h>

// clear && gcc prototype.c && ./a.out < pub.in

#define STR_MAX_TAM 500

typedef const char* const literal;
typedef char* String;

void readStr(String input) {
	fgets(input, STR_MAX_TAM, stdin);
	// input[strlen(input) - 1] = 0;
	printf("input: %s\n", input);
	// return input;
}

char** Split(String file) {
	int numberOfKeys = 8;
	char** arrayOfStrings = (char**)malloc(numberOfKeys * sizeof(char*));

	for (int i = 0; i < numberOfKeys; i++) {
		arrayOfStrings[i] = (char*)malloc(STR_MAX_TAM * sizeof(char));
	}

	arrayOfStrings[0] = strtok(file, ",");

    // Iterate through the tokens
    for (int i = 1; i < numberOfKeys; i++) {
		arrayOfStrings[1] = strtok(NULL, ",");
    }

	return arrayOfStrings;

}

int main() {
	literal filePath = "players.csv";
	FILE* file = fopen(filePath, "r");

	char input[STR_MAX_TAM];
	char fileBuffer[STR_MAX_TAM];

	readStr(input);
	while (strcmp(input, "FIM")) {
		fgets(fileBuffer, STR_MAX_TAM, file);
		fileBuffer[strlen(fileBuffer) - 1] = 0;
		printf("%s\n", fileBuffer);

		char** split = Split(fileBuffer);

		printf("split[1]: %s\n", split[1]);
		// free(split);

		readStr(input);
	}
	printf("\n");

}