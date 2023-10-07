#include "../Libs/LibTP02.h"

// clear && gcc TP02Q04.c && ./a.out < pub.in > result.txt

bool PesquisaBinariaAux(String nome, int left, int right, Log* log, Jogador* array) {
	
	int mid = (left + right) / 2;
	String elementoBusca = array[mid].nome;

	if (strstr(elementoBusca, nome)) {
		log->comparacoes++;
		return true;
	}	else if (strcmp(elementoBusca, nome) < 0) {
		left = mid + 1;
	}	else right = mid - 1;
	log->comparacoes += 2;

	return left <= right ? PesquisaBinariaAux(nome, left, right, log, array) : false;
}

bool PesquisaBinaria(String nome, Log* log, Lista lista) {
	return PesquisaBinariaAux(nome, 0, lista.size - 1, log, lista.array);
}

int main() {

	Timer timer = newTimer();
	Log log = newLog();

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Lista listaJogadores = newLista(74); // Tamanho de entradas do pri.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		listaJogadores.Inserir(BD.Get(id, BD), &listaJogadores);
	}

	listaJogadores.SortByNome(listaJogadores);

	timer.Start(&timer);
	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		bool hasFound = PesquisaBinaria(inputPUBIN, &log, listaJogadores);
		printf("%s\n", hasFound ? "SIM" : "NAO");
	}
	timer.Stop(&timer);

	log.RegistroPesquisa("794989_binaria.txt", timer, log);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}