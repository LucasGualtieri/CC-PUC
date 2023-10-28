#ifndef LIB_TP02_H
#define LIB_TP02_H

#include <err.h>
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

int readInt() {
	int integer;
	scanf("%d%*c", &integer);
	return integer;
}

// --------------------------- CLASSE SPLIT ---------------------------

#define MAX_ATTRIBUTES 8

typedef struct Split {
	char array[MAX_ATTRIBUTES][STR_MAX_LEN];
} Split;

Split newSplit(FILE* CSV) {

	Split split;

	for (int i = 0; i < MAX_ATTRIBUTES; i++) {
		if (fscanf(CSV, "%[^,\n]", split.array[i]) == 0) {
			strcpy(split.array[i], "nao informado");
		}
		fgetc(CSV); // Despresando a virgula
	}

	return split;
}

Split splitSpace() {

	Split split;

	for (int i = 0; i < 3; i++) {
		scanf("%[^ \n]", split.array[i]);
		if (getchar() == '\n') i = 3;
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

	// printf("[%d ## ", jogador.id);
	printf("%s ## ", jogador.nome);
	printf("%d ## ", jogador.altura);
	printf("%d ## ", jogador.peso);
	printf("%d ## ", jogador.anoNascimento);
	printf("%s ## ", jogador.universidade);
	printf("%s ## ", jogador.cidadeNascimento);
	printf("%s ##\n", jogador.estadoNascimento);

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

	Jogador (*Get) (int id, struct Lista);
	void (*ImportDataBase) (literal filePath, struct Lista*);
	void (*Mostrar) (struct Lista);

	void (*InserirInicio) (Jogador, struct Lista*);
	void (*InserirFim) (Jogador, struct Lista*);
	void (*Inserir) (String pos, Jogador, struct Lista*);
	Jogador (*RemoverInicio) (struct Lista*);
	Jogador (*RemoverFim) (struct Lista*);
	Jogador (*Remover) (String pos, struct Lista*);

	void (*Close) (struct Lista*);

} Lista;

Jogador GetLista(int id, Lista lista) { return lista.array[id]; }

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

		BD->InserirFim(jogador, BD);

	}

}

void MostrarLista(Lista lista) {

	if (lista.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Lista vazia.\n");
		return;
	}

	for (int i = 0; i < lista.size; i++) {
		printf("[%d] ## ", i);
		lista.array[i].Mostrar(lista.array[i]);
	}
}

// ---------------------- INSERÇÕES E REMOÇÕES ----------------------

void InserirInicioLista(Jogador jogador, Lista* lista) {

	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao inserir: Lista cheia.\n");
		return;
	}

	Jogador* array = lista->array;

	for (int i = lista->size; i > 0; i--) array[i] = array[i - 1];

	array[0] = jogador.Clone(jogador);

	lista->size++;

}

void InserirFimLista(Jogador jogador, Lista* lista) {

	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao inserir: Lista cheia.\n");
		return;
	}

	lista->array[lista->size++] = jogador.Clone(jogador);

}

void InserirLista(String posStr, Jogador jogador, Lista* lista) {

	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao inserir: Lista cheia.\n");
		return;
	}

	Jogador* array = lista->array;
	int pos = atoi(posStr);

	for (int i = lista->size; i > pos; i--) array[i] = array[i - 1];

	array[pos] = jogador.Clone(jogador);

	lista->size++;

}

Jogador RemoverInicioLista(Lista* lista) {
	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao remover: Lista vazia.\n");
		exit(0);
	}

	Jogador* array = lista->array;

	Jogador removido = array[0].Clone(array[0]);

	for (int i = 0; i < lista->size - 1; i++) array[i] = array[i + 1];

	lista->size--;

	return removido;
}

Jogador RemoverFimLista(Lista* lista) {
	if (lista->size == 0) {
		fprintf(stderr, "Erro ao remover: Lista vazia.\n");
		exit(0);
	}

	return lista->array[--lista->size];
}

Jogador RemoverLista(String posStr, Lista* lista) {
	if (lista->size == 0) {
		fprintf(stderr, "Erro ao remover: Lista vazia.\n");
		exit(0);
	}

	Jogador* array = lista->array;

	int pos = atoi(posStr);
	Jogador removido = array[pos];

	for (int i = pos; i < lista->size - 1; i++) array[i] = array[i + 1];

	lista->size--;

	return removido;
}


void CloseLista(Lista* lista) {
	
	for (int i = 0; i < lista->size; i++) {
		lista->array[i].Close(lista->array[i]);
	}

	free(lista->array);
	
	lista->maxSize = lista->size = 0;
}

