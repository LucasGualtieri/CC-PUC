#include "../personagem.h"
#include <biblioteca_cpp.h>
#include <list.h>
#include <timer.h>

// clear && g++ TP02Q07.cc -I /home/lucas/PC-HOME/CC-PUC/Bibliotecas -o TP02Q07.exe && ./TP02Q07.exe < pub.in > out.txt

void printLog(Timer timer, int numeroComparacoes) {

	ofstream log("matricula_sequencial.txt");

	log << "Matrícula: 794989\t";
	log << "Tempo de execução: " << timer.elapsed() << "ms\t";
	log << "Número de comparações: " << numeroComparacoes << endl;

	log.close();
}

int main() {

	Timer timer;
	List<shared_ptr<Personagem>> list(86);

	list.populate();

	timer.start();

	int numberOfComparisons = 0;
	string searching;
	while ((searching = readString()) != "FIM") {
		if (list.SequentialSearch(searching, numberOfComparisons)) {
			cout << "SIM" << endl;
		} else {
			cout << "NAO" << endl;
		}
	}

	timer.stop();

	printLog(timer, numberOfComparisons);

	// cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}