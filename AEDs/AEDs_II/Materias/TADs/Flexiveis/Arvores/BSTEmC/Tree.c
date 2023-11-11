#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

// clear && gcc Tree.c BST.c Node.c -o Tree.out && ./Tree.out

int main() {

	BST tree = newBST();

	tree.Insert(3, &tree);
	tree.Insert(1, &tree);
	tree.Insert(2, &tree);

	tree.Print(tree);

	tree.Delete(5, &tree); // Terminar de fazer a remoção

	tree.Print(tree);

	return 0;

}