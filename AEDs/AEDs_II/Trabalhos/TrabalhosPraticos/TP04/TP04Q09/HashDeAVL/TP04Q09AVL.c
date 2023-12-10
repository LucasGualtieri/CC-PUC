#include "../Libs/LibsC/LibTP04.h"
#include "../Libs/LibsC/AVL.h"

// clear && gcc TP04Q09AVL.c && ./a.out < pub.in > result.txt
// clear && gcc TP04Q09AVL.c && ./a.out < pubTunado.in > result.txt

typedef struct HashIndAVL {

	int tabelaLen;
	AVL* array;

	void (*Inserir) (Jogador, struct HashIndAVL);
	bool (*Pesquisar) (Jogador, Log* log, struct HashIndAVL);
	void (*Mostrar) (struct HashIndAVL);
	void (*Close) (struct HashIndAVL);

} HashIndAVL;

HashIndAVL newHashIndAVL();
int Hash(Jogador, HashIndAVL);
void InserirHashIndAVL(Jogador, HashIndAVL);
bool PesquisarHashIndAVL(Jogador, Log*, HashIndAVL);
void MostrarHashIndAVL(HashIndAVL);
void CloseHashIndAVL(HashIndAVL);

int main() {

	BD BD = newBD(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	HashIndAVL hash = newHashIndAVL(25);

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

	log.RegistroPesquisa("794989_hashIndiretaAVL.txt", timer, log);

	hash.Close(hash);
	BD.Close(&BD);
}

HashIndAVL newHashIndAVL(int tabelaLen) {

	HashIndAVL hash;

	hash.tabelaLen = tabelaLen;
	hash.array = malloc(tabelaLen * sizeof(AVL));

	for (int i = 0; i < tabelaLen; i++) {
		hash.array[i] = newAVL();
	}

	hash.Inserir = InserirHashIndAVL;
	hash.Pesquisar = PesquisarHashIndAVL;
	hash.Mostrar = MostrarHashIndAVL;

	hash.Close = CloseHashIndAVL;

	return hash;
}

int Hash(Jogador jogador, HashIndAVL hash) {
	return jogador.altura % hash.tabelaLen;
}

void InserirHashIndAVL(Jogador jogador, HashIndAVL hash) {
	int pos = Hash(jogador, hash);
	hash.array[pos].Inserir(jogador, &hash.array[pos]);
}

bool PesquisarHashIndAVL(Jogador jogador, Log* log, HashIndAVL hash) {
	int pos = Hash(jogador, hash);
	return hash.array[pos].Pesquisar(jogador, log, hash.array[pos]);
}

void MostrarHashIndAVL(HashIndAVL hash) {
	puts("----- Tabela Hash -----");
	for (int i = 0; i < hash.tabelaLen; i++) {
		hash.array[i].Mostrar(hash.array[i]);
	}
}

void CloseHashIndAVL(HashIndAVL hash) {

	for (int i = 0; i < hash.tabelaLen; i++) {
		hash.array[i].Close(&hash.array[i]);
	}

	free(hash.array);
}