#include <biblioteca_c.h>

// clear && gcc trinca.c -I /home/lucas/CC-PUC/Bibliotecas -o trinca.exe && ./trinca.exe < pub.in > out.txt
// clear && gcc trinca.c -lm -o trinca.exe && ./trinca.exe < pub.in > out.txt

void printLista(String* lista, String character) {
	int listaLength = stringsArrayLen(lista);
	for (int i = 0; i < listaLength; i++) {
		printf("%s%s", lista[i], i < listaLength - 1 ? " " : character);
	}
}

int main() {

	String* listaAtual = split(getstr(0), " ", 1);
	String* listaNova = split(getstr(0), " ", 1);
	String amigo = getstr(0);

	if (strcmp(amigo, "Nao")) {

		char** position = listaAtual;
		for (int i = 0; strcmp(listaAtual[i], amigo); i++) {
			printf("%s ", listaAtual[i]);
			position++;
		}

		printLista(listaNova, " ");
		printLista(position, "\n");

	} else {
		printLista(listaAtual, " ");
		printLista(listaNova, "\n");
	}

	free(amigo);
	freeSplit(listaAtual);
	freeSplit(listaNova);

	puts("\n******* | FIM DO PROGRAMA | *******\n");
	return 0;
}