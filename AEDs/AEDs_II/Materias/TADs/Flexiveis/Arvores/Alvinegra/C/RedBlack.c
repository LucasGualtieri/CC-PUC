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

private Children Balance(Node* root, Children children) {

	// if (root) printf("root: %d\n", root->value);
	// else printf("root: NULL\n");
	// if (filho) printf("filho: %d\n", filho->value);
	// else printf("filho: NULL\n");
	// if (neto) printf("neto: %d\n", neto->value);
	// else printf("neto: NULL\n");

	Node* filho = children.child;
	Node* neto = children.grandChild;

	if (neto != NULL && neto->color && filho->color) {
		if (root->value < filho->value && filho->value < neto->value) {
			// puts("SimpleRotationLeft");
			children.child = SimpleRotationLeft(root);
		} else if (root->value < filho->value && filho->value > neto->value) {
			// puts("DoubleRotationRightLeft");
			children.child = DoubleRotationRightLeft(root);
		} else if (root->value > filho->value && filho->value > neto->value) {
			// puts("SimpleRotationRight");
			children.child = SimpleRotationRight(root);
		} else {
			// puts("DoubleRotationLeftRight");
			children.child = DoubleRotationLeftRight(root);
		}
	} else {
		children.child = root;
		children.grandChild = filho;
	}

	return children;
}

private Node* SimpleRotationLeft(Node* avo) {

	Node* aux = avo->right;
	avo->right = aux->left;
	aux->left = avo;

	avo->color = true;
	aux->color = false;

	return aux;
}

private Node* SimpleRotationRight(Node* avo) {

	Node* aux = avo->left;
	avo->left = aux->right;
	aux->right = avo;

	avo->color = true;
	aux->color = false;

	return aux;
}

private Node* DoubleRotationRightLeft(Node* avo) {
	avo->right = SimpleRotationRight(avo->right);
	return SimpleRotationLeft(avo);
}

private Node* DoubleRotationLeftRight(Node* root) {
	root->left = SimpleRotationLeft(root->left);
	return SimpleRotationRight(root);
}

void InsertRedBlack(int value, RedBlack* tree) {
	tree->root = InsertRedBlackAux(value, tree->root).child;
	if (tree->root->color) tree->root->color = false;
}

private Children InsertRedBlackAux(int value, Node* root) {

	Children children;

	if (is4No(root)) fragmentar(root);

	if (root == NULL) {
		root = newNode(value, true);
		children = newChildren(NULL, NULL);
	} else if (value < root->value) {
		children = InsertRedBlackAux(value, root->left);
		root->left = children.child;
	} else if (value > root->value) {
		children = InsertRedBlackAux(value, root->right);
		root->right = children.child;
	} else {
		// printf("Erro ao inserir na árvore: '%d' já pertece à árvore.", value);
		// errx(0, "Erro ao inserir na árvore: '%d' já pertece à árvore.", value);
	}

	return Balance(root, children);
}

private bool is4No(Node* i) {
	return i && i->left && i->right && i->left->color && i->right->color;
}

private void fragmentar(Node* i) {
	printf("fragmentar\n");
	i->color = !(i->right->color = i->left->color = false);
}

private Children newChildren(Node* child, Node* grandChild) {
	Children children = { child, grandChild };
	return children;
}

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
