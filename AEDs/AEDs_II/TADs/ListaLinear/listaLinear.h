#ifndef LIB_H_
#define LIB_H_

typedef struct Lista {
	int *array, maxSize, size;
	void (*InserirInicio)(int number, struct Lista*);
	void (*InserirFim)(int number, struct Lista*);
	void (*Inserir)(int number, size_t position, struct Lista*);
	int (*RemoverInicio)(struct Lista*);
	int (*RemoverFim)(struct Lista*);
	int (*Remover)(size_t position, struct Lista*);
	void (*Mostrar)(struct Lista);

} Lista;

void InserirInicioListaLinear(int number, Lista* lista) {
	if (lista->size == lista->maxSize) {
		printf("Erro ao inserir: Lista cheia.");
		return;	
	}

	for (int i = 0; i < lista->size; i++) {	
		lista->array[lista->size - i] = lista->array[lista->size - i - 1];
	}
	
	lista->size++;

	lista->array[0] = number;
}

void InserirFimListaLinear(int number, Lista* lista) {
	if (lista->size == lista->maxSize) {
		printf("Erro ao inserir: Lista cheia.");
		return;	
	}
	
	lista->array[lista->size++] = number;

}

void InserirListaLinear(int number, size_t position, Lista* lista) {
	if (lista->size == lista->maxSize) {
		printf("Erro ao inserir: Lista cheia.");
		return;	
	}
	
	for (int i = 0; i < lista->size - position; i++) {	
		lista->array[lista->size - i] = lista->array[lista->size - i - 1];
	}
	
	lista->array[position] = number;

	lista->size++;
}

int RemoverInicioListaLinear(Lista* lista) {
	if (lista->size == 0) {
		printf("Erro ao remover do inicio: Lista vazia.");
		return 0;
	}

	int removido = lista->array[0];

	for (int i = 0; i < lista->size - 1; i++) {	
		lista->array[i] = lista->array[i + 1];
	}

	lista->size--;

	return removido;
}

int RemoverFimListaLinear(Lista* lista) {
	if (lista->size == 0) {
		printf("Erro ao remover do fim: Lista vazia.");
		return 0;
	}

	int removido = lista->array[--lista->size];

	return removido;
}

int RemoverListaLinear(size_t position, Lista* lista) {
	if (lista->size == 0) {
		printf("Erro ao remover do fim: Lista vazia.");
		return 0;
	}

	int removido = lista->array[position];

	for (int i = position; i < lista->size - 1; i++) {
		lista->array[i] = lista->array[i + 1];
	}
	
	lista->size--;

	return removido;
}

void MostrarListaLinear(Lista lista) {

	if (lista.size == 0) printf("Lista vazia.\n");	

	for (int i = 0; i < lista.size; i++) {
		if (i == 0) printf("{ ");	
		printf("%d", lista.array[i]);
		printf("%s", i < lista.size - 1 ? " " : " }\n");
	}
}

Lista newLista(size_t maxSize) {

	Lista lista;

	if (maxSize == 0) maxSize = 80;
	
	lista.maxSize = maxSize;
	lista.array = (int*)malloc(maxSize * sizeof(int));
	lista.size = 0;
    lista.InserirInicio = InserirInicioListaLinear;
    lista.InserirFim = InserirFimListaLinear;
    lista.Inserir = InserirListaLinear;
    lista.Mostrar = MostrarListaLinear;
	lista.RemoverInicio = RemoverInicioListaLinear;
	lista.RemoverFim= RemoverFimListaLinear;
	lista.Remover = RemoverListaLinear;

	return lista;
}

#endif /* LIB_H_ */