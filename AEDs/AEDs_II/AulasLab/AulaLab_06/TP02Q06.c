#include <biblioteca_c.h>

// clear && gcc TP02Q06.c -o TP02Q06 && ./TP02Q06 < pub.in > out.txt

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

	Personagem* clone = (Personagem*)malloc(sizeof(Personagem));

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
	jsonString = replaceAll(jsonString, "{", "");
	jsonString = replaceAll(jsonString, "}", "");

	char** pairs = split(jsonString, "', ");
	int sizeOfPairs = 9;
	printf("%s\n", pairs[1]);

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

typedef struct Lista Lista;
struct Lista {
	Personagem** array;
	int primeiro, ultimo;
	int arraySize;
} lista; // Tentar fazer com que não seja global

char* remover() {
	if (lista.primeiro == lista.ultimo) {
		printf("Erro ao remover!\n");
	}

	int index = lista.primeiro;

	lista.primeiro = (lista.primeiro + 1) % lista.arraySize;

	return lista.array[index]->nome;
}

void calculaMedia() {
	int i = lista.primeiro;
	int contador = 0;
	double soma = 0;

	while (i != lista.ultimo) {
		soma += lista.array[i]->altura;
		contador++;
		i = (i + 1) % lista.arraySize;
	}

	double x = soma / contador;
	double result = (x - floor(x) == 0.5) ? ceil(x) : round(x);

	printf("%.0f\n", result);
}

void inserir(Personagem personagem) {
	if (((lista.ultimo + 1) % lista.arraySize) == lista.primeiro) {
		remover();
	}

	lista.array[lista.ultimo] = clone(personagem);

	lista.ultimo = (lista.ultimo + 1) % lista.arraySize;

	calculaMedia();
}

// ANCHOR - listaAction
void listaAction(char* string) {

	char* listaAction = substr(string, 0, 1);
	// printf("listaAction: \"%s\"\n", listaAction);

	if (!strcmp(listaAction, "I")) {

		Personagem personagem;
		Construtor(&personagem);

		char* filePath = substr(string, indexOf(string, "/"), strlen(string)); // Alternativa do Verde
		// char* filePath = substr(string, indexOf(string, "./"), strlen(string)); // Alternativa do Verde

		Ler(&personagem, filePath);

		inserir(personagem);
	} else if (!strcmp(listaAction, "R")) {
		printf("(R) %s\n", remover());
	}
}

int main() {
	lista.arraySize = 6;
	lista.array = (Personagem**)malloc(lista.arraySize * sizeof(Personagem*));

	char* filePath = getstr(0);

	while (strcmp(filePath, "FIM")) {
		Personagem personagem;
		Construtor(&personagem);

		Ler(&personagem, filePath);
		Imprimir(personagem);

		// inserir(personagem);
		scanf("%s", filePath);
	}

	// int listaActionsNumber;
	// scanf("%d", &listaActionsNumber);

	// for (int i = 0; i < listaActionsNumber; i++) {
	// 	listaAction(getsptr());
	// }
}