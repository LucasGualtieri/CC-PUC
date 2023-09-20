#include <stdbool.h>

typedef struct Fila {
	int *array, maxSize, size;
	bool ShowOnUpdate;

	void (*Inserir)(int number, struct Fila*);
	int (*Remover)(struct Fila*);

	void (*ToggleShow) (struct Fila*);
	void (*Mostrar)(struct Fila);
	void (*Close)(struct Fila*);

} Fila;

void InserirFilaLinear(int number, Fila* fila) {

	if (fila->maxSize == 0) {
		puts("Erro ao inserir: Fila fechada.");
		return;
	} else if (fila->size == fila->maxSize) {
		puts("Erro ao inserir: Fila cheia.");
		return;
	}

	fila->array[fila->size++] = number;

	if (fila->ShowOnUpdate) fila->Mostrar(*fila);

}

int RemoverFilaLinear(Fila* fila) {

	// Em hexadecimal, cada dígito pode representar 4 bits.
	if (fila->maxSize == 0) {
		puts("Erro ao remover: Fila fechada.");
		return -0x7fffffff;
	} else if (fila->size == 0) {
		puts("Erro ao remover: Fila vazia.");
		return -0x7fffffff;
	}

	int removido = fila->array[0];

	for (int i = 0; i < fila->size - 1; i++) {
		fila->array[i] = fila->array[i + 1];
	}

	fila->size--;

	if (fila->ShowOnUpdate) fila->Mostrar(*fila);

	return removido;
}

void ToggleShowOnUpdateFilaLinear(Fila* fila) {
	fila->ShowOnUpdate = fila->ShowOnUpdate ? false : true;
}

void MostrarFilaLinear(Fila fila) {

	if (fila.maxSize == 0) {
		puts("Erro ao mostrar: Fila fechada.");
		return;
	} else if (fila.size == 0) {
		puts("Erro ao mostrar: Fila vazia.");
		return;
	}

	printf("{ ");
	for (int i = 0; i < fila.size; i++) {
		printf("%d ", fila.array[i]);
	}
	printf("}\n");
}

void CloseFilaLinear(Fila* fila) {
	free(fila->array);
	fila->maxSize = 0;
}

Fila newFila(size_t maxSize) {

	Fila fila;

	if (maxSize == 0) maxSize = 80;

	fila.size = 0;
	fila.maxSize = maxSize;
	fila.array = (int*)malloc(maxSize * sizeof(int));
	fila.ShowOnUpdate = false;

	fila.Inserir = InserirFilaLinear;
	fila.Remover = RemoverFilaLinear;

	fila.ToggleShow = ToggleShowOnUpdateFilaLinear;
	fila.Mostrar = MostrarFilaLinear;
	fila.Close = CloseFilaLinear;

	return fila;
}