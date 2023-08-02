#include "../personagem.h"
#include <biblioteca_cpp.h>
#include <list.h>

// clear && g++ TP02Q05.cc -I /home/lucas/PC-HOME/CC-PUC/Bibliotecas -o TP02Q05.exe && ./TP02Q05.exe < pub.in > out.txt
// clear && g++ TP02Q05.cc -I /home/lucas/PC-HOME/CC-PUC/Bibliotecas -o TP02Q05.exe && ./TP02Q05.exe < temp.in

void InsertRemove(string action, List<shared_ptr<Personagem>>& list) {

	split actions(action, " ");

	if (actions[0] == "I") {
		list.insertEnd(NewPersonagem(actions[1]));
	} else if (actions[0] == "R") {
		cout << "(R) " << list.removeEnd()->getName() << endl;
	} else {
		throw string("Invalid action: '" + actions[0] + "'");
	}
}

int main() {

	List<shared_ptr<Personagem>> list(86);

	list.populate();

	int numberOfActions = stoi(readString());

	for (int i = 0; i < numberOfActions; i++) {
		try {
			InsertRemove(readString(), list);
		} catch (string errorMessage) {
			cout << errorMessage << endl;
		}
	}

	list.print();

	// cout << "\n******* | FIM DO PROGRAMA | *******\n\n";
	return 0;
}