#ifndef LIB_H_
#define LIB_H_

typedef struct Lista {
	int *array, maxSize, size;
    void (*InserirInicio)(struct Lista*, int number);
    void (*InserirFim)(struct Lista*, int number);
    void (*Inserir)(struct Lista*, int number, int position);
    int (*RemoverInicio)(struct Lista*);
    int (*RemoverFim)(struct Lista*);
    int (*Remover)(struct Lista*, int position);
    void (*Mostrar)(struct Lista*);
} Lista;

void InserirInicio(Lista* lista, int number) {
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

void InserirFim(Lista* lista, int number) {
	if (lista->size == lista->maxSize) {
		printf("Erro ao inserir: Lista cheia.");
		return;	
	}
	
	lista->array[lista->size++] = number;

}

void Inserir(Lista* lista, int number, int position) {
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

int RemoverInicio(Lista* lista) {
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

int RemoverFim(Lista* lista) {
	if (lista->size == 0) {
		printf("Erro ao remover do fim: Lista vazia.");
		return 0;
	}

	int removido = lista->array[--lista->size];

	return removido;
}

int Remover(Lista* lista, int position) {
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

void Mostrar(Lista* lista) {

	if (lista->size == 0) printf("Lista vazia.\n");	

	for (int i = 0; i < lista->size; i++) {
		if (i == 0) printf("{ ");	
		printf("%d", lista->array[i]);
		printf("%s", i < lista->size - 1 ? " " : " }\n");
	}
} 

Lista newLista(int maxSize) {
	Lista lista;
	if (maxSize == 0) maxSize = 80;
	lista.maxSize = maxSize;
	lista.size = 0;
	lista.array = (int*)malloc(maxSize * sizeof(int));

    lista.InserirInicio = InserirInicio;
    lista.InserirFim = InserirFim;
    lista.Inserir = Inserir;
    lista.Mostrar = Mostrar;
	lista.RemoverInicio = RemoverInicio;
	lista.RemoverFim= RemoverFim;
	lista.Remover = Remover;

	return lista;
}

#endif /* LIB_H_ */