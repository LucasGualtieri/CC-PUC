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
	void (*RegistroOrdenacao) (Timer, struct Log);
} Log;

void RegistroOrdenacao(Timer timer, Log log) {
	printf("Tempo de execução: %fs\n", timer.Time(&timer));
	printf("Número de movimentações: %d\n", log.movimentacoes);	
}

Log newLog() {
	Log log = { 0, 0 };
	log.RegistroOrdenacao = RegistroOrdenacao;
	return log;
}

// --------------------------- CLASSE LISTA ---------------------------

typedef struct Lista {

	String *array;
	int maxSize, size;
	bool showOnUpdate;

	void (*Inserir) (String, struct Lista*);
	bool (*isSorted) (struct Lista);

	void (*ImportDataBase) (literal filePath, struct Lista*);
	String (*Get) (int id, struct Lista);

	void (*Mostrar) (struct Lista);
	void (*Close) (struct Lista*);

} Lista;

void InserirLista(String string, Lista* lista) {

	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao inserir: Lista cheia.\n");
		return;
	}

	lista->array[lista->size++] = strdup(string);
}

bool IsSorted(Lista lista) {

	bool result = true;

	String* array = lista.array;

	for (int i = 1; i < lista.size - 1; i++) {
		if (strcmp(array[i - 1], array[i]) > 0) {
			result = false;
			i = lista.size;
		}
	}

	return result;
}

void MostrarLista(Lista lista) {

	if (lista.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Lista vazia.\n");
		return;
	}

	for (int i = 0; i < lista.size; i++) {
		printf("%d° %s\n", i + 1, lista.array[i]);
	}
}

void CloseLista(Lista* lista) {
	
	for (int i = 0; i < lista->size; i++) {
		free(lista->array[i]);
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
	// readStr(CSV, inputCSV); // Despresando o header do .csv
	
	while (!feof(CSV)) {
		fscanf(CSV, "%s", inputCSV);
		BD->Inserir(inputCSV, BD);
	}

}

String GetLista(int id, Lista lista) { return lista.array[id]; }

Lista newLista(size_t maxSize) {

	Lista lista;

	if (maxSize == 0) maxSize = 500;

	lista.size = 0;
	lista.maxSize = maxSize;
	lista.array = (String*)malloc(maxSize * sizeof(String));

	lista.Inserir = InserirLista;
	lista.isSorted = IsSorted;

	lista.ImportDataBase = ImportDataBaseBD;
	lista.Get = GetLista;

	lista.Mostrar = MostrarLista;
	lista.Close = CloseLista;

	return lista;
}

#endif