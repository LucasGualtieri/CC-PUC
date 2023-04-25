#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// clear && gcc TP02Q02.c -o TP02Q02 && ./TP02Q02 < pub.in > out.txt

// Funções auxiliares - Reimplementações de funções em java
char* fgetsptr(FILE* file);

char* substr(char* string, int beggining, int end);

char* replaceAll(char* string, char* regex, char* replacement);

char* trim(char* string);

int indexOf(char* string, char* reference);

char** split(char* string, char* regex);

typedef struct Personagem Personagem;
struct Personagem {
	char* nome;
	int altura;
	double peso;
	char* corDoCabelo;
	char* corDaPele;
	char* corDosOlhos;
	char* anoNascimento;
	char* genero;
	char* homeworld;
};

void Construtor(Personagem* personagem) {
	personagem->nome = (char*)malloc(50);
	personagem->altura = 0;
	personagem->peso = 0;
	personagem->corDoCabelo = (char*)malloc(50);
	personagem->corDaPele = (char*)malloc(50);
	personagem->corDosOlhos = (char*)malloc(50);
	personagem->anoNascimento = (char*)malloc(50);
	personagem->genero = (char*)malloc(50);
	personagem->homeworld = (char*)malloc(50);
}

void Ler(Personagem* personagem, char* filePath) {

	FILE* file = fopen(filePath, "r");

	if (file == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		exit(0);
	}

	char* jsonString;
	jsonString = fgetsptr(file);
	fclose(file);

	// Remove as chaves do começo e fim do JSON
	jsonString[strlen(jsonString) - 1] = '\0';
	jsonString++;

	char** pairs = split(jsonString, ", '");
	int sizeOfPairs = 9;

	for (int i = 0; i < sizeOfPairs; i++) {
		char** pair = split(pairs[i], ":");
		char* key = replaceAll(trim(pair[0]), "\'", "");
		char* value = replaceAll(trim(pair[1]), "\'", "");

		// printf("Key: \"%s\"\n", key);
		// printf("Value: \"%s\"\n", value);

		if (!strcmp(key, "name")) {
			strcpy(personagem->nome, value);
		} else if (!strcmp(key, "height")) {
			if (!strcmp(key, "unknown")) {
				personagem->altura = 0;
			} else {
				personagem->altura = atoi(value);
			}
		} else if (!strcmp(key, "mass")) {
			if (!strcmp(value, "unknown")) {
				personagem->peso = 0;
			} else {
				personagem->peso = strtod(replaceAll(value, ",", ""), NULL);
			}
		} else if (!strcmp(key, "hair_color")) {
			personagem->corDoCabelo = value;
		} else if (!strcmp(key, "skin_color")) {
			personagem->corDaPele = value;
		} else if (!strcmp(key, "eye_color")) {
			personagem->corDosOlhos = value;
		} else if (!strcmp(key, "birth_year")) {
			personagem->anoNascimento = value;
		} else if (!strcmp(key, "gender")) {
			personagem->genero = value;
		} else if (!strcmp(key, "homeworld")) {
			personagem->homeworld = value;
		}
	}
}

void Imprimir(Personagem personagem) {
	printf(" ## %s", personagem.nome);
	printf(" ## %d", personagem.altura);
	printf(" ## %g", personagem.peso);
	printf(" ## %s", personagem.corDoCabelo);
	printf(" ## %s", personagem.corDaPele);
	printf(" ## %s", personagem.corDosOlhos);
	printf(" ## %s", personagem.anoNascimento);
	printf(" ## %s", personagem.genero);
	printf(" ## %s", personagem.homeworld);
	printf(" ## \n");
}

int main() {
	char* filePath = malloc(50);

	scanf("%s", filePath);

	while (strcmp(filePath, "FIM")) {
		Personagem personagem;
		Construtor(&personagem);

		Ler(&personagem, filePath);
		Imprimir(personagem);

		scanf("%s", filePath);
	}
}

// File Get Pointer String. Equivalente a um fscanf mas para char*. Ótimo para strings em structs - fgetsptr(&string, file);
char* fgetsptr(FILE* file) {
	char* string = malloc(2000);
	fscanf(file, " %[^\n]", string);
	return realloc(string, strlen(string) + 1);
}

char* substr(char* string, int beginning, int end) {
	int length = end - beginning;
	char* strAux = (char*)malloc((length + 1) * sizeof(char));
	if (strAux != NULL) {
		memcpy(strAux, string + beginning, length);
		strAux[length] = '\0';
	}
	return strAux;
}

int indexOf(char* string, char* reference) {
	int refLength = strlen(reference);

	for (int i = 0; i <= strlen(string) - refLength; i++) {
		if (!strcmp(substr(string, i, i + refLength), reference)) {
			return i;
		}
	}

	return -1;
}

char** split(char* string, char* regex) {
	int arraySize = 1;

	// Descobrindo o tamanho do nosso Array
	for (int i = 0; i < strlen(string) - strlen(regex); i++) {
		if (!strcmp(substr(string, i, i + strlen(regex)), regex)) {
			arraySize++;
		}
	}

	// Criando o array de strings
	char** array = (char**)malloc(arraySize * sizeof(char**));

	// Separando as substrings e atribuindo
	for (int i = 0; i < arraySize - 1; i++) {
		array[i] = (char*)malloc((indexOf(string, regex) - 1) * sizeof(char*));
		strcpy(array[i], substr(string, 0, indexOf(string, regex)));
		string += indexOf(string, regex) + strlen(regex);
	}
	array[arraySize - 1] = (char*)malloc((strlen(string) - 1) * sizeof(char*));
	strcpy(array[arraySize - 1], substr(string, 0, strlen(string)));

	return array;
}

char* trim(char* string) {
	if (string[0] == ' ') {
		string++;
	}
	if (string[strlen(string) - 1] == ' ') {
		string[strlen(string) - 1] = '\0';
	}
	return string;
}

char* replaceAll(char* string, char* regex, char* replacement) {
	char* aux = (char*)malloc(2000 * sizeof(char));

	int i = 0, j = 0;
	while (i < strlen(string)) {
		if (!strcmp(substr(string, i, i + strlen(regex)), regex)) {
			strcat(aux, replacement);
			j += strlen(replacement);
			i += strlen(regex);
		} else {
			aux[j] = string[i];
			j++;
			i++;
		}
	}

	aux[strlen(aux) + 1] = '\0';

	return realloc(aux, (strlen(aux) + 1) * sizeof(char));
}