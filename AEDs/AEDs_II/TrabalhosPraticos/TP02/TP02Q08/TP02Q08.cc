#include "../personagem.h"
#include <biblioteca_cpp.h>
#include <list.h>
#include <timer.h>

// clear && g++ TP02Q08.cc -I /home/lucas/PC-HOME/CC-PUC/Bibliotecas -o TP02Q08.exe && ./TP02Q08.exe < pub.in > out.txt

void criarLog(Timer timer, int numeroComparacoes) {

	ofstream log("matricula_sequencial.txt");

	log << "Matrícula: 794989\t";
	log << "Tempo Execucao: " << timer.elapsed() << "ms\t";
	log << "Número de comparações: " + to_string(numeroComparacoes) << endl;

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
		if (list.BinarySearch(searching, numberOfComparisons)) {
			cout << "SIM" << endl;
		} else {
			cout << "NAO" << endl;
		}
	}

	timer.stop();

	criarLog(timer, numberOfComparisons);

	// cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}