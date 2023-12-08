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

	do {
		system("clear");
		int numero = RANDOM(0, 1000);
		// int numero = readInt();
		printf("Inserindo o %d\n", numero);
		tree.Insert(numero, &tree);
		printf("Tree Height: %d\n", tree.Height(tree));
		tree.PrintPre(tree);
	} while (getchar() != ' ');

	tree.Close(&tree);

	return 0;
}