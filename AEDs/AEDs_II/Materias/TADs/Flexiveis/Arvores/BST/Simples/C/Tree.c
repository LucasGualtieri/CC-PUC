#include <stdio.h>
#include <stdlib.h>
#include "BST.h"

// clear && gcc Tree.c BST.c Node.c -o Tree.out && ./Tree.out

int main() {

	BST tree = newBST();

	tree.Insert(5, &tree);
	tree.Insert(2, &tree);
	tree.Insert(1, &tree);
	tree.Insert(3, &tree);
	tree.Insert(0, &tree);
	tree.Insert(4, &tree);
	tree.Insert(8, &tree);
	tree.Insert(7, &tree);
	tree.Insert(6, &tree);
	tree.Insert(9, &tree);
	tree.Insert(10, &tree);

	tree.Print(tree);

	tree.Delete(10, &tree);
	tree.Print(tree);
	tree.Delete(9, &tree);
	tree.Print(tree);
	tree.Delete(6, &tree);
	tree.Print(tree);
	tree.Delete(7, &tree);
	tree.Print(tree);
	tree.Delete(8, &tree);
	tree.Print(tree);
	tree.Delete(5, &tree);
	tree.Print(tree);
	tree.Delete(2, &tree);
	tree.Print(tree);
	tree.Delete(1, &tree);
	tree.Print(tree);
	tree.Delete(3, &tree);
	tree.Print(tree);
	tree.Delete(0, &tree);
	tree.Print(tree);
	tree.Delete(4, &tree);
	tree.Print(tree);

	return 0;

}