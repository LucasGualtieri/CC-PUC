#ifndef FILA_CIRCULAR_H_
#define FILA_CIRCULAR_H_

#include <stdbool.h> 

typedef struct FilaCircular {
	int *array, maxSize, first, last;
	bool ShowOnUpdate;
	void (*Inserir)(int number, struct FilaCircular*);
	int (*Remover)(struct FilaCircular*);
	int (*Next)(struct FilaCircular*);
	void (*Mostrar)(struct FilaCircular);
	void (*ToggleShow) (struct FilaCircular*);

} FilaCircular;

void InserirFilaCircular(int number, FilaCircular* fila) {
	if ((fila->last + 1) % fila->maxSize == fila->first) {
		puts("Erro ao inserir: fila cheia.");
		return;	
	}

	fila->array[fila->last] = number;
	fila->last = (fila->last + 1) % fila->maxSize;

	if (fila->ShowOnUpdate) fila->Mostrar(*fila);
}

int RemoverFilaCircular(FilaCircular* fila) {
	if (fila->last == fila->first) {
		puts("Erro ao inserir: fila cheia.");
		return 0;
	}

	int removido = fila->array[fila->first];
	fila->first = (fila->first + 1) % fila->maxSize;

	if (fila->ShowOnUpdate) fila->Mostrar(*fila);

	return removido;
}

int NextFilaCircular(FilaCircular* fila) {
	return RemoverFilaCircular(fila);
}

void MostrarFilaCircular(FilaCircular fila) {

	if (fila.maxSize == 0) {
		printf("fila vazia.\n");	
		return;
	}

	printf("{ ");	
	for (int i = fila.first; i < fila.last; i = (i + 1) % fila.maxSize) {
		printf("%d", fila.array[i]);
		printf("%s", i < fila.last - 1 ? " " : " }\n");
	}
}

void ToggleShowOnUpdateFilaCircular(FilaCircular* fila) {
	fila->ShowOnUpdate = fila->ShowOnUpdate ? false : true;
}

FilaCircular newFilaCircular(size_t maxSize) {

	FilaCircular fila;

	if (maxSize == 0) maxSize = 80;
	
	fila.maxSize = maxSize;
	fila.array = (int*)malloc((maxSize + 1) * sizeof(int));
	fila.first = fila.last = 0;
	fila.ShowOnUpdate = false;
	fila.ToggleShow = ToggleShowOnUpdateFilaCircular;
	fila.Next = NextFilaCircular;
    fila.Inserir = InserirFilaCircular;
	fila.Remover = RemoverFilaCircular;
    fila.Mostrar = MostrarFilaCircular;

	return fila;
}

#endif /* LIB_H_ */