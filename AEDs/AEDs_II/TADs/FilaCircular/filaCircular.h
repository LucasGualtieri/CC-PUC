#ifndef FILA_CIRCULAR_H_
#define FILA_CIRCULAR_H_

#include <stdbool.h> 

typedef struct FilaCircular {
	int *array, maxSize, size;
	bool ShowOnUpdate;
	void (*Inserir)(int number, struct FilaCircular*);
	int (*Remover)(struct FilaCircular*);
	int (*Next)(struct FilaCircular*);
	void (*Mostrar)(struct FilaCircular);
	void (*ToggleShow) (struct FilaCircular*);

} FilaCircular;

void InserirFilaCircular(int number, FilaCircular* fila) {
	if (fila->size == fila->maxSize) {
		printf("Erro ao inserir: fila cheia.");
		return;	
	}
	
	fila->array[fila->size++] = number;

	if (fila->ShowOnUpdate) fila->Mostrar(*fila);
}

int RemoverFilaCircular(FilaCircular* fila) {
	if (fila->size == 0) {
		printf("Erro ao remover do inicio: fila vazia.");
		return 0;
	}

	int removido = fila->array[0];

	for (int i = 0; i < fila->size - 1; i++) {	
		fila->array[i] = fila->array[i + 1];
	}

	fila->size--;

	if (fila->ShowOnUpdate) fila->Mostrar(*fila);

	return removido;
}

int NextFilaCircular(FilaCircular* fila) {
	return RemoverFilaCircular(fila);
}

void MostrarFilaCircular(FilaCircular fila) {

	if (fila.size == 0) printf("fila vazia.\n");	

	for (int i = 0; i < fila.size; i++) {
		if (i == 0) printf("{ ");	
		printf("%d", fila.array[i]);
		printf("%s", i < fila.size - 1 ? " " : " }\n");
	}
}

void ToggleShowOnUpdateFilaCircular(FilaCircular* fila) {
	fila->ShowOnUpdate = fila->ShowOnUpdate ? false : true;
}

FilaCircular newFilaCircular(size_t maxSize) {

	FilaCircular fila;

	if (maxSize == 0) maxSize = 80;
	
	fila.maxSize = maxSize;
	fila.array = (int*)malloc(maxSize * sizeof(int));
	fila.size = 0;
	fila.ShowOnUpdate = false;
	fila.ToggleShow = ToggleShowOnUpdateFilaCircular;
	fila.Next = NextFilaCircular;
    fila.Inserir = InserirFilaCircular;
	fila.Remover = RemoverFilaCircular;
    fila.Mostrar = MostrarFilaCircular;

	return fila;
}

#endif /* LIB_H_ */