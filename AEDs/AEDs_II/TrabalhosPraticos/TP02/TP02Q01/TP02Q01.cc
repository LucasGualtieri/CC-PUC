#include "../personagem.h"
#include <biblioteca_cpp.h>
#include <list.h>
#include <split.h>

// clear && g++ teste.cc -I /home/lucas/PC-HOME/CC-PUC/Bibliotecas -o teste.exe && ./teste.exe < pub.in > out.txt

// void Insertremove(string nome) {

// 	split array(nome, " ");

// 	cout << array[0] << endl;
// 	cout << array[1] << endl;
// }

int main() {

	List<shared_ptr<Personagem>> list(86);

	list.populate();

	// string listActions;
	// while (getline(cin, listActions)) {
	// 	// Insertremove(listActions);
	// }

	list.print();

	// cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}