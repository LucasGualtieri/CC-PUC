#ifndef FILA_CIRCULAR_H_
#define FILA_CIRCULAR_H_

#include <stdbool.h> 

typedef struct FilaCircular {
	int *array, maxSize, size, first, last;
	bool showOnUpdate;
	
	void (*Inserir)(int number, struct FilaCircular*);
	int (*Remover)(struct FilaCircular*);
	int (*Next)(struct FilaCircular*);

	void (*ToggleShow) (struct FilaCircular*);
	void (*Mostrar)(struct FilaCircular);
	void (*Close)(struct FilaCircular*);

} FilaCircular;

void InserirFilaCircular(int number, FilaCircular* fila) {
	
	if (fila->maxSize == 0) {
		puts("Erro ao inserir: Fila fechada.");
		return;	
	} else if ((fila->last + 1) % fila->maxSize == fila->first) {
		puts("Erro ao inserir: Fila cheia.");
		return;	
	}

	fila->size++;
	fila->array[fila->last] = number;
	fila->last = (fila->last + 1) % fila->maxSize;

	if (fila->showOnUpdate) fila->Mostrar(*fila);
}

int RemoverFilaCircular(FilaCircular* fila) {

	// Em hexadecimal, cada dígito pode representar 4 bits.
	if (fila->maxSize == 0) {
		puts("Erro ao remover: Fila fechada.");
		return -0x7fffffff;	
	} else if (fila->last == fila->first) {
		puts("Erro ao remover: Fila vazia.");
		return -0x7fffffff;
	}

	fila->size--;
	int removido = fila->array[fila->first];
	fila->first = (fila->first + 1) % fila->maxSize;

	if (fila->showOnUpdate) fila->Mostrar(*fila);

	return removido;
}

int NextFilaCircular(FilaCircular* fila) {
	return RemoverFilaCircular(fila);
}

void MostrarFilaCircular(FilaCircular fila) {

	if (fila.maxSize == 0) {
		puts("Erro ao mostrar: Lista fechada.");
		return;
	} else if (fila.last == fila.first) {
		puts("Erro ao mostrar: Fila vazia.");
		return;
	}

	printf("{ ");	
	for (int i = fila.first; i != fila.last; i = (i + 1) % fila.maxSize) {
		printf("%d ", fila.array[i]);
	}
	printf("}\n");
}

void ToggleShowOnUpdateFilaCircular(FilaCircular* fila) {
	fila->showOnUpdate = fila->showOnUpdate ? false : true;
}

void CloseFilaCircular(FilaCircular* fila) {
	fila->maxSize = 0;
	free(fila->array);
}

FilaCircular newFilaCircular(size_t maxSize) {

	FilaCircular fila;

	if (maxSize == 0) maxSize = 80;
	
	fila.size = 0;
	fila.maxSize = maxSize + 1;
	fila.array = (int*)malloc((maxSize + 1) * sizeof(int));
	fila.first = fila.last = 0;
	fila.showOnUpdate = false;

	fila.Inserir = InserirFilaCircular;
	fila.Remover = RemoverFilaCircular;
	fila.Next = NextFilaCircular;

	fila.ToggleShow = ToggleShowOnUpdateFilaCircular;
	fila.Mostrar = MostrarFilaCircular;
	fila.Close = CloseFilaCircular;

	return fila;
}

#endif