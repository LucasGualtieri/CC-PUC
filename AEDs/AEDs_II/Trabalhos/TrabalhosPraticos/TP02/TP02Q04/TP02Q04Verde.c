#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

// clear && gcc TP02Q04Verde.c && ./a.out < pub.in > result.txt

/*
	A MAIN ESTÁ NO FINAL NO ARQUIVO
*/

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


// ------------------- CLASSE SPLIT -------------------

#define MAX_ATTRIBUTES 8

typedef struct Split {
	int size;
	char array[MAX_ATTRIBUTES][STR_MAX_LEN];
} Split;

Split newSplit(FILE* CSV) {

	Split split = { 8 }; // Inicializa o size com 8

	char valor[STR_MAX_LEN];
	for (int i = 0; i < MAX_ATTRIBUTES; i++) {
		if (fscanf(CSV, "%[^,\n]", valor) == 0) {
			strcpy(split.array[i], "nao informado");
		} else {
			strcpy(split.array[i], valor);
		}
		fgetc(CSV); // Despresando a virgula
	}

	return split;
}

// ------------------- CLASSE TIMER -------------------

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

Timer newTimerStart() {
	Timer timer;
	timer.Start = TimerStart;
	timer.Stop = TimerStop;
	timer.Time = TimerTime;
	timer.Start(&timer);
	return timer;
}

Timer newTimer() {
	Timer timer;
	timer.Start = TimerStart;
	timer.Stop = TimerStop;
	return timer;
}

// ------------------- CLASSE JOGADOR -------------------

typedef struct Jogador {

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

	void (*Construtor) (Split array, struct Jogador*);
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

// ------------------- CLASSE LISTA -------------------

typedef struct Lista {

	Jogador *array;
	int maxSize, size;
	bool showOnUpdate;

	void (*Inserir)(Jogador jogador, struct Lista*);
	Jogador (*Remover)(struct Lista*);

	void (*Sort)(struct Lista);

	void (*ImportDataBase) (literal filePath, struct Lista*);
	Jogador (*Get)(int id, struct Lista);

	void (*ToggleShow)(struct Lista*);
	void (*Mostrar)(struct Lista);
	void (*Close)(struct Lista*);

} Lista;

void InserirLista(Jogador jogador, Lista* lista) {


	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao inserir: Lista cheia.\n");
		return;
	}

	lista->array[lista->size++] = jogador.Clone(jogador);

	if (lista->showOnUpdate) lista->Mostrar(*lista);

}

void SortLista(Lista lista);

void ToggleShowOnUpdateLista(Lista* lista) {
	lista->showOnUpdate = lista->showOnUpdate ? false : true;
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

void CloseLista(Lista* lista) {
	
	for (int i = 0; i < lista->size; i++) {
		lista->array[i].Close(lista->array[i]);
	}

	free(lista->array);
	
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
	lista.showOnUpdate = false;

	lista.Inserir = InserirLista;

	lista.Sort = SortLista;

	lista.ImportDataBase = ImportDataBaseBD;
	lista.Get = GetLista;

	lista.ToggleShow = ToggleShowOnUpdateLista;
	lista.Mostrar = MostrarLista;
	lista.Close = CloseLista;

	return lista;
}

// ------------------- Pesquisa Binária -------------------

bool PesquisaBinariaAux(String nome, int* comparacoes, Jogador* array, int left, int right) {
	
	int mid = (left + right) / 2;
	String elementoBusca = array[mid].nome;

	if (strstr(elementoBusca, nome)) {
		(*comparacoes)++;
		return true;
	}	else if (strcmp(elementoBusca, nome) < 0) {
		left = mid + 1;
	}	else right = mid - 1;
	(*comparacoes) += 2;

	return left <= right ? PesquisaBinariaAux(nome, comparacoes, array, left, right) : false;
}

bool PesquisaBinaria(String nome, int* comparacoes, Lista lista) {
	return PesquisaBinariaAux(nome, comparacoes, lista.array, 0, lista.size - 1);
}

// ------------------- Ordenação por Nome -------------------

#define strcmpr(jog1, jog2) strcmp(jog1.nome, jog2.nome)

void SortLista(Lista lista) {
	int N = lista.size;
	Jogador* array = lista.array;

	int j;
	Jogador temp;
	for (int i = 1; i < N; i++) {
		temp = array[i];
		j = i - 1;
		while (j >= 0 && strcmpr(array[j], temp) > 0) {
			array[j-- + 1] = array[j];
		}
		array[j + 1] = temp;
	}
}

// ------------------- MAIN -------------------

void registroLog(Timer timer, int comparacoes) {
	literal fileName = "794989_binaria.txt";
	FILE* file = fopen(fileName, "w");

	fprintf(file, "794989\t%.3fs\t%d", timer.Time(&timer), comparacoes);

	fclose(file);
}

int main() {

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("/tmp/players.csv", &BD);

	Lista listaJogadores = newLista(74); // Tamanho de entradada do Pub.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		listaJogadores.Inserir(BD.Get(id, BD), &listaJogadores);
	}

	listaJogadores.Sort(listaJogadores);

	Timer timer = newTimerStart();
	int comparacoes = 0;
	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		bool resultado = PesquisaBinaria(inputPUBIN, &comparacoes, listaJogadores);
		printf("%s\n", resultado ? "SIM" : "NAO");
	}
	
	timer.Stop(&timer);

	registroLog(timer, comparacoes);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}