#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "RedBlack.h"
#include "String.h"

// clear && gcc Tree.c RedBlack.c Node.c -o Tree.out && ./Tree.out
// clear && gcc Tree.c -o Tree.out && ./Tree.out

#define RANDOM(minRange, maxRange) (rand() % ((maxRange + 1) - minRange)) + minRange

int readInt() {
	int integer;
	scanf("%d%*c", &integer);
	return integer;
}

int main() {

	RedBlack tree = newRedBlack();

	String string;

	while (strcmp((readString(&string)).s, "FIM")) {
		int integer = atoi(string.s);
		tree.Insert(integer, &tree);
		// printf("Tree Height: %d\n", tree.Height(tree));
		tree.PrintPre(tree);
	}

	tree.Close(&tree);

	return 0;
}