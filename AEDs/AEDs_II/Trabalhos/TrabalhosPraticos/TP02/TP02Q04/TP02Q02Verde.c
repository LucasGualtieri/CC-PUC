#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <string.h>

#define STR_MAX_LEN 500
#define BD_SIZE 3923 // Quantidade Jogadores

typedef const char* const literal;
typedef char* String;

#define MAX_ATTRIBUTES 8

typedef struct Split {
	int size;
	char array[MAX_ATTRIBUTES][STR_MAX_LEN];
} Split;

typedef struct Jogador {

	int id, altura, peso, anoNascimento;
	String nome;
	String universidade;
	String cidadeNascimento;
	String estadoNascimento;

	// Getter e Setter - Id
	int (*getId) (struct Jogador);
	void (*setId) (int id, struct Jogador*);

	// Getter e Setter - Altura
	int (*getAltura) (struct Jogador);
	void (*setAltura) (String altura, struct Jogador*);

	// Getter e Setter - Peso
	int (*getPeso) (struct Jogador);
	void (*setPeso) (String peso, struct Jogador*);

	// Getter e Setter - AnoNascimento
	int (*getAnoNascimento) (struct Jogador);
	void (*setAnoNascimento) (String anoNascimento, struct Jogador*);

	// Getter e Setter - Nome
	String (*getNome) (struct Jogador);
	void (*setNome) (String nome, struct Jogador*);

	// Getter e Setter - Universidade
	String (*getUniversidade) (struct Jogador);
	void (*setUniversidade) (String universidade, struct Jogador*);

	// Getter e Setter - CidadeNascimento
	String (*getCidadeNascimento) (struct Jogador);
	void (*setCidadeNascimento) (String cidadeNascimento, struct Jogador*);

	// Getter e Setter - EstadoNascimento
	String (*getEstadoNascimento) (struct Jogador);
	void (*setEstadoNascimento) (String estadoNascimento, struct Jogador*);

	void (*Construtor) (Split array, struct Jogador*);
	void (*Mostrar) (struct Jogador);
	// void (*Close) (Split array, struct Jogador*);

} Jogador;

// Getter e Setter - Id
int GetIdJogador(Jogador jogador) { return jogador.id; }
void SetIdJogador(int id, Jogador* jogador) { jogador->id = id; }

// Getter e Setter - Altura
int GetAlturaJogador(Jogador jogador) { return jogador.altura; }
void SetAlturaJogador(String altura, Jogador* jogador) {
	if (!strcmp(altura, "(null)")) {
		jogador->altura = -1;
		return;
	}
	jogador->altura = atoi(altura);
}

// Getter e Setter - Peso
int GetPesoJogador(Jogador jogador) { return jogador.peso; }
void SetPesoJogador(String peso, Jogador* jogador) {
	if (!strcmp(peso, "(null)")) {
		jogador->peso = -1;
		return;
	}
	jogador->peso = atoi(peso);
}

// Getter e Setter - AnoNascimento
int GetAnoNascimentoJogador(Jogador jogador) { return jogador.anoNascimento; }
void SetAnoNascimentoJogador(String anoNascimento, Jogador* jogador) {
	if (!strcmp(anoNascimento, "(null)")) {
		jogador->anoNascimento = -1;
		return;
	}
	jogador->anoNascimento = atoi(anoNascimento);
}

// Getter e Setter - Nome
String GetNomeJogador(Jogador jogador) { return jogador.nome; }
void SetNomeJogador(String nome, Jogador* jogador) { jogador->nome = strdup(nome); }

// Getter e Setter - Universidade
String GetUniversidadeJogador(Jogador jogador) { return jogador.universidade; }
void SetUniversidadeJogador(String universidade, Jogador* jogador) { jogador->universidade = strdup(universidade); }

// Getter e Setter - CidadeNascimento
String GetCidadeNascimentoJogador(Jogador jogador) { return jogador.cidadeNascimento; }
void SetCidadeNascimentoJogador(String cidadeNascimento, Jogador* jogador) { jogador->cidadeNascimento = strdup(cidadeNascimento); }

