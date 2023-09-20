#include <stdbool.h>

typedef struct Pilha {
	int *array, maxSize, size;
	bool ShowOnUpdate;

	void (*Inserir)(int number, struct Pilha*);
	int (*Remover)(struct Pilha*);

	void (*ToggleShow) (struct Pilha*);
	void (*Mostrar)(struct Pilha);
	void (*Close)(struct Pilha*);

} Pilha;

void InserirPilhaLinear(int number, Pilha* pilha) {

	if (pilha->maxSize == 0) {
		puts("Erro ao inserir: Pilha fechada.");
		return;
	} else if (pilha->size == pilha->maxSize) {
		puts("Erro ao inserir: Pilha cheia.");
		return;
	}

	pilha->array[pilha->size++] = number;

	if (pilha->ShowOnUpdate) pilha->Mostrar(*pilha);

}

int RemoverPilhaLinear(Pilha* pilha) {

	// Em hexadecimal, cada dígito pode representar 4 bits.
	if (pilha->maxSize == 0) {
		puts("Erro ao remover: Pilha fechada.");
		return -0x7fffffff;
	} else if (pilha->size == 0) {
		puts("Erro ao remover: Pilha vazia.");
		return -0x7fffffff;
	}

	int removido = pilha->array[--pilha->size];

	if (pilha->ShowOnUpdate) pilha->Mostrar(*pilha);

	return removido;
}

void ToggleShowOnUpdatePilhaLinear(Pilha* pilha) {
	pilha->ShowOnUpdate = pilha->ShowOnUpdate ? false : true;
}

void MostrarPilhaLinear(Pilha pilha) {

	if (pilha.maxSize == 0) {
		puts("Erro ao mostrar: Pilha fechada.");
		return;
	} else if (pilha.size == 0) {
		puts("Erro ao mostrar: Fila vazia.");
		return;
	}

	printf("{ ");
	for (int i = 0; i < pilha.size; i++) {
		printf("%d ", pilha.array[i]);
	}
	printf("}\n");
}

void ClosePilhaLinear(Pilha* pilha) {
	free(pilha->array);
	pilha->maxSize = 0;
}

Pilha newPilha(size_t maxSize) {

	Pilha pilha;

	if (maxSize == 0) maxSize = 80;

	pilha.size = 0;
	pilha.maxSize = maxSize;
	pilha.array = (int*)malloc(maxSize * sizeof(int));
	pilha.ShowOnUpdate = false;

	pilha.Inserir = InserirPilhaLinear;
	pilha.Remover = RemoverPilhaLinear;

	pilha.ToggleShow = ToggleShowOnUpdatePilhaLinear;
	pilha.Mostrar = MostrarPilhaLinear;
	pilha.Close = ClosePilhaLinear;

	return pilha;
}