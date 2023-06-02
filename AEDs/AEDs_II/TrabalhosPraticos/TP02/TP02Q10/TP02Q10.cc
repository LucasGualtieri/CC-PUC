#include "../personagem.h"
#include <biblioteca_cpp.h>
#include <list.h>
#include <timer.h>

// clear && g++ TP02Q10.cc -I /home/lucas/PC-HOME/CC-PUC/Bibliotecas -o TP02Q10.exe && ./TP02Q10.exe < pub.in > out.txt

int main() {

	Timer timer;
	List<shared_ptr<Personagem>> list(86);

	list.populate();

	timer.start();

	int numberOfComparisons = list.SelectionRecSort();

	timer.stop();

	for (int i = 0; i < list.getSize(); i++) {
		list[i]->print();
	}

	printLog(timer, numberOfComparisons);

	// cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}