// Getter e Setter - EstadoNascimento
String GetEstadoNascimentoJogador(Jogador jogador) { return jogador.estadoNascimento; }
void SetEstadoNascimentoJogador(String estadoNascimento, Jogador* jogador) { jogador->estadoNascimento = strdup(estadoNascimento); }

void ConstrutorJogador(Split split, Jogador* jogador) {

	jogador->setId(atoi(split.array[0]), jogador);
	jogador->setNome(split.array[1], jogador);
	jogador->setAltura(split.array[2], jogador);
	jogador->setPeso(split.array[3], jogador);
	jogador->setUniversidade(split.array[4], jogador);
	jogador->setAnoNascimento(split.array[5], jogador);
	jogador->setCidadeNascimento(split.array[6], jogador);
	jogador->setEstadoNascimento(split.array[7], jogador);

}

void MostrarJogador(Jogador jogador) {
	printf("[%d ## ", jogador.getId(jogador));
	printf("%s ## ", jogador.getNome(jogador));
	printf("%d ## ", jogador.getAltura(jogador));
	printf("%d ## ", jogador.getPeso(jogador));
	printf("%d ## ", jogador.getAnoNascimento(jogador));
	printf("%s ## ", jogador.getUniversidade(jogador));
	printf("%s ## ", jogador.getCidadeNascimento(jogador));
	printf("%s]\n", jogador.getEstadoNascimento(jogador));
}

void CloseJogador();

Jogador newJogador();

const Jogador ERRO = { -0x7fffffff }; // Setta o Id

typedef struct Fila {

	Jogador *array;
	int maxSize, size;
	bool showOnUpdate;

	void (*Inserir)(Jogador jogador, struct Fila*);
	Jogador (*Remover)(struct Fila*);

	void (*ImportDataBase) (literal filePath, struct Fila*);
	Jogador (*Get) (int id, struct Fila);

	void (*ToggleShow) (struct Fila*);
	void (*Mostrar)(struct Fila);
	void (*Close)(struct Fila*); // Implementar o Jogador.close(); Para dar free nas strings

} Fila;

void InserirFila(Jogador jogador, Fila* fila);

Jogador RemoverFila(Fila* fila);

void ToggleShowOnUpdateFila(Fila* fila);

void MostrarFila(Fila fila);

void CloseFila(Fila* fila);

void ImportDataBaseBD(literal filePath, Fila* BD);

Jogador GetFila(int id, Fila fila) { return fila.array[id]; }

Fila newFila(size_t maxSize);

char* readStr(FILE* stream, String input);
Split newSplit(FILE* CSV, const char* const delimiter);

int main() {

	Fila BD = newFila(BD_SIZE);
	BD.ImportDataBase("/tmp/players.csv", &BD);

	Fila listaJogadores = newFila(40); // Tamanho de entradada do Pub.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		listaJogadores.Inserir(BD.Get(id, BD), &listaJogadores);
		// Dentro do inserir fazer um .clone
	}

	listaJogadores.Mostrar(listaJogadores);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}

char* readStr(FILE* stream, String input) {
	if (!stream) stream = stdin;

	fgets(input, STR_MAX_LEN, stream);
	input[(int)strcspn(input, "\r\n")] = '\0';
	return input;
}

Split newSplit(FILE* CSV) {

	Split split = { 8 }; // Inicializa o size com 1

	char teste[500];
	for (int i = 0; i < MAX_ATTRIBUTES; i++) {
		if (fscanf(CSV, "%[^,\n\r]", teste) == 0) {
			strcpy(split.array[i], "nao informado");
		} else {
			strcpy(split.array[i], teste);
		}
		fgetc(CSV); // Despresando a virgula
	}

	return split;
}

Jogador newJogador() {

	Jogador jogador;

	jogador.getId = GetIdJogador;
	jogador.setId = SetIdJogador;

	jogador.getAltura = GetAlturaJogador;
	jogador.setAltura = SetAlturaJogador;

	jogador.getPeso = GetPesoJogador;
	jogador.setPeso = SetPesoJogador;
	
	jogador.getAnoNascimento = GetAnoNascimentoJogador;
	jogador.setAnoNascimento = SetAnoNascimentoJogador;

	jogador.getNome = GetNomeJogador;
	jogador.setNome = SetNomeJogador;

	jogador.getUniversidade = GetUniversidadeJogador;
	jogador.setUniversidade = SetUniversidadeJogador;

	jogador.getCidadeNascimento = GetCidadeNascimentoJogador;
	jogador.setCidadeNascimento = SetCidadeNascimentoJogador;

	jogador.getEstadoNascimento = GetEstadoNascimentoJogador;
	jogador.setEstadoNascimento = SetEstadoNascimentoJogador;

	jogador.Construtor = ConstrutorJogador;
	jogador.Mostrar = MostrarJogador;

	return jogador;
}

void InserirFila(Jogador jogador, Fila* fila) {

	if (fila->maxSize == 0) {
		fprintf(stderr, "Erro ao inserir: Fila fechada.\n");
		return;
	} else if (fila->size == fila->maxSize) {
		fprintf(stderr, "Erro ao inserir: Fila cheia.\n");
		return;
	}

	fila->array[fila->size++] = jogador;

	if (fila->showOnUpdate) fila->Mostrar(*fila);

}

Jogador RemoverFila(Fila* fila) {

	// Em hexadecimal, cada dígito pode representar 4 bits.
	if (fila->maxSize == 0) {
		fprintf(stderr, "Erro ao remover: Fila fechada.\n");
		return ERRO;
	} else if (fila->size == 0) {
		fprintf(stderr, "Erro ao remover: Fila vazia.\n");
		return ERRO;
	}

	Jogador removido = fila->array[0];

	for (int i = 0; i < fila->size - 1; i++) {
		fila->array[i] = fila->array[i + 1];
	}

	fila->size--;

	if (fila->showOnUpdate) fila->Mostrar(*fila);

	return removido;
}

void ToggleShowOnUpdateFila(Fila* fila) {
	fila->showOnUpdate = fila->showOnUpdate ? false : true;
}

void MostrarFila(Fila fila) {

	// listaJogadores.printPlayer(id, BD); // Loopar pelo id

	if (fila.maxSize == 0) {
		fprintf(stderr, "Erro ao mostrar: Fila fechada.\n");
		return;
	} else if (fila.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Fila vazia.\n");
		return;
	}

	for (int i = 0; i < fila.size; i++) {
		fila.array[i].Mostrar(fila.array[i]);
	}
}

void CloseFila(Fila* fila) {
	free(fila->array);
	// For pra dar free em todos os jogadores
	fila->maxSize = 0;
}

void ImportDataBaseBD(literal filePath, Fila* BD) {

	// printf("filePath: %s\n", filePath);

	FILE* CSV;

	if (!(CSV = fopen(filePath, "r"))) {
		printf("Erro: Falha ao abrir players.csv\n");
		exit(0);
	}

	char inputCSV[STR_MAX_LEN];
	readStr(CSV, inputCSV); // Despresando o header do .csv
	
	while (!feof(CSV)) {

		// printf("inputCSV: %s\n", inputCSV);

		// No estado atual o split retorna uma possível linha vazia quando o arquivo tem uma linha vazia no final
		Split array = newSplit(CSV);
		Jogador jogador = newJogador();

		jogador.Construtor(array, &jogador);
		BD->Inserir(jogador, BD);

		// jogador.Mostrar(jogador);
	}
}

Fila newFila(size_t maxSize) {

	Fila fila;

	if (maxSize == 0) maxSize = 80;

	fila.size = 0;
	fila.maxSize = maxSize;
	fila.array = (Jogador*)malloc(maxSize * sizeof(Jogador));
	fila.showOnUpdate = false;

	fila.Inserir = InserirFila;
	fila.Remover = RemoverFila;

	fila.ImportDataBase = ImportDataBaseBD;
	fila.Get = GetFila;

	fila.ToggleShow = ToggleShowOnUpdateFila;
	fila.Mostrar = MostrarFila;
	fila.Close = CloseFila;

	return fila;
}