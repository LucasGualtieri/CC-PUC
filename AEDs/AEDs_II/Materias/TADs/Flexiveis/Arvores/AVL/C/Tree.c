#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "AVL.h"

// clear && gcc Tree.c AVL.c Node.c -o Tree.out && ./Tree.out

#define RANDOM(minRange, maxRange) (rand() % ((maxRange + 1) - minRange)) + minRange

int readInt() {
	int integer;
	scanf("%d%*c", &integer);
	return integer;
}

int main() {

	AVL tree = newAVL();
	srand(time(NULL));

	for (int i = 0; i < 2000000; i++) {
		int numero = rand() % 2000000;
		tree.Insert(numero, &tree);
	}

	printf("Tree Height: %d\n", tree.Height(tree));
	
	Node* search;

	if ((search = tree.Search(12345, tree)) != NULL) {
		printf("Valor %d encontrado.\n", search->value);
	} else {
		puts("Valor não encontrado.");
	}

	tree.Close(&tree);

	return 0;
}

// do {
// 	system("clear");
// 	int numero = RANDOM(0, 1000);
// 	// int numero = readInt();
// 	printf("Inserindo o %d\n", numero);
// 	tree.Insert(numero, &tree);
// 	printf("Tree Height: %d\n", tree.Height(tree));
// 	tree.PrintPre(tree);
// } while (getchar() != ' ');