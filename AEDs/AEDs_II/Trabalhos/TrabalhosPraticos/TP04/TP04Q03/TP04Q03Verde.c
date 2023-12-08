#include <err.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// clear && gcc TP04Q03Verde.c && ./a.out < pub.in > result.txt

// ===================================================================
// ----------------- FUNÇÕES E DEFINIÇÕES AUXILIARES -----------------
// ===================================================================

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

#define max(val1, val2) (val1 > val2 ? val1 : val2)
#define getFator(raiz) (alturaDir(raiz) - alturaEsq(raiz))
#define alturaDir(raiz) (raiz->dir == NULL ? 0 : raiz->dir->nivel)
#define alturaEsq(raiz) (raiz->esq == NULL ? 0 : raiz->esq->nivel)

typedef struct No {
	Jogador jogador;
	int nivel;
	struct No *esq, *dir;
	void (*setNivel) (struct No*);
	void (*Close) (struct No*);
} No;

void SetNivelNo(No* no) {
	no->nivel = max(alturaEsq(no), alturaDir(no)) + 1;
}

void CloseNo(No* No) {
	No->jogador.Close(No->jogador);
	free(No);
}

No* newNo(Jogador jogador, No* esq, No* dir) {

	No* no = malloc(sizeof(No));

	no->jogador = jogador.Clone(jogador);
	no->esq = esq;
	no->dir = dir;
	no->setNivel = SetNivelNo;
	no->Close = CloseNo;

	return no;
}

typedef struct AVL {
	No* raiz;
	void (*Inserir) (Jogador, struct AVL*);
	void (*Mostrar) (struct AVL);
	int (*Altura) (struct AVL);
	void (*Close) (struct AVL*);

} AVL;

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

int CompareToAVL(String nome, No* raiz, Log* log) {
	log->comparacoes++;
	return strcmp(nome, raiz->jogador.nome);
}

No* Balancear(No* raiz);

No* InserirAVLAux(Jogador jogador, No* raiz, Log* log) {

	if (raiz == NULL) {
		raiz = newNo(jogador, NULL, NULL);
	} else if (CompareToAVL(jogador.nome, raiz, log) < 0) {
		raiz->esq = InserirAVLAux(jogador, raiz->esq, log);
	} else if (CompareToAVL(jogador.nome, raiz, log) > 0) {
		raiz->dir = InserirAVLAux(jogador, raiz->dir, log);
	} else {
		errx(1, "Erro ao inserir na Árvore: Jogador '%s' repetido.", jogador.nome);
	}

	return Balancear(raiz);
}

No* RotacaoSimplesEsq(No* raiz) {

	No* aux = raiz->dir;
	raiz->dir = aux->esq;
	aux->esq = raiz;

	raiz->setNivel(raiz);
	aux->setNivel(aux);

	return aux;
}

No* RotacaoSimplesDir(No* raiz) {

	No* aux = raiz->esq;
	raiz->esq = aux->dir;
	aux->dir = raiz;

	raiz->setNivel(raiz);
	aux->setNivel(aux);

	return aux;
}

No* RotacaoDuplaDirEsq(No* raiz) {
	raiz->dir = RotacaoSimplesDir(raiz->dir);
	return RotacaoSimplesEsq(raiz);
}

No* RotacaoDuplaEsqDir(No* raiz) {
	raiz->esq = RotacaoSimplesEsq(raiz->esq);
	return RotacaoSimplesDir(raiz);
}

No* Balancear(No* raiz) {

	raiz->setNivel(raiz);

	if (getFator(raiz) == 2) {
		if (getFator(raiz->dir) == 1) {
			raiz = RotacaoSimplesEsq(raiz);
		} else {
			raiz = RotacaoDuplaDirEsq(raiz);
		}
	} else if (getFator(raiz) == -2) {
		if (getFator(raiz->esq) == -1) {
			raiz = RotacaoSimplesDir(raiz);
		} else {
			raiz = RotacaoDuplaEsqDir(raiz);
		}
	}

	return raiz;
} 

void InserirAVL(Jogador jogador, AVL* arvore) {
	Log log;
	arvore->raiz = InserirAVLAux(jogador, arvore->raiz, &log);
}

void MostrarAux(No* raiz) {

	if (raiz != NULL) {
		MostrarAux(raiz->esq);
		puts(raiz->jogador.nome);
		MostrarAux(raiz->dir);
	}
}

void MostrarAVL(AVL arvore) {

	if (arvore.raiz == NULL) {
		errx(1, "Erro ao printar na Árvore: Árvore vazia.");
	}

	puts("---- Mostrar Arvore ----");
	MostrarAux(arvore.raiz);
}

int AlturaAVL(AVL arvore) {

	if (arvore.raiz == NULL) {
		errx(0, "Erro ao printar árvore: Árvore vazia.");
	}

	int esq = alturaEsq(arvore.raiz);
	int dir = alturaDir(arvore.raiz);

	return esq > dir ? esq : dir;
}

void CloseAVLAux(No* i) {
	if (i != NULL) {
		CloseAVLAux(i->esq);
		CloseAVLAux(i->dir);
		i->Close(i);
	}
}

void CloseAVL(AVL* arvore) {
	CloseAVLAux(arvore->raiz);
	arvore->raiz = NULL;
}

AVL newAVL() {

	AVL arvore;

	arvore.raiz = NULL;

	arvore.Inserir = InserirAVL;
	arvore.Mostrar = MostrarAVL;
	arvore.Altura = AlturaAVL;

	arvore.Close = CloseAVL;

	return arvore;
}

// clear && gcc TP04Q03.c && ./a.out < pub.in > result.txt

bool PesquisarAux(No* raiz, String chave, Log* log);

bool Pesquisar(AVL arvore, String chave, Log* log) {

	if (arvore.raiz == NULL) {
		errx(1, "Erro ao Pesquisar na árvore: Árvore vazia.");
	}

	printf("%s raiz ", chave);
	return PesquisarAux(arvore.raiz, chave, log);
}

bool PesquisarAux(No* raiz, String chave, Log* log) {

	bool resultado;
	
	if (raiz == NULL) {
		resultado = false;
	} else if (CompareToAVL(chave, raiz, log) < 0) {
		printf("esq ");
		resultado = PesquisarAux(raiz->esq, chave, log);
	} else if (CompareToAVL(chave, raiz, log) > 0) {
		printf("dir ");
		resultado = PesquisarAux(raiz->dir, chave, log);
	} else {
		resultado = true;
	}

	return resultado;
}

void main() {

	BD BD = newBD(BD_SIZE);
	BD.ImportDataBase("/tmp/players.csv", &BD);
	AVL arvore = newAVL();

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		arvore.Inserir(BD.Get(id, BD), &arvore);
	}

	Timer timer = newTimer();
	Log log = newLog();

	timer.Start(&timer);
	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		bool resultado = Pesquisar(arvore, inputPUBIN, &log);
		puts(resultado ? "SIM" : "NAO");
	}
	timer.Stop(&timer);

	log.RegistroPesquisa("794989_avl.txt", timer, log);

	arvore.Close(&arvore);
	BD.Close(&BD);
}