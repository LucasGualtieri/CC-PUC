#ifndef LISTA_LINEAR_H_
#define LISTA_LINEAR_H_

#include <stdbool.h>

typedef struct Lista {
	int *array, maxSize, size;
	bool ShowOnUpdate;

	void (*InserirInicio)(int number, struct Lista*);
	void (*InserirFim)(int number, struct Lista*);
	void (*Inserir)(int number, size_t position, struct Lista*);

	int (*RemoverInicio)(struct Lista*);
	int (*RemoverFim)(struct Lista*);
	int (*Remover)(size_t position, struct Lista*);

	void (*ToggleShow) (struct Lista*);
	void (*Mostrar)(struct Lista);
	void (*Close)(struct Lista*);

} Lista;

void InserirInicioListaLinear(int number, Lista* lista) {

	if (lista->maxSize == 0) {
		puts("Erro ao inserir: Lista fechada.");
		return;
	} else if (lista->size == lista->maxSize) {
		puts("Erro ao inserir: Lista cheia.");
		return;
	}

	for (int i = 0; i < lista->size; i++) {
		lista->array[lista->size - i] = lista->array[lista->size - i - 1];
	}

	lista->size++;
	lista->array[0] = number;

	if (lista->ShowOnUpdate) lista->Mostrar(*lista);
}

void InserirFimListaLinear(int number, Lista* lista) {

	if (lista->maxSize == 0) {
		puts("Erro ao inserir: Lista fechada.");
		return;
	} else if (lista->size == lista->maxSize) {
		puts("Erro ao inserir: Lista cheia.");
		return;
	}

	lista->array[lista->size++] = number;

	if (lista->ShowOnUpdate) lista->Mostrar(*lista);

}

void InserirListaLinear(int number, size_t position, Lista* lista) {

	if (lista->maxSize == 0) {
		puts("Erro ao inserir: Lista fechada.");
		return;
	} else if (lista->size == lista->maxSize) {
		puts("Erro ao inserir: Lista cheia.");
		return;
	}

	for (int i = 0; i < lista->size - position; i++) {
		lista->array[lista->size - i] = lista->array[lista->size - i - 1];
	}

	lista->array[position] = number;
	lista->size++;

	if (lista->ShowOnUpdate) lista->Mostrar(*lista);
}

int RemoverInicioListaLinear(Lista* lista) {

	// Em hexadecimal, cada dígito pode representar 4 bits.
	if (lista->maxSize == 0) {
		puts("Erro ao remover: Lista fechada.");
		return -0x7fffffff;
	} else if (lista->size == 0) {
		puts("Erro ao remover: Lista vazia.");
		return -0x7fffffff;
	}

	int removido = lista->array[0];

	for (int i = 0; i < lista->size - 1; i++) {
		lista->array[i] = lista->array[i + 1];
	}

	lista->size--;

	if (lista->ShowOnUpdate) lista->Mostrar(*lista);

	return removido;
}

int RemoverFimListaLinear(Lista* lista) {

	// Em hexadecimal, cada dígito pode representar 4 bits.
	if (lista->maxSize == 0) {
		puts("Erro ao remover: Lista fechada.");
		return -0x7fffffff;
	} else if (lista->size == 0) {
		puts("Erro ao remover: Lista vazia.");
		return -0x7fffffff;
	}

	int removido = lista->array[--lista->size];

	if (lista->ShowOnUpdate) lista->Mostrar(*lista);

	return removido;
}

int RemoverListaLinear(size_t position, Lista* lista) {

	// Em hexadecimal, cada dígito pode representar 4 bits.
	if (lista->maxSize == 0) {
		puts("Erro ao remover: Lista fechada.");
		return -0x7fffffff;
	} else if (lista->size == 0) {
		puts("Erro ao remover: Lista vazia.");
		return -0x7fffffff;
	}

	int removido = lista->array[position];

	for (int i = position; i < lista->size - 1; i++) {
		lista->array[i] = lista->array[i + 1];
	}

	lista->size--;

	if (lista->ShowOnUpdate) lista->Mostrar(*lista);

	return removido;
}

void ToggleShowOnUpdateListaLinear(Lista* lista) {
	lista->ShowOnUpdate = lista->ShowOnUpdate ? false : true;
}

void MostrarListaLinear(Lista lista) {

	if (lista.maxSize == 0) {
		puts("Erro ao mostrar: Lista fechada.");
		return;
	} else if (lista.size == 0) {
		puts("Erro ao mostrar: Fila vazia.");
		return;
	}

	printf("{ ");
	for (int i = 0; i < lista.size; i++) {
		printf("%d ", lista.array[i]);
	}
	printf("}\n");
}

void CloseListaLinear(Lista* lista) {
	free(lista->array);
	lista->maxSize = 0;
}

Lista newLista(size_t maxSize) {

	Lista lista;

	if (maxSize == 0) maxSize = 80;

	lista.size = 0;
	lista.maxSize = maxSize;
	lista.array = (int*)malloc(maxSize * sizeof(int));
	lista.ShowOnUpdate = false;

	lista.InserirInicio = InserirInicioListaLinear;
	lista.InserirFim = InserirFimListaLinear;
	lista.Inserir = InserirListaLinear;

	lista.RemoverInicio = RemoverInicioListaLinear;
	lista.RemoverFim= RemoverFimListaLinear;
	lista.Remover = RemoverListaLinear;

	lista.ToggleShow = ToggleShowOnUpdateListaLinear;
	lista.Mostrar = MostrarListaLinear;
	lista.Close = CloseListaLinear;

	return lista;
}

#endif