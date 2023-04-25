#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// #define arrayLength(array) ((int)(sizeof(array) / sizeof(array[0])))

#define listSize 70

char* substr(char* jsonString, int beggining, int end);

int indexOf(char* string, char* reference);

char* pstrcpy(char* string);

char* pairs(char* jsonString);

char* Key(char* pair);

char* Value(char* pair, int keyLength);

char* doubleFixer(char* string);

char* fgetsptr(FILE* file);

char* getsptr();

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

Personagem* clone(Personagem personagem) {

	Personagem* clone = (Personagem*)malloc(1 * sizeof(Personagem));

	clone->nome = personagem.nome;
	clone->altura = personagem.altura;
	clone->peso = personagem.peso;
	clone->corDoCabelo = personagem.corDoCabelo;
	clone->corDaPele = personagem.corDaPele;
	clone->corDosOlhos = personagem.corDosOlhos;
	clone->anoNascimento = personagem.anoNascimento;
	clone->genero = personagem.genero;
	clone->homeworld = personagem.homeworld;

	return clone;
}

void Ler(Personagem* personagem, char* filePath) {

	FILE* file = fopen(filePath, "r");

	if (file == NULL) {
		printf("Erro ao abrir o arquivo.\n");
		exit(0);
	}

	char* jsonString = fgetsptr(file);
	fclose(file);

	// Remove as chaves do começo e fim do JSON
	jsonString[strlen(jsonString) - 1] = '\0';
	jsonString++;

	for (int i = 0; i < 9; i++) { // 9
		char* pair = pairs(jsonString);

		// Skippa para o próximo par Key:Value (para a próxima iteração)
		jsonString += strlen(pair) + 2;

		char* key = pstrcpy(Key(pair));
		char* value = pstrcpy(Value(pair, strlen(key)));

		// printf("key: %s\n", key);
		// printf("Value: %s\n", value);

		// printf("CRASHANDO\n");
		// exit(0);

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
				value = doubleFixer(value);
				personagem->peso = strtod(value, NULL);
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
	printf(" ## ");
}

typedef struct Lista Lista;
struct Lista {
	Personagem** array;
	int n;
} lista; // Tentar fazer com que não seja global

void inserirInicio(Personagem personagem) {

	// validar insercao
	if (lista.n >= listSize) {
		printf("Erro ao inserir!");
		exit(1);
	}

	// levar elementos para o fim do array
	for (int i = lista.n; i > 0; i--) {
		lista.array[i] = lista.array[i - 1];
	}

	lista.array[0] = clone(personagem);
	lista.n++;
}

void inserirFim(Personagem personagem) {

	// validar insercao
	if (lista.n >= listSize) {
		printf("Erro ao inserir!");
		exit(1);
	}

	lista.array[lista.n] = clone(personagem);

	lista.n++;
}

void inserir(Personagem personagem, int pos) {

	// validar insercao
	if (lista.n >= listSize || pos < 0 || pos > lista.n) {
		printf("Erro ao inserir!");
		exit(1);
	}

	// levar elementos para o fim do array
	for (int i = lista.n; i > pos; i--) {
		lista.array[i] = lista.array[i - 1];
	}

	lista.array[pos] = clone(personagem);
	lista.n++;
}

Personagem removerInicio() {
	// validar remocao
	if (lista.n == 0) {
		printf("Erro ao remover!");
		exit(1);
	}

	Personagem resp = *lista.array[0];

	lista.n--;

	for (int i = 0; i < lista.n; i++) {
		lista.array[i] = lista.array[i + 1];
	}

	return resp;
}

Personagem removerFim() {

	// validar remocao
	if (lista.n == 0) {
		printf("Erro ao remover!");
		exit(1);
	}

	return *lista.array[--lista.n];
}

Personagem remover(int pos) {
	// validar remocao
	if (lista.n == 0 || pos < 0 || pos >= lista.n) {
		printf("Erro ao remover!");
		exit(1);
	}

	Personagem resp = *lista.array[pos];
	lista.n--;

	for (int i = pos; i < lista.n; i++) {
		lista.array[i] = lista.array[i + 1];
	}

	return resp;
}

// ANCHOR - listaAction
void listaAction(char* string) {

	char* listaAction = substr(string, 0, 2);

	// printf("listaAction: \"%s\"\n", listaAction);

	if (!strcmp(listaAction, "II") || !strcmp(listaAction, "I*") || !strcmp(listaAction, "IF")) {

		Personagem personagem;
		Construtor(&personagem);

		// char* filePath = substr(string, indexOf(string, "/"), strlen(string)); // Alternativa do Verde
		char* filePath = substr(string, indexOf(string, "./"), strlen(string));

		Ler(&personagem, filePath);

		if (!strcmp(listaAction, "II")) {
			inserirInicio(personagem);
		} else if (!strcmp(listaAction, "I*")) {
			int insertionIdex = atoi(substr(string, 3, strlen(string)));
			inserir(personagem, insertionIdex);
		} else {
			inserirFim(personagem);
		}
	} else {
		if (!strcmp(listaAction, "RI")) {
			printf("(R) %s\n", removerInicio().nome);
		} else if (!strcmp(listaAction, "R*")) {
			int removalIdex = atoi(substr(string, 3, strlen(string)));
			printf("(R) %s\n", remover(removalIdex).nome);
		} else {
			printf("(R) %s\n", removerFim().nome);
		}
	}
}

int main() {

	lista.array = (Personagem**)malloc(listSize * sizeof(Personagem*));
	lista.n = 0;

	char* filePath = getsptr();

	while (strcmp(filePath, "FIM")) {
		Personagem personagem;
		Construtor(&personagem);

		Ler(&personagem, filePath);
		// Imprimir(personagem);

		inserirFim(personagem);

		filePath = getsptr();
	}

	// printf("%s\n", lista.array[0]->nome);

	int listaActionsNumber;
	scanf("%d", &listaActionsNumber);

	for (int i = 0; i < listaActionsNumber; i++) {
		listaAction(getsptr());
	}

	for (int i = 0; i < lista.n; i++) {
		printf("[%d] ", i);
		Imprimir(*lista.array[i]);
		if (i < lista.n - 1) printf("%c", '\n');
	}
}

char* substr(char* string, int beggining, int end) {
	char* aux = (char*)malloc((int)strlen(string) * sizeof(char));

	for (int i = 0; i <= end - beggining; i++) {
		aux[i] = string[beggining + i];
	}

	aux[end - beggining] = '\0';

	return (char*)realloc(aux, strlen(aux) + 1);
}

int indexOf(char* string, char* reference) {

	for (int i = 0; i <= strlen(string) - strlen(reference); i++) {
		char* substring = substr(string, i, strlen(reference) + i);

		if (!strcmp(substring, reference)) {
			return i;
		}
	}
	return 0;
}

char* doubleFixer(char* string) {
	char* aux = (char*)malloc(strlen(string) * sizeof(char));

	for (int i = 0, j = 0; i < strlen(string); i++) {
		if (string[i] != ',') {
			aux[j] = string[i];
			aux[i + 1] = '\0';
			j++;
		}
	}
	aux[strlen(string)] = '\0';
	return aux;
}

char* pairs(char* jsonString) {
	for (int i = 0; i < strlen(jsonString); i++) {
		// !strcmp(substr(jsonString, i, i + 1), "',")
		if (jsonString[i] == '\'' && jsonString[i + 1] == ',') {
			return substr(jsonString, 0, i + 1);
		}
	}
}

char* Key(char* pair) {
	char* aux = (char*)malloc(500 * sizeof(char));

	for (int i = 0; i < strlen(pair); i++) {
		if (pair[i] == ':') {
			return substr(pair, 1, i - 1);
		}
	}
}

char* Value(char* pair, int keyLength) {
	int valueStart = keyLength + 5; // Skippa a chave - (+ 5 é pra skippar os espaços e ':' e '`')
	int valueEnd = strlen(pair) - 1; // - 1 para não salvarmos o último '
	return substr(pair, valueStart, valueEnd);
}

// File Get Pointer String. Equivalente a um fscanf mas para char*. Ótimo para strings em structs - fgetsptr(file);
char* fgetsptr(FILE* file) {
	char* string = malloc(2000);
	fscanf(file, " %[^\n]", string);
	return (char*)realloc(string, (strlen(string) + 1) * sizeof(char));
}

// Get Pointer String. Equivalente a um scanf mas para char*. Ótimo para strings em structs - getsptr(p1.nome);
char* getsptr() {
	char* string = malloc(2000);
	scanf(" %[^\n]", string);
	return (char*)realloc(string, (strlen(string) + 1) * sizeof(char));
}

// Pointer String Copy. Equivalente a um strcpy, mas para Pointer Strings. pstrcpy(&string, "New String");
char* pstrcpy(char* string) {

	char* aux = (char*)malloc((int)strlen(string) * sizeof(char));
	strcpy(aux, string);

	return aux;
}