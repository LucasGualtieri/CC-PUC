#include "../TP02Libs/LibsC/LibTP02.h"

// clear && gcc TP02Q04.c && ./a.out < pub.in > result.txt

bool PesquisaBinariaAux(String nome, Jogador* array, int left, int right) {
	int mid = (left + right) / 2;
	String elementoBusca = array[mid].getNome(array[mid]);

	int result = strcmp(elementoBusca, nome);

	if (result == 0) return true;
	else if (result < 0) left = mid + 1;
	else right = mid - 1;

	return left <= right ? PesquisaBinariaAux(nome, array, left, right) : false;
}

bool PesquisaBinaria(String nome, Fila fila) {
	return PesquisaBinariaAux(nome, fila.array, 0, fila.size - 1);
}

int main() {

	Fila BD = newFila(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Fila listaJogadores = newFila(49); // Tamanho de entradada do Pub.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		listaJogadores.Inserir(BD.Get(id, BD), &listaJogadores);
	}

	listaJogadores.Sort(listaJogadores);
	// listaJogadores.Mostrar(listaJogadores);

	// Timer timer = newTimer();
	// timer.Start(&tempoTotal);
	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		bool resultado = PesquisaBinaria(inputPUBIN, listaJogadores);
		printf("%s\n", resultado ? "SIM" : "NAO");
	}
	// double tempoTotal = timer.Stop(&timer);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);


}

#define strcmpr(jog1, jog2) strcmp(jog1.getNome(jog1), jog2.getNome(jog2))

void SortFila(Fila fila) {
	int N = fila.size;
	Jogador* array = fila.array;

	int j;
	Jogador temp;
	for (int i = 1; i < N; i++) {
		temp = array[i];
		j = i - 1;
		while (j >= 0 && strcmpr(array[j], temp) > 0) {
			array[j-- + 1] = array[j];
		}
		array[j + 1] = temp;
	}
}