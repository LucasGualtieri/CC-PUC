#include "../Libs/LibTP02.h"

// clear && gcc TP02Q06.c && ./a.out < pub.in > result.txt

#define strcmpr(jog1, jog2) strcmp(jog1.nome, jog2.nome)

void SelectionSortRecursivo(int i, int j, int menor, Resultado* resultado, Lista array) {

	if (j < array.size) {
		if (strcmpr(array.array[menor], array.array[j]) > 0) menor = j;
		resultado->comparacoes++;
		SelectionSortRecursivo(i, j + 1, menor, resultado, array);
	} else {
		swap(&array.array[i], &array.array[menor]);
		resultado->movimentacoes += 3;
	}

	if (++i < array.size - 1 && j == i) {
		SelectionSortRecursivo(i, i + 1, i, resultado, array);
	}

}

void SelectionSort(Resultado* resultado, Lista array) {
	SelectionSortRecursivo(0, 1, 0, resultado, array);
}

void registroLog(Timer timer, Resultado resultado);

int main() {
	
	Timer timer = newTimer();
	Resultado resultado = { 0, 0 };

	Lista BD = newLista(BD_SIZE);
	BD.ImportDataBase("../tmp/players.csv", &BD);

	Lista listaJogadores = newLista(465); // Tamanho de entradas do pri.in

	char inputPUBIN[STR_MAX_LEN];

	while (strcmp(readStr(0, inputPUBIN), "FIM")) {
		int id = atoi(inputPUBIN);
		listaJogadores.Inserir(BD.Get(id, BD), &listaJogadores);
	}

	timer.Start(&timer);
	SelectionSort(&resultado, listaJogadores);
	timer.Stop(&timer);

	listaJogadores.Mostrar(listaJogadores);

	registroLog(timer, resultado);

	listaJogadores.Close(&listaJogadores);
	BD.Close(&BD);

}

void registroLog(Timer timer, Resultado resultado) {

	literal fileName = "794989_selecaoRecursiva.txt";
	FILE* file = fopen(fileName, "w");

	fprintf(file, "Matrícula: 794989\t");
	fprintf(file, "Tempo de execução: %fs\t", timer.Time(&timer));
	fprintf(file, "Número de comparações: %d\t", resultado.comparacoes);
	fprintf(file, "Número de movimentações: %d", resultado.movimentacoes);

	fclose(file);

}