Lista newLista(size_t maxSize) {

	Lista lista;

	if (maxSize == 0) maxSize = 80;

	lista.size = 0;
	lista.maxSize = maxSize;
	lista.array = (Jogador*)malloc(maxSize * sizeof(Jogador));

	lista.Get = GetLista;
	lista.ImportDataBase = ImportDataBaseBD;
	lista.Mostrar = MostrarLista;

	lista.InserirInicio = InserirInicioLista;
	lista.InserirFim = InserirFimLista;
	lista.Inserir = InserirLista;
	lista.RemoverInicio = RemoverInicioLista;
	lista.RemoverFim = RemoverFimLista;
	lista.Remover = RemoverLista;

	lista.Close = CloseLista;

	return lista;
}

// --------------------------- CLASSE FILA CIRCULAR ---------------------------

typedef struct FilaCircular {

	Jogador *array;
	int primeiro, ultimo;
	int size, maxSize;

	float (*getMediaAlturas) (struct FilaCircular);
	void (*Mostrar) (struct FilaCircular);

	float (*Inserir) (Jogador, struct FilaCircular*);
	Jogador (*Remover) (struct FilaCircular*);

	void (*Close) (struct FilaCircular*);

} FilaCircular;

float GetMediaAlturasFilaCircular(FilaCircular fila) {
	float media = 0;
	int jogador = fila.primeiro;
	for (int i = 0; i < fila.size; i++) {
		media += fila.array[jogador].altura;
		jogador = (jogador + 1) % fila.maxSize;
	}
	return media / fila.size;
}

void MostrarFilaCircular(FilaCircular fila) {

	if (fila.primeiro == fila.ultimo) {
		fprintf(stderr, "Erro ao mostrar: FilaCircular vazia.\n");
		return;
	}

	for (int i = 0, jogador = fila.primeiro; i < fila.size; i++) {
		printf("[%d] ## ", i);
		fila.array[i].Mostrar(fila.array[jogador]);
		jogador = (jogador + 1) % fila.maxSize;
	}
}

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

Jogador RemoverFilaCircular(FilaCircular* fila);

float InserirFilaCircular(Jogador jogador, FilaCircular* fila) {

	if ((fila->ultimo + 1) % fila->maxSize == fila->primeiro) {
		jogador.Close(fila->Remover(fila));
	}

	fila->size++;
	fila->array[fila->ultimo] = jogador.Clone(jogador);
	fila->ultimo = (fila->ultimo + 1) % fila->maxSize;

	return fila->getMediaAlturas(*fila);

}

Jogador RemoverFilaCircular(FilaCircular* fila) {

	if (fila->primeiro == fila->ultimo) {
		fprintf(stderr, "Erro ao remover: Pilha Circular vazia.\n");
		exit(0);
	}

	Jogador removido = fila->array[fila->primeiro];

	fila->size--;
	fila->primeiro = (fila->primeiro + 1) % fila->maxSize;

	return removido;
}

void CloseFilaCircular(FilaCircular* fila) {
	
	for (int i = 0, jogador = fila->primeiro; i < fila->size; i++) {
		fila->array[jogador].Close(fila->array[jogador]);
		jogador = (jogador + 1) % fila->maxSize;
	}

	free(fila->array);

	fila->maxSize = fila->size = 0;
}

FilaCircular newFilaCircular(size_t maxSize) {

	FilaCircular fila;

	if (maxSize == 0) maxSize = 80;

	fila.size = fila.primeiro = fila.ultimo = 0;
	fila.maxSize = maxSize + 1;
	fila.array = (Jogador*)malloc((maxSize + 1) * sizeof(Jogador));

	fila.getMediaAlturas = GetMediaAlturasFilaCircular;
	fila.Mostrar = MostrarFilaCircular;

	fila.Inserir = InserirFilaCircular;
	fila.Remover = RemoverFilaCircular;

	fila.Close = CloseFilaCircular;

	return fila;
}

// --------------------------- CLASSE CELULA ---------------------------

typedef struct Celula {
	Jogador jogador;
	struct Celula *prox, *baixo;
	void (*Close) (struct Celula*);
} Celula;

void CloseCelula(Celula* celula) {
	celula->jogador.Close(celula->jogador);
	free(celula);
}

Celula* newCelula(Jogador jogador, Celula* prox) {
	Celula* celula = malloc(sizeof(Celula));
	celula->jogador = jogador.Clone(jogador);
	celula->prox = prox;
	celula->baixo = prox;
	celula->Close = CloseCelula;
	return celula;
}

// --------------------------- CLASSE FILA FLEX ---------------------------

typedef struct FilaFlex {

	Celula *primeiro, *ultimo;
	int size, maxSize;

	float (*getMediaAlturas) (struct FilaFlex);
	void (*Mostrar) (struct FilaFlex);

	float (*Inserir) (Jogador, struct FilaFlex*);
	Jogador (*Remover) (struct FilaFlex*);

	void (*Close) (struct FilaFlex*);

} FilaFlex;

float GetMediaAlturasFilaFlex(FilaFlex fila) {
	float media = 0;
	for (Celula* i = fila.primeiro; i != NULL; i = i->prox) {
		media += i->jogador.altura;
	}
	return media / fila.size;
}

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

float InserirFilaFlex(Jogador jogador, FilaFlex* fila) {

	if (fila->size == fila->maxSize) { jogador.Close(fila->Remover(fila)); }

	if (fila->size == 0) fila->primeiro = fila->ultimo = newCelula(jogador, NULL);
	else fila->ultimo = fila->ultimo->prox = newCelula(jogador, NULL);
	fila->size++;

	return fila->getMediaAlturas(*fila);

}

Jogador RemoverFilaFlex(FilaFlex* fila) {

	if (fila->size == 0) {
		fprintf(stderr, "Erro ao remover: Fila Flex vazia.\n");
		exit(0);
	}

	fila->size--;
	Celula* removida = fila->primeiro;
	fila->primeiro = removida->prox;
	Jogador removido = removida->jogador.Clone(removida->jogador);
	removida->Close(removida);

	return removido;

}

void MostrarFilaFlex(FilaFlex fila) {
	if (fila.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Fila Flex vazia.\n");
		exit(0);
	}

	int contador = 0;
	for (Celula* i = fila.primeiro; i != NULL; i = i->prox) {
		printf("[%d] ## ", contador++);
		i->jogador.Mostrar(i->jogador);
	}

}

void CloseFilaFlex(FilaFlex* fila) {
	
	Celula* i = fila->primeiro;
	while (i != NULL) {
		Celula* tmp = i;
		i = i->prox;
		tmp->Close(tmp);
	}

	fila->maxSize = fila->size = 0;
}

FilaFlex newFilaFlex(size_t maxSize) {

	FilaFlex fila;

	if (maxSize == 0) maxSize = 80;

	fila.size = 0;
	fila.primeiro = fila.ultimo = NULL;
	fila.maxSize = maxSize;

	fila.getMediaAlturas = GetMediaAlturasFilaFlex;
	fila.Mostrar = MostrarFilaFlex;

	fila.Inserir = InserirFilaFlex;
	fila.Remover = RemoverFilaFlex;

	fila.Close = CloseFilaFlex;

	return fila;
}

// --------------------------- CLASSE PILHA FLEX ---------------------------

typedef struct PilhaFlex {

	Celula *topo;
	int size;

	void (*Mostrar) (struct PilhaFlex);

	void (*Inserir) (Jogador, struct PilhaFlex*);
	Jogador (*Remover) (struct PilhaFlex*);

	void (*Close) (struct PilhaFlex*);

} PilhaFlex;

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

void InserirPilhaFlex(Jogador jogador, PilhaFlex* pilha) {
	pilha->topo = newCelula(jogador, pilha->topo);
	pilha->size++;
}

Jogador RemoverPilhaFlex(PilhaFlex* pilha) {

	if (pilha->topo == NULL) {
		fprintf(stderr, "Erro ao remover: Pilha Flex vazia.\n");
		exit(0);
	}

	pilha->size--;
	Celula* removida = pilha->topo;
	pilha->topo = removida->baixo;
	Jogador removido = removida->jogador.Clone(removida->jogador);
	removida->Close(removida);

	return removido;

}

void MostrarPilhaFlexRec(int contador, Celula* i) {
	if (i->baixo != NULL) MostrarPilhaFlexRec(contador - 1, i->baixo);
	printf("[%d] ## ", contador);
	i->jogador.Mostrar(i->jogador);
}

void MostrarPilhaFlex(PilhaFlex pilha) {

	if (pilha.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Pilha Flex vazia.\n");
		exit(0);
	}

	MostrarPilhaFlexRec(pilha.size - 1, pilha.topo);

}

void ClosePilhaFlex(PilhaFlex* pilha) {
	
	Celula* i = pilha->topo;
	while (i != NULL) {
		Celula* tmp = i;
		i = i->prox;
		tmp->Close(tmp);
	}

	pilha->size = 0;

}

PilhaFlex newPilhaFlex() {

	PilhaFlex pilha;

	pilha.size = 0;
	pilha.topo = NULL;

	pilha.Mostrar = MostrarPilhaFlex;

	pilha.Inserir = InserirPilhaFlex;
	pilha.Remover = RemoverPilhaFlex;

	pilha.Close = ClosePilhaFlex;

	return pilha;
}

#endif