#include <err.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// ===================================================================
// ----------------- FUNÇÕES E DEFINIÇÕES AUXILIARES -----------------
// ===================================================================

#define STR_MAX_LEN 80
#define BD_SIZE 3923 // Quantidade Jogadores

typedef const char* const literal;
typedef char* String;

char* readStr(FILE* stream, String input) {
	if (!stream) stream = stdin;

	// fgets(input, STR_MAX_LEN, stream);
	// input[(int)strcspn(input, "\n")] = '\0';

	int x = fscanf(stream, "%[^\n]", input);
	if (x == 0) strcpy(input, "FIM");
	else fgetc(stream);

	// printf("x: %d\n", x);
	// printf("input: %s\n", input);
	// printf("strlen(input): %d\n", (int)strlen(input));

	return input;
}

int readInt() {
	int integer;
	scanf("%d%*c", &integer);
	return integer;
}

// ====================================================================
// --------------------------- CLASSE SPLIT ---------------------------
// ====================================================================

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

// ====================================================================
// --------------------------- CLASSE TIMER ---------------------------
// ====================================================================

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

// ==================================================================
// --------------------------- CLASSE LOG ---------------------------
// ==================================================================

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

// ======================================================================
// --------------------------- CLASSE JOGADOR ---------------------------
// ======================================================================

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

	if (!jogador.nome) free(jogador.nome);
	if (!jogador.universidade) free(jogador.universidade);
	if (!jogador.cidadeNascimento) free(jogador.cidadeNascimento);
	if (!jogador.estadoNascimento) free(jogador.estadoNascimento);
}

void swap(Jogador* jog1, Jogador* jog2, Log* log) {
	Jogador aux = *jog1;
	*jog1 = *jog2;
	*jog2 = aux;
	log->movimentacoes += 3;
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

// ======================================================================
// --------------------------- CLASSE BD ---------------------------
// ======================================================================

typedef struct BD {

	Jogador *array;
	int maxSize, size;
	bool ordenado;

	Jogador (*Get) (int id, struct BD);
	void (*ImportDataBase) (literal filePath, struct BD*);

	void (*OrdenarPorNome) (struct BD*);
	Jogador (*PesquisarPorNome) (String, Log*, struct BD);
	void (*Mostrar) (struct BD);
	void (*Inserir) (Jogador, struct BD*);


	void (*Close) (struct BD*);

} BD;

Jogador GetBD(int id, BD BD) { return BD.array[id]; }

int CompareToStr(int pos, String pivot, BD BD) {
	return strcmp(BD.array[pos].nome, pivot);
}

int CompareToNome(String str, Jogador jog, Log* log) {
	log->comparacoes++;
	return strcmp(str, jog.nome);
}

void QuickSort(int left, int right, Log* log, BD BD) {

	int i = left, j = right;
	Jogador pivot = BD.array[(right + left) / 2];

	while (i <= j) {
		while (CompareToStr(i, pivot.nome, BD) < 0) i++;
		while (CompareToStr(j, pivot.nome, BD) > 0) j--;
		if (i <= j) swap(&BD.array[i++], &BD.array[j--], log);
	}

	if (left < j)  QuickSort(left, j, log, BD);
	if (i < right)  QuickSort(i, right, log, BD);
}

void OrdenarPorNomeBD(BD* BD) {
	BD->ordenado = true;
	Log log = newLog();
	QuickSort(0, BD->size - 1, &log, *BD);
}

Jogador PesquisarPorNomeBinario(String nome, Log* log, BD BD) {
	Jogador pesquisado;
	int	esquerda = 0, direita = BD.size - 1, meio;
	
	while (esquerda <= direita) {

		meio = (esquerda + direita) / 2;
		pesquisado = BD.array[meio];

		if (CompareToNome(nome, pesquisado, log) < 0) {
			direita = meio - 1;
		} else if (CompareToNome(nome, pesquisado, log) > 0) {
			esquerda = meio + 1;
		} else {
			esquerda = direita + 1;
		}
	}

	return pesquisado;
}

Jogador PesquisarPorNomeBD(String nome, Log* log, BD BD) {
	Jogador pesquisado;

	if (BD.ordenado) {
		pesquisado = PesquisarPorNomeBinario(nome, log, BD);
	} else {
		// pesquisado = PesquisarPorNomeSequencial(nome);
	}

	return pesquisado;
}

void MostrarBD(BD BD) {
	for (int i = 0; i < BD.size; i++) {
		printf("%d - %s\n", i + 1, BD.array[i].nome);
	}
}

void ImportDataBaseBD(literal filePath, BD* BD) {

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

void InserirBD(Jogador jogador, BD* BD) {

	if (BD->size == BD->maxSize) {
		fprintf(stderr, "Erro ao inserir: Banco De Dados cheio.\n");
		return;
	}

	BD->array[BD->size++] = jogador.Clone(jogador);

}

void CloseBD(BD* BD) {
	
	for (int i = 0; i < BD->size; i++) {
		BD->array[i].Close(BD->array[i]);
	}

	free(BD->array);
	
	BD->maxSize = BD->size = 0;
}

BD newBD(size_t maxSize) {

	BD BD;

	if (maxSize == 0) maxSize = 80;

	BD.size = 0;
	BD.maxSize = maxSize;
	BD.ordenado = false;
	BD.array = (Jogador*)malloc(maxSize * sizeof(Jogador));

	BD.Get = GetBD;
	BD.ImportDataBase = ImportDataBaseBD;
	BD.OrdenarPorNome = OrdenarPorNomeBD;
	BD.PesquisarPorNome = PesquisarPorNomeBD;
	BD.Mostrar = MostrarBD;
	BD.Inserir = InserirBD;

	BD.Close = CloseBD;

	return BD;
}

typedef struct Celula {
	Jogador jogador;
	struct Celula *esq, *dir;
	void (*Close) (struct Celula*);
} Celula;

void CloseCelula(Celula* celula) {
	celula->jogador.Close(celula->jogador);
	free(celula);
}

Celula* newCelula(Jogador jogador, Celula* esq, Celula* dir) {
	Celula* celula = malloc(sizeof(Celula));

	celula->jogador = jogador.Clone(jogador);
	celula->esq = esq;
	celula->dir = dir;
	celula->Close = CloseCelula;

	return celula;
}

typedef struct ListaDupla {

	int size;
	Celula *primeiro, *ultimo;

	void (*Mostrar) (struct ListaDupla);
	bool (*CompareTo) (Jogador, Jogador, Log*);
	void (*InserirFim) (Jogador, struct ListaDupla*);
	bool (*Pesquisar) (Jogador, Log*, struct ListaDupla);
	void (*Close) (struct ListaDupla*);

} ListaDupla;

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

bool CompareToListaDupla(Jogador jog1, Jogador jog2, Log* log) {

	log->comparacoes++;

	int strComp = strcmp(jog1.nome, jog2.nome);

	return strComp == 0;
}

void InserirFimListaDupla(Jogador jogador, ListaDupla* lista) {
	lista->ultimo = lista->ultimo->dir = newCelula(jogador, NULL, NULL);
	lista->size++;
}

bool PesquisarListaDupla(Jogador jogador, Log* log, ListaDupla lista) {

	bool resultado = false;

	for (Celula* i = lista.primeiro->dir; i != NULL; i = i->dir) {
		if (CompareToListaDupla(jogador, i->jogador, log)) {
			resultado = true;
			i = lista.ultimo;
		}
	}

	return resultado;
}

void MostrarListaDupla(ListaDupla lista) {
	if (lista.size == 0) {
		// errx(1, "Erro ao mostrar: Lista Dupla vazia.\n");
	}

	for (Celula* i = lista.primeiro->dir; i != NULL; i = i->dir) {
		puts(i->jogador.nome);
	}

}

void CloseListaDupla(ListaDupla* lista) {
	
	Celula* i = lista->primeiro;
	while (i != NULL) {
		Celula* tmp = i;
		i = i->dir;
		tmp->Close(tmp);
	}

	lista->size = 0;
}

ListaDupla newListaDupla() {

	ListaDupla lista;

	lista.size = 0;
	Celula* new = malloc(sizeof(Celula));
	new->jogador = newJogador();
	new->esq = NULL;
	new->dir = NULL;
	new->Close = CloseCelula;
	lista.primeiro = lista.ultimo = new;

	lista.CompareTo = CompareToListaDupla;

	lista.InserirFim = InserirFimListaDupla;
	lista.Pesquisar = PesquisarListaDupla;

	lista.Mostrar = MostrarListaDupla;
	lista.Close = CloseListaDupla;

	return lista;
}

// clear && gcc TP04Q09.c && ./a.out < pub.in > result.txt

typedef struct HashInd {

	int tabelaLen;
	ListaDupla* array;

	void (*Inserir) (Jogador, struct HashInd);
	bool (*Pesquisar) (Jogador, Log* log, struct HashInd);
	void (*Mostrar) (struct HashInd);
	void (*Close) (struct HashInd);

} HashInd;

HashInd newHashInd();
int Hash(Jogador, HashInd);
void InserirHashInd(Jogador, HashInd);
bool PesquisarHashInd(Jogador, Log*, HashInd);
void MostrarHashInd(HashInd);
void CloseHashInd(HashInd);

// clear && gcc TP04Q09Verde.c && ./a.out < pub.in > result.txt

int main() {

	BD BD = newBD(BD_SIZE);
	BD.ImportDataBase("/tmp/players.csv", &BD);

	HashInd hash = newHashInd(25);

	char inputPUBIN[STR_MAX_LEN];

	while (!strstr("FIMfim", readStr(0, inputPUBIN))) {
		int id = atoi(inputPUBIN);
		hash.Inserir(BD.Get(id, BD), hash);
	}

	// hash.Mostrar(hash);

	Timer timer = newTimer();
	Log log = newLog();

	BD.OrdenarPorNome(&BD); // Para possibilitar uma pesquisa binária.

	timer.Start(&timer);
	while (!strstr("FIMfim", readStr(0, inputPUBIN))) {
		Jogador pesquisado = BD.PesquisarPorNome(inputPUBIN, &log, BD);
		bool resultado = hash.Pesquisar(pesquisado, &log, hash);
		printf("%s %s\n", inputPUBIN, resultado ? "SIM" : "NAO");
	}
	timer.Stop(&timer);

	log.RegistroPesquisa("794989_hashIndireta.txt", timer, log);

	hash.Close(hash);
	BD.Close(&BD);
}

HashInd newHashInd(int tabelaLen) {

	HashInd hash;

	hash.tabelaLen = tabelaLen;
	hash.array = malloc(tabelaLen * sizeof(ListaDupla));

	for (int i = 0; i < tabelaLen; i++) {
		hash.array[i] = newListaDupla();
	}

	hash.Inserir = InserirHashInd;
	hash.Pesquisar = PesquisarHashInd;
	hash.Mostrar = MostrarHashInd;

	hash.Close = CloseHashInd;

	return hash;
}

int Hash(Jogador jogador, HashInd hash) {
	return jogador.altura % hash.tabelaLen;
}

void InserirHashInd(Jogador jogador, HashInd hash) {
	int pos = Hash(jogador, hash);
	hash.array[pos].InserirFim(jogador, &hash.array[pos]);
}

bool PesquisarHashInd(Jogador jogador, Log* log, HashInd hash) {
	int pos = Hash(jogador, hash);
	return hash.array[pos].Pesquisar(jogador, log, hash.array[pos]);
}

void MostrarHashInd(HashInd hash) {
	puts("----- Tabela Hash -----");
	for (int i = 0; i < hash.tabelaLen; i++) {
		hash.array[i].Mostrar(hash.array[i]);
	}
}

void CloseHashInd(HashInd hash) {

	for (int i = 0; i < hash.tabelaLen; i++) {
		hash.array[i].Close(&hash.array[i]);
	}

	free(hash.array);
}