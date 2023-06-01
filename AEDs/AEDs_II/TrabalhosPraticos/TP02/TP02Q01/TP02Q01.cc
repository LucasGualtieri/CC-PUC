#include "../personagem.h"
#include <biblioteca_cpp.h>
#include <list.h>

// clear && g++ TP02Q01.cc -I /home/lucas/PC-HOME/CC-PUC/Bibliotecas -o TP02Q01.exe && ./TP02Q01.exe < pub.in > out.txt

int main() {

	List<shared_ptr<Personagem>> list(86);

	list.populate();

	for (int i = 0; i < list.getSize(); i++) {
		list[i]->print();
		if (i < list.getSize() - 1) cout << endl;
	}

	// cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}