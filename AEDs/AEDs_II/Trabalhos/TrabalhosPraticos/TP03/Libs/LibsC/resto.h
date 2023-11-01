// =======================================================================================
// --------------------------- CLASSE LISTA ---------------------------
// =======================================================================================

typedef struct Lista {

	Jogador *array;
	int maxSize, size;

	Jogador (*Get) (int id, struct Lista);
	void (*ImportDataBase) (literal filePath, struct Lista*);
	void (*Mostrar) (struct Lista);

	void (*InserirInicio) (Jogador, struct Lista*);
	void (*InserirFim) (Jogador, struct Lista*);
	void (*Inserir) (String pos, Jogador, struct Lista*);
	Jogador (*RemoverInicio) (struct Lista*);
	Jogador (*RemoverFim) (struct Lista*);
	Jogador (*Remover) (String pos, struct Lista*);

	void (*Close) (struct Lista*);

} Lista;

Jogador GetLista(int id, Lista lista) { return lista.array[id]; }

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

		BD->InserirFim(jogador, BD);

	}

}

void MostrarLista(Lista lista) {

	if (lista.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Lista vazia.\n");
		return;
	}

	for (int i = 0; i < lista.size; i++) {
		printf("[%d] ## ", i);
		lista.array[i].Mostrar(lista.array[i]);
	}
}

// ---------------------- INSERÇÕES E REMOÇÕES ----------------------

void InserirInicioLista(Jogador jogador, Lista* lista) {

	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao inserir: Lista cheia.\n");
		return;
	}

	Jogador* array = lista->array;

	for (int i = lista->size; i > 0; i--) array[i] = array[i - 1];

	array[0] = jogador.Clone(jogador);

	lista->size++;

}

void InserirFimLista(Jogador jogador, Lista* lista) {

	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao inserir: Lista cheia.\n");
		return;
	}

	lista->array[lista->size++] = jogador.Clone(jogador);

}

void InserirLista(String posStr, Jogador jogador, Lista* lista) {

	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao inserir: Lista cheia.\n");
		return;
	}

	Jogador* array = lista->array;
	int pos = atoi(posStr);

	for (int i = lista->size; i > pos; i--) array[i] = array[i - 1];

	array[pos] = jogador.Clone(jogador);

	lista->size++;

}

Jogador RemoverInicioLista(Lista* lista) {
	if (lista->size == lista->maxSize) {
		fprintf(stderr, "Erro ao remover: Lista vazia.\n");
		exit(0);
	}

	Jogador* array = lista->array;

	Jogador removido = array[0].Clone(array[0]);

	for (int i = 0; i < lista->size - 1; i++) array[i] = array[i + 1];

	lista->size--;

	return removido;
}

Jogador RemoverFimLista(Lista* lista) {
	if (lista->size == 0) {
		fprintf(stderr, "Erro ao remover: Lista vazia.\n");
		exit(0);
	}

	return lista->array[--lista->size];
}

Jogador RemoverLista(String posStr, Lista* lista) {
	if (lista->size == 0) {
		fprintf(stderr, "Erro ao remover: Lista vazia.\n");
		exit(0);
	}

	Jogador* array = lista->array;

	int pos = atoi(posStr);
	Jogador removido = array[pos];

	for (int i = pos; i < lista->size - 1; i++) array[i] = array[i + 1];

	lista->size--;

	return removido;
}


void CloseLista(Lista* lista) {
	
	for (int i = 0; i < lista->size; i++) {
		lista->array[i].Close(lista->array[i]);
	}

	free(lista->array);
	
	lista->maxSize = lista->size = 0;
}

Lista newLista(size_t maxSize) {

	Lista lista;

	if (maxSize == 0) maxSize = 80;

	lista.size = 0;
	lista.maxSize = maxSize;
	lista.array = (Jogador*)malloc(maxSize * sizeof(Jogador));

	lista.Get = GetLista;
	lista.ImportDataBase = ImportDataBaseBD;
	lista.Mostrar = MostrarLista;

	lista.InserirInicio = InserirInicioLista;
	lista.InserirFim = InserirFimLista;
	lista.Inserir = InserirLista;
	lista.RemoverInicio = RemoverInicioLista;
	lista.RemoverFim = RemoverFimLista;
	lista.Remover = RemoverLista;

	lista.Close = CloseLista;

	return lista;
}

// =======================================================================================
// --------------------------- CLASSE FILA CIRCULAR ---------------------------
// =======================================================================================

typedef struct FilaCircular {

	Jogador *array;
	int primeiro, ultimo;
	int size, maxSize;

	float (*getMediaAlturas) (struct FilaCircular);
	void (*Mostrar) (struct FilaCircular);

	float (*Inserir) (Jogador, struct FilaCircular*);
	Jogador (*Remover) (struct FilaCircular*);

	void (*Close) (struct FilaCircular*);

} FilaCircular;

float GetMediaAlturasFilaCircular(FilaCircular fila) {
	float media = 0;
	int jogador = fila.primeiro;
	for (int i = 0; i < fila.size; i++) {
		media += fila.array[jogador].altura;
		jogador = (jogador + 1) % fila.maxSize;
	}
	return media / fila.size;
}

void MostrarFilaCircular(FilaCircular fila) {

	if (fila.primeiro == fila.ultimo) {
		fprintf(stderr, "Erro ao mostrar: FilaCircular vazia.\n");
		return;
	}

	for (int i = 0, jogador = fila.primeiro; i < fila.size; i++) {
		printf("[%d] ## ", i);
		fila.array[i].Mostrar(fila.array[jogador]);
		jogador = (jogador + 1) % fila.maxSize;
	}
}

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

Jogador RemoverFilaCircular(FilaCircular* fila);

float InserirFilaCircular(Jogador jogador, FilaCircular* fila) {

	if ((fila->ultimo + 1) % fila->maxSize == fila->primeiro) {
		jogador.Close(fila->Remover(fila));
	}

	fila->size++;
	fila->array[fila->ultimo] = jogador.Clone(jogador);
	fila->ultimo = (fila->ultimo + 1) % fila->maxSize;

	return fila->getMediaAlturas(*fila);

}

Jogador RemoverFilaCircular(FilaCircular* fila) {

	if (fila->primeiro == fila->ultimo) {
		fprintf(stderr, "Erro ao remover: Pilha Circular vazia.\n");
		exit(0);
	}

	Jogador removido = fila->array[fila->primeiro];

	fila->size--;
	fila->primeiro = (fila->primeiro + 1) % fila->maxSize;

	return removido;
}

void CloseFilaCircular(FilaCircular* fila) {
	
	for (int i = 0, jogador = fila->primeiro; i < fila->size; i++) {
		fila->array[jogador].Close(fila->array[jogador]);
		jogador = (jogador + 1) % fila->maxSize;
	}

	free(fila->array);

	fila->maxSize = fila->size = 0;
}

FilaCircular newFilaCircular(size_t maxSize) {

	FilaCircular fila;

	if (maxSize == 0) maxSize = 80;

	fila.size = fila.primeiro = fila.ultimo = 0;
	fila.maxSize = maxSize + 1;
	fila.array = (Jogador*)malloc((maxSize + 1) * sizeof(Jogador));

	fila.getMediaAlturas = GetMediaAlturasFilaCircular;
	fila.Mostrar = MostrarFilaCircular;

	fila.Inserir = InserirFilaCircular;
	fila.Remover = RemoverFilaCircular;

	fila.Close = CloseFilaCircular;

	return fila;
}

// =======================================================================================
// --------------------------- CLASSE CELULA ---------------------------
// =======================================================================================

typedef struct Celula {
	Jogador jogador;
	struct Celula *prox, *ant, *baixo;
	void (*Close) (struct Celula*);
} Celula;

void CloseCelula(Celula* celula) {
	celula->jogador.Close(celula->jogador);
	free(celula);
}

Celula* newCelula(Jogador jogador, Celula* prox) {
	Celula* celula = malloc(sizeof(Celula));
	celula->jogador = jogador.Clone(jogador);
	celula->prox = prox;
	celula->ant = prox;
	celula->baixo = prox;
	celula->Close = CloseCelula;
	return celula;
}

// =======================================================================================
// --------------------------- CLASSE FILA FLEX ---------------------------
// =======================================================================================

typedef struct FilaFlex {

	Celula *primeiro, *ultimo;
	int size, maxSize;

	float (*getMediaAlturas) (struct FilaFlex);
	void (*Mostrar) (struct FilaFlex);

	float (*Inserir) (Jogador, struct FilaFlex*);
	Jogador (*Remover) (struct FilaFlex*);

	void (*Close) (struct FilaFlex*);

} FilaFlex;

float GetMediaAlturasFilaFlex(FilaFlex fila) {
	float media = 0;
	for (Celula* i = fila.primeiro; i != NULL; i = i->prox) {
		media += i->jogador.altura;
	}
	return media / fila.size;
}

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

float InserirFilaFlex(Jogador jogador, FilaFlex* fila) {

	if (fila->size == fila->maxSize) { jogador.Close(fila->Remover(fila)); }

	if (fila->size == 0) fila->primeiro = fila->ultimo = newCelula(jogador, NULL);
	else fila->ultimo = fila->ultimo->prox = newCelula(jogador, NULL);
	fila->size++;

	return fila->getMediaAlturas(*fila);

}

Jogador RemoverFilaFlex(FilaFlex* fila) {

	if (fila->size == 0) {
		fprintf(stderr, "Erro ao remover: Fila Flex vazia.\n");
		exit(0);
	}

	fila->size--;
	Celula* removida = fila->primeiro;
	fila->primeiro = removida->prox;
	Jogador removido = removida->jogador.Clone(removida->jogador);
	removida->Close(removida);

	return removido;

}

void MostrarFilaFlex(FilaFlex fila) {
	if (fila.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Fila Flex vazia.\n");
		exit(0);
	}

	int contador = 0;
	for (Celula* i = fila.primeiro; i != NULL; i = i->prox) {
		printf("[%d] ## ", contador++);
		i->jogador.Mostrar(i->jogador);
	}

}

void CloseFilaFlex(FilaFlex* fila) {
	
	Celula* i = fila->primeiro;
	while (i != NULL) {
		Celula* tmp = i;
		i = i->prox;
		tmp->Close(tmp);
	}

	fila->maxSize = fila->size = 0;
}

FilaFlex newFilaFlex(size_t maxSize) {

	FilaFlex fila;

	if (maxSize == 0) maxSize = 80;

	fila.size = 0;
	fila.primeiro = fila.ultimo = NULL;
	fila.maxSize = maxSize;

	fila.getMediaAlturas = GetMediaAlturasFilaFlex;
	fila.Mostrar = MostrarFilaFlex;

	fila.Inserir = InserirFilaFlex;
	fila.Remover = RemoverFilaFlex;

	fila.Close = CloseFilaFlex;

	return fila;
}

// =======================================================================================
// --------------------------- CLASSE PILHA FLEX ---------------------------
// =======================================================================================

typedef struct PilhaFlex {

	Celula *topo;
	int size;

	void (*Mostrar) (struct PilhaFlex);

	void (*Inserir) (Jogador, struct PilhaFlex*);
	Jogador (*Remover) (struct PilhaFlex*);

	void (*Close) (struct PilhaFlex*);

} PilhaFlex;

// ---------------------- INSERÇÃO E REMOÇÃO ----------------------

void InserirPilhaFlex(Jogador jogador, PilhaFlex* pilha) {
	pilha->topo = newCelula(jogador, pilha->topo);
	pilha->size++;
}

Jogador RemoverPilhaFlex(PilhaFlex* pilha) {

	if (pilha->topo == NULL) {
		fprintf(stderr, "Erro ao remover: Pilha Flex vazia.\n");
		exit(0);
	}

	pilha->size--;
	Celula* removida = pilha->topo;
	pilha->topo = removida->baixo;
	Jogador removido = removida->jogador.Clone(removida->jogador);
	removida->Close(removida);

	return removido;

}

void MostrarPilhaFlexRec(int contador, Celula* i) {
	if (i->baixo != NULL) MostrarPilhaFlexRec(contador - 1, i->baixo);
	printf("[%d] ## ", contador);
	i->jogador.Mostrar(i->jogador);
}

void MostrarPilhaFlex(PilhaFlex pilha) {

	if (pilha.size == 0) {
		fprintf(stderr, "Erro ao mostrar: Pilha Flex vazia.\n");
		exit(0);
	}

	MostrarPilhaFlexRec(pilha.size - 1, pilha.topo);

}

void ClosePilhaFlex(PilhaFlex* pilha) {
	
	Celula* i = pilha->topo;
	while (i != NULL) {
		Celula* tmp = i;
		i = i->prox;
		tmp->Close(tmp);
	}

	pilha->size = 0;

}

PilhaFlex newPilhaFlex() {

	PilhaFlex pilha;

	pilha.size = 0;
	pilha.topo = NULL;

	pilha.Mostrar = MostrarPilhaFlex;

	pilha.Inserir = InserirPilhaFlex;
	pilha.Remover = RemoverPilhaFlex;

	pilha.Close = ClosePilhaFlex;

	return pilha;
}
