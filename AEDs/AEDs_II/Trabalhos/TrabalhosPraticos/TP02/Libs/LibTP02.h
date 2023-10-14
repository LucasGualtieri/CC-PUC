#ifndef LIB_TP02_H
#define LIB_TP02_H

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// --------------------------- FUNÇÕES E DEFINIÇÕES AUXILIARES ---------------------------

#define STR_MAX_LEN 80
#define BD_SIZE 3923 // Quantidade Jogadores

typedef const char* const literal;
typedef char* String;

char* readStr(FILE* stream, String input) {
	if (!stream) stream = stdin;

	fgets(input, STR_MAX_LEN, stream);
	input[(int)strcspn(input, "\n")] = '\0';
	return input;
}

// --------------------------- CLASSE SPLIT ---------------------------

#define MAX_ATTRIBUTES 8

typedef struct Split {
	char array[MAX_ATTRIBUTES][STR_MAX_LEN];
} Split;

Split newSplit(FILE* CSV) {

	Split split; // Inicializa o size com 8

	for (int i = 0; i < MAX_ATTRIBUTES; i++) {
		if (fscanf(CSV, "%[^,\n]", split.array[i]) == 0) {
			strcpy(split.array[i], "nao informado");
		}
		fgetc(CSV); // Despresando a virgula
	}

	return split;
}

// --------------------------- CLASSE TIMER ---------------------------

typedef struct Timer {
	clock_t startTime;
	clock_t endTime;
	double totalTime;
	void (*Start)(struct Timer*);
	void (*Stop)(struct Timer*);
	double (*Time)(struct Timer*);
} Timer;

void TimerStart(Timer* timer) {
	timer->startTime = clock();
}

void TimerStop(Timer* timer) {
	timer->endTime = clock();
}

double TimerTime(Timer* timer) {
	timer->totalTime = ((double)(timer->endTime - timer->startTime)) / CLOCKS_PER_SEC;
	return timer->totalTime;
}

Timer newTimer() {
	Timer timer;
	timer.Start = TimerStart;
	timer.Stop = TimerStop;
	timer.Time = TimerTime;
	return timer;
}

// --------------------------- CLASSE LOG ---------------------------

typedef struct Log {
	int comparacoes, movimentacoes;
	void (*RegistroPesquisa) (literal fileName, Timer, struct Log);
	void (*RegistroOrdenacao) (literal fileName, Timer, struct Log);
} Log;

void RegistroPesquisa(literal fileName, Timer timer, Log log) {
	FILE* file = fopen(fileName, "w");

	fprintf(file, "Matrícula: 794989\t");
	fprintf(file, "Tempo de execução: %fs\t", timer.Time(&timer));
	fprintf(file, "Número de comparações: %d", log.comparacoes);

	fclose(file);
}

void RegistroOrdenacao(literal fileName, Timer timer, Log log) {
	FILE* file = fopen(fileName, "w");

	fprintf(file, "Matrícula: 794989\t");
	fprintf(file, "Tempo de execução: %fs\t", timer.Time(&timer));
	fprintf(file, "Número de comparações: %d\t", log.comparacoes);
	fprintf(file, "Número de movimentações: %d", log.movimentacoes);

	fclose(file);
}

Log newLog() {
	Log log = { 0, 0 };
	log.RegistroPesquisa = RegistroPesquisa;
	log.RegistroOrdenacao = RegistroOrdenacao;
	return log;
}

// --------------------------- CLASSE JOGADOR ---------------------------

typedef struct Jogador {

	void* atributo;
	int id, altura, peso, anoNascimento;
	String nome;
	String universidade;
	String cidadeNascimento;
	String estadoNascimento;

	// Setter - Id
	void (*setId) (int id, struct Jogador*);

	// Setter - Altura
	void (*setAltura) (int altura, struct Jogador*);

	// Setter - Peso
	void (*setPeso) (int peso, struct Jogador*);

	// Setter - AnoNascimento
	void (*setAnoNascimento) (int anoNascimento, struct Jogador*);

	// Setter - Nome
	void (*setNome) (String nome, struct Jogador*);

	// Setter - Universidade
	void (*setUniversidade) (String universidade, struct Jogador*);

	// Setter - CidadeNascimento
	void (*setCidadeNascimento) (String cidadeNascimento, struct Jogador*);

	// Setter - EstadoNascimento
	void (*setEstadoNascimento) (String estadoNascimento, struct Jogador*);

	void (*Construtor) (Split, struct Jogador*);
	struct Jogador (*Clone) (struct Jogador);
	void (*Mostrar) (struct Jogador);
	void (*Close) (struct Jogador);

} Jogador;

// Setter - Id
void SetIdJogador(int id, Jogador* jogador) {
	jogador->id = id;
}

// Setter - Nome
void SetNomeJogador(String nome, Jogador* jogador) {
	jogador->nome = strdup(nome);
}

// Setter - Altura
void SetAlturaJogador(int altura, Jogador* jogador) {
	jogador->altura = altura;
}

// Setter - Peso
void SetPesoJogador(int peso, Jogador* jogador) {
	jogador->peso = peso;
}

// Setter - AnoNascimento
void SetAnoNascimentoJogador(int anoNascimento, Jogador* jogador) {
	jogador->anoNascimento = anoNascimento;
}

// Setter - Universidade
void SetUniversidadeJogador(String universidade, Jogador* jogador) {
	jogador->universidade = strdup(universidade);
}

// Setter - CidadeNascimento
void SetCidadeNascimentoJogador(String cidadeNascimento, Jogador* jogador) {
	jogador->cidadeNascimento = strdup(cidadeNascimento);
}

// Setter - EstadoNascimento
void SetEstadoNascimentoJogador(String estadoNascimento, Jogador* jogador) {
	jogador->estadoNascimento = strdup(estadoNascimento);
}

void ConstrutorJogador(Split split, Jogador* jogador) {

	jogador->setId(atoi(split.array[0]), jogador);
	jogador->setNome(split.array[1], jogador);
	jogador->setAltura(atoi(split.array[2]), jogador);
	jogador->setPeso(atoi(split.array[3]), jogador);
	jogador->setUniversidade(split.array[4], jogador);
	jogador->setAnoNascimento(atoi(split.array[5]), jogador);
	jogador->setCidadeNascimento(split.array[6], jogador);
	jogador->setEstadoNascimento(split.array[7], jogador);

}

Jogador CloneJogador(Jogador jogador) {

	Jogador clone = jogador;

	clone.setNome(jogador.nome, &clone);
	clone.setUniversidade(jogador.universidade, &clone);
	clone.setCidadeNascimento(jogador.cidadeNascimento, &clone);
	clone.setEstadoNascimento(jogador.estadoNascimento, &clone);

	return clone;

}

void MostrarJogador(Jogador jogador) {

	printf("[%d ## ", jogador.id);
	printf("%s ## ", jogador.nome);
	printf("%d ## ", jogador.altura);
	printf("%d ## ", jogador.peso);
	printf("%d ## ", jogador.anoNascimento);
	printf("%s ## ", jogador.universidade);
	printf("%s ## ", jogador.cidadeNascimento);
	printf("%s]\n", jogador.estadoNascimento);

}

void CloseJogador(Jogador jogador) {

	free(jogador.nome);
	free(jogador.universidade);
	free(jogador.cidadeNascimento);
	free(jogador.estadoNascimento);

}

Jogador newJogador() {

	Jogador jogador;

	jogador.setId = SetIdJogador;
	jogador.setAltura = SetAlturaJogador;
	jogador.setPeso = SetPesoJogador;
	jogador.setAnoNascimento = SetAnoNascimentoJogador;
	jogador.setNome = SetNomeJogador;
	jogador.setUniversidade = SetUniversidadeJogador;
	jogador.setCidadeNascimento = SetCidadeNascimentoJogador;
	jogador.setEstadoNascimento = SetEstadoNascimentoJogador;

	jogador.Construtor = ConstrutorJogador;
	jogador.Clone = CloneJogador;

	jogador.Mostrar = MostrarJogador;
	jogador.Close = CloseJogador;

	return jogador;
}

// --------------------------- CLASSE LISTA ---------------------------

typedef struct Lista {

	Jogador *array;
	int maxSize, size;
	bool showOnUpdate;

	void (*Inserir) (Jogador, struct Lista*);

	void (*setAtributo) (void* atributo, struct Lista lista);
	bool (*CompareToInt) (Jogador jog1, Jogador jog2, Log* log);
	int (*CompareToStr) (Jogador jog1, Jogador jog2, Log* log);
	void (*SortByNome) (struct Lista);

	void (*ImportDataBase) (literal filePath, struct Lista*);
	Jogador (*Get) (int id, struct Lista);

	void (*Mostrar) (struct Lista);
	void (*MostrarParcial) (int k, struct Lista);
	void (*Close) (struct Lista*);

} Lista;

void InserirLista(Jogador jogador, Lista* lista) {

	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao inserir: Lista cheia.\n");
		return;
	}

	lista->array[lista->size++] = jogador.Clone(jogador);

}

void swap(Jogador* jog1, Jogador* jog2, Log* log) {
	Jogador aux = *jog1;
	*jog1 = *jog2;
	*jog2 = aux;
	log->movimentacoes += 3;
}

void SortByNomeLista(Lista lista) {

	Log log;
	int N = lista.size;
	Jogador* array = lista.array;

	for (int i = 0; i < N - 1; i++) {
		int menor = i;
		for (int j = i + 1; j < N; j++) {
			if (strcmp(array[menor].nome, array[j].nome) > 0) {
				menor = j;
			}
		}
		swap(&array[i], &array[menor], &log);
	}

}

void setAtributoLista(void* atributo, Lista lista) {
	lista.array[lista.size - 1].atributo = atributo;
}

#define vint(var) *((int*)var) // Void to int

bool CompareToIntLista(Jogador jog1, Jogador jog2, Log* log) {

	log->comparacoes += 2;
	if (vint(jog1.atributo) != vint(jog2.atributo)) {
		return vint(jog1.atributo) > vint(jog2.atributo);
	} else {
		return strcmp(jog1.nome, jog2.nome) > 0;
	}
}

int CompareToStrLista(Jogador jog1, Jogador jog2, Log* log) {

	log->comparacoes++;
	int strComp = strcmp(jog1.atributo, jog2.atributo);

	if (strComp == 0) {
		log->comparacoes++;
		strComp = strcmp(jog1.nome, jog2.nome);
	}

	return strComp;
}

void MostrarLista(Lista lista) {

	if (lista.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Lista vazia.\n");
		return;
	}

	for (int i = 0; i < lista.size; i++) {
		lista.array[i].Mostrar(lista.array[i]);
	}
}

void MostrarParcialLista(int k, Lista lista) {

	if (lista.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Lista vazia.\n");
		return;
	}

	for (int i = 0; i < k; i++) {
		lista.array[i].Mostrar(lista.array[i]);
	}
}

void CloseLista(Lista* lista) {
	
	for (int i = 0; i < lista->size; i++) {
		lista->array[i].Close(lista->array[i]);
	}

	free(lista->array);
	
	lista->maxSize = 0;
}

void ImportDataBaseBD(literal filePath, Lista* BD) {

	FILE* CSV;
	if (!(CSV = fopen(filePath, "r"))) {
		printf("Erro: Falha ao abrir players.csv\n");
		exit(0);
	}

	char inputCSV[STR_MAX_LEN];
	readStr(CSV, inputCSV); // Despresando o header do .csv
	
	Jogador jogador;

	while (!feof(CSV)) {

		Split array = newSplit(CSV);

		jogador = newJogador();
		jogador.Construtor(array, &jogador);

		BD->Inserir(jogador, BD);

	}

}

Jogador GetLista(int id, Lista lista) { return lista.array[id]; }

Lista newLista(size_t maxSize) {

	Lista lista;

	if (maxSize == 0) maxSize = 80;

	lista.size = 0;
	lista.maxSize = maxSize;
	lista.array = (Jogador*)malloc(maxSize * sizeof(Jogador));

	lista.Inserir = InserirLista;

	lista.setAtributo = setAtributoLista;
	lista.CompareToInt = CompareToIntLista;
	lista.CompareToStr = CompareToStrLista;
	lista.SortByNome = SortByNomeLista;

	lista.ImportDataBase = ImportDataBaseBD;
	lista.Get = GetLista;

	lista.Mostrar = MostrarLista;
	lista.MostrarParcial = MostrarParcialLista;
	lista.Close = CloseLista;

	return lista;
}

#endif