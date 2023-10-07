#include "../Libs/LibTP02.h"

// clear && gcc TP02Q04.c && ./a.out < pub.in > result.txt

bool PesquisaBinariaAux(String nome, int left, int right, Resultado* resultado, Jogador* array) {
	
	int mid = (left + right) / 2;
	String elementoBusca = array[mid].nome;

	if (strstr(elementoBusca, nome)) {
		resultado->comparacoes++;
		return true;
	}	else if (strcmp(elementoBusca, nome) < 0) {
		left = mid + 1;
	}	else right = mid - 1;
	resultado->comparacoes += 2;

	return left <= right ? PesquisaBinariaAux(nome, left, right, resultado, array) : false;
}

bool PesquisaBinaria(String nome, Resultado* resultado, Lista lista) {
	return PesquisaBinariaAux(nome, 0, lista.size - 1, resultado, lista.array);
}

void registroLog(Timer timer, Resultado resultado);

int main() {

	Timer timer = newTimer();
	Resultado resultado = { 0 };

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
		bool achou = PesquisaBinaria(inputPUBIN, &resultado, listaJogadores);
		printf("%s\n", achou ? "SIM" : "NAO");
	}
	timer.Stop(&timer);

	registroLog(timer, resultado);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}

void registroLog(Timer timer, Resultado resultado) {

	literal fileName = "794989_binaria.txt";
	FILE* file = fopen(fileName, "w");

	fprintf(file, "Matrícula: 794989\t");
	fprintf(file, "Tempo de execução: %fs\t", timer.Time(&timer));
	fprintf(file, "Número de comparações: %d", resultado.comparacoes);

	fclose(file);

}