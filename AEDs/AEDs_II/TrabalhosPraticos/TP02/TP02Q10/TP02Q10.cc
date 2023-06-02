#include "../personagem.h"
#include <biblioteca_cpp.h>
#include <list.h>
#include <timer.h>

// clear && g++ TP02Q10.cc -I /home/lucas/PC-HOME/CC-PUC/Bibliotecas -o TP02Q10.exe && ./TP02Q10.exe < pub.in > out.txt
// clear && g++ TP02Q10.cc -I /home/lucas/PC-HOME/CC-PUC/Bibliotecas -o TP02Q10.exe && ./TP02Q10.exe < unsorted.in > out.txt

void printLog(Timer timer, int numeroComparacoes, int numberOfSwaps) {

	ofstream log("matricula_selecaoRecursiva.txt");

	log << "Matrícula: 794989\t";
	log << "Tempo de execução: " << timer.elapsed() << "ms\t";
	log << "Número de movimentações: " << numberOfSwaps << " \t";
	log << "Número de comparações: " << numeroComparacoes << endl;

	log.close();
}

int main() {

	Timer timer;
	List<shared_ptr<Personagem>> list(86);

	list.populate();

	timer.start();

	int numberOfSwaps = 0;
	int numberOfComparisons = list.SelectionRecSort(numberOfSwaps);

	timer.stop();

	list.print(false);

	printLog(timer, numberOfComparisons, numberOfSwaps);

	// cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}