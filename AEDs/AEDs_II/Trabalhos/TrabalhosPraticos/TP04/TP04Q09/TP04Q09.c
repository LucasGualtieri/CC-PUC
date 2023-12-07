#include "../Libs/LibsC/LibTP04.h"
#include "../Libs/LibsC/ListaDupla.h"

// clear && gcc TP04Q09.c && ./a.out < pub.in > result.txt

typedef struct HashInd {

	int tabelaLen;
	ListaDupla* array;

	void (*Inserir) (Jogador, struct HashInd);
	bool (*Pesquisar) (Jogador, Log* log, struct HashInd);
	void (*Mostrar) (struct HashInd);
	void (*Close) (struct HashInd);

} HashInd;

HashInd newHashInd();
int Hash(Jogador, HashInd);
void InserirHashInd(Jogador, HashInd);
bool PesquisarHashInd(Jogador, Log*, HashInd);
void MostrarHashInd(HashInd);
void CloseHashInd(HashInd);

int main() {

	BD BD = newBD(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	HashInd hash = newHashInd(25);

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		hash.Inserir(BD.Get(id, BD), hash);
	}

	// hash.Mostrar(hash);

	Timer timer = newTimer();
	Log log = newLog();

	BD.OrdenarPorNome(&BD); // Para possibilitar uma pesquisa binária.

	timer.Start(&timer);
	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		Jogador pesquisado = BD.PesquisarPorNome(inputPUBIN, &log, BD);
		bool resultado = hash.Pesquisar(pesquisado, &log, hash);
		printf("%s %s\n", inputPUBIN, resultado ? "SIM" : "NAO");
	}
	timer.Stop(&timer);

	log.RegistroPesquisa("794989_hashIndireta.txt", timer, log);

	hash.Close(hash);
	BD.Close(&BD);
}

HashInd newHashInd(int tabelaLen) {

	HashInd hash;

	hash.tabelaLen = tabelaLen;
	hash.array = malloc(tabelaLen * sizeof(ListaDupla));

	for (int i = 0; i < tabelaLen; i++) {
		hash.array[i] = newListaDupla();
	}

	hash.Inserir = InserirHashInd;
	hash.Pesquisar = PesquisarHashInd;
	hash.Mostrar = MostrarHashInd;

	hash.Close = CloseHashInd;

	return hash;
}

int Hash(Jogador jogador, HashInd hash) {
	return jogador.altura % hash.tabelaLen;
}

void InserirHashInd(Jogador jogador, HashInd hash) {
	int pos = Hash(jogador, hash);
	hash.array[pos].InserirFim(jogador, &hash.array[pos]);
}

bool PesquisarHashInd(Jogador jogador, Log* log, HashInd hash) {
	int pos = Hash(jogador, hash);
	return hash.array[pos].Pesquisar(jogador, log, hash.array[pos]);
}

void MostrarHashInd(HashInd hash) {
	puts("----- Tabela Hash -----");
	for (int i = 0; i < hash.tabelaLen; i++) {
		hash.array[i].Mostrar(hash.array[i]);
	}
}

void CloseHashInd(HashInd hash) {

	for (int i = 0; i < hash.tabelaLen; i++) {
		hash.array[i].Close(&hash.array[i]);
	}

	free(hash.array);
}