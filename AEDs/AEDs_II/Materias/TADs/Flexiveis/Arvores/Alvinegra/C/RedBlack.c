#include <stdio.h>
#include <err.h>

#include "RedBlack.h"

RedBlack newRedBlack() {

	RedBlack tree;

	tree.root = NULL;

	tree.Insert = InsertRedBlack;
	// tree.Delete = DeleteRedBlack;
	tree.Search = SearchRedBlack;

	tree.Height = HeightRedBlack;
	tree.Print = PrintRedBlack;
	tree.PrintPre = PrintPreRedBlack;
	tree.PrintPos = PrintPosRedBlack;

	tree.Close = CloseRedBlack;
	
	return tree;
}

private Node* Balance(int value, Node* avo, Children children) {


	Node* filho = children.child;
	Node* neto = children.grandChild;

	if (avo) printf("avo: %d\n", avo->value);
	else printf("avo: NULL\n");
	if (filho) printf("filho: %d\n", filho->value);
	else printf("filho: NULL\n");
	if (neto) printf("neto: %d\n", neto->value);
	else printf("neto: NULL\n");

	if (filho->color && neto != NULL && neto->color) {
		if (avo->value > filho->value && filho->value > neto->value) {
			puts("SimpleRotationLeft");
			avo = SimpleRotationLeft(avo);
		} else if (avo->value > filho->value && filho->value < neto->value) {
			puts("DoubleRotationRightLeft");
			avo = DoubleRotationRightLeft(avo);
		} else if (avo->value < filho->value && filho->value < neto->value) {
			puts("SimpleRotationRight");
			avo = SimpleRotationRight(avo);
		} else {
			puts("DoubleRotationLeftRight");
			avo = DoubleRotationLeftRight(avo);
		}
	}

	return avo;
}

private Node* SimpleRotationLeft(Node* root) {

	Node* aux = root->right;
	root->right = aux->left;
	aux->left = root;

	// root->setLevel(root);
	// aux->setLevel(aux);

	return aux;
}

private Node* SimpleRotationRight(Node* root) {

	Node* aux = root->left;
	root->left = aux->right;
	aux->right = root;

	// root->setLevel(root);
	// aux->setLevel(aux);

	return aux;
}

private Node* DoubleRotationRightLeft(Node* root) {
	root->right = SimpleRotationRight(root->right);
	return SimpleRotationLeft(root);
}

private Node* DoubleRotationLeftRight(Node* root) {
	root->left = SimpleRotationLeft(root->left);
	return SimpleRotationRight(root);
}

private Children newChildren(Node* child, Node* grandChild) {
	Children children = { child, grandChild };
	return children;
}

void InsertRedBlack(int value, RedBlack* tree) {
	if (tree->root == NULL) tree->root = newNode(value, false);
	else if (value < tree->root->value) tree->root->left = InsertRedBlackAux(value, tree->root).child;
	else tree->root->right = InsertRedBlackAux(value, tree->root).child;
}

private Children InsertRedBlackAux(int value, Node* i) {

	// if (is4No()) fragmentar();

	Children children;

	if (i == NULL) {
		i = newNode(value, true);
		children = newChildren(i, NULL);
	} else if (value < i->value) {
		children = InsertRedBlackAux(value, i->left);
		i->left = children.child;
		// newChildren(i, children.child);
	} else if (value > i->value) {
		children = InsertRedBlackAux(value, i->right);
		i->right = children.child;
		// newChildren(i, children.child);
	} else {
		// printf("Erro ao inserir na árvore: '%d' já pertece à árvore.", value);
		// errx(0, "Erro ao inserir na árvore: '%d' já pertece à árvore.", value);
	}

	// return newChildren(Balance(value, i, children), children);
	i = Balance(value, i, children);

	return children;
}

// private void InsertRedBlackAux(int value, Node* avo, Node* pai, Node* i) {

// 	if (i == NULL) {
// 		i = newNode(value);
// 	} else if (value < i->value) {
// 		i->left = InsertRedBlackAux(value, i->left);
// 	} else if (value > i->value) {
// 		i->right = InsertRedBlackAux(value, i->right);
// 	} else {
// 		// printf("Erro ao inserir na árvore: '%d' já pertece à árvore.", value);
// 		// errx(0, "Erro ao inserir na árvore: '%d' já pertece à árvore.", value);
// 	}

// 	Balance(root);
// }

Node* SearchRedBlack(int value, RedBlack tree) {
	return SearchRedBlackAux(value, tree.root);
}

private Node* SearchRedBlackAux(int value, Node* root) {

	if (root == NULL) {
		// printf("Erro ao pesquisar na árvore: '%d' não pertece à árvore.", value);
		// errx(0, "Erro ao pesquisar na árvore: '%d' não pertece à árvore.", value);
	} else if (value < root->value) {
		root = SearchRedBlackAux(value, root->left);
	} else if (value > root->value) {
		root = SearchRedBlackAux(value, root->right);
	}

	return root;
}

int HeightRedBlack(RedBlack tree) {

	if (tree.root == NULL) {
		errx(0, "Erro ao calcular altura da árvore: Árvore vazia.");
	}

	return 0;

	// return max(leftHeight(tree.root), rightHeight(tree.root));
}

void PrintRedBlack(RedBlack tree) {

	if (tree.root == NULL) {
		errx(0, "Erro ao printar árvore: Árvore vazia.");
	}

	printf("{ ");
	PrintRedBlackAux(tree.root);
	printf("\b\b }\n");
}

private void PrintRedBlackAux(Node* root) {
	if (root != NULL) {
		PrintRedBlackAux(root->left);
		printf("%d, ", root->value);
		PrintRedBlackAux(root->right);
	}
}

void PrintPreRedBlack(RedBlack tree) {

	if (tree.root == NULL) {
		errx(0, "Erro ao printar árvore: Árvore vazia.");
	}

	printf("{ ");
	PrintPreRedBlackAux(tree.root);
	printf("\b\b }\n");
}

private void PrintPreRedBlackAux(Node* root) {
	if (root != NULL) {
		printf("%d, ", root->value);
		PrintPreRedBlackAux(root->left);
		PrintPreRedBlackAux(root->right);
	}
}

void PrintPosRedBlack(RedBlack tree) {

	if (tree.root == NULL) {
		errx(0, "Erro ao printar árvore: Árvore vazia.");
	}

	printf("{ ");
	PrintPosRedBlackAux(tree.root);
	printf("\b\b }\n");
}

private void PrintPosRedBlackAux(Node* root) {
	if (root != NULL) {
		PrintPosRedBlackAux(root->left);
		PrintPosRedBlackAux(root->right);
		printf("%d, ", root->value);
	}
}

void CloseRedBlack(RedBlack* tree) {
	CloseRedBlackAux(tree->root);
	tree->root = NULL;
}

void CloseRedBlackAux(Node* root) {
	if (root != NULL) {
		CloseRedBlackAux(root->left);
		CloseRedBlackAux(root->right);
		root->Close(root);
	}
}