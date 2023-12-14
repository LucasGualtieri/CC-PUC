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

private Node* Balance(Node* root) {

	// root->setLevel(root);

	// printf("%d factor: %d\n", root->value, getFactor(root));

	// if (getFactor(root) == 2) {
	// 	if (getFactor(root->right) == 1) {
	// 		// puts("SimpleRotationLeft");
	// 		root = SimpleRotationLeft(root);
	// 	} else {
	// 		// puts("DoubleRotationRightLeft");
	// 		root = DoubleRotationRightLeft(root);
	// 	}
	// } else if (getFactor(root) == -2) {
	// 	if (getFactor(root->left) == -1) {
	// 		// puts("SimpleRotationRight");
	// 		root = SimpleRotationRight(root);
	// 	} else {
	// 		// puts("DoubleRotationLeftRight");
	// 		root = DoubleRotationLeftRight(root);
	// 	}
	// }

	return root;
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

void InsertRedBlack(int value, RedBlack* tree) {
	if (tree->root == NULL) tree->root = newNode(value);
	else InsertRedBlackAux(value, NULL, NULL, tree->root);
}

private void InsertRedBlackAux(int value, Node* avo, Node* pai, Node* i) {

	// if (is4No()) fragmentar();

	Node* neto = NULL;

	if (value > i->value) {
		if (i->right == NULL) neto = i->right = newNode(value);
		else InsertRedBlackAux(value, pai, i, i->right);
	} else if (value < i->value) {
		if (i->left == NULL) neto = i->left = newNode(value);
		else InsertRedBlackAux(value, pai, i, i->left);
	} else {
		// printf("Erro ao inserir na árvore: '%d' já pertece à árvore.", value);
		// errx(0, "Erro ao inserir na árvore: '%d' já pertece à árvore.", value);
	}

	// if (i->color && !neto) balancear(avo, pai, i, neto); 
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