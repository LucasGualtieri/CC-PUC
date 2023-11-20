#include <stdio.h>
#include <err.h>

#include "BST.h"

BST newBST() {

	BST tree;
	
	tree.root = NULL;
	tree.Insert = InsertBST;
	tree.Delete = DeleteBST;
	tree.Print = PrintBST;

	return tree;
}

void InsertBST(int value, BST* tree) {
	tree->root = InsertBSTAux(value, tree->root);
	// InsertBSTAux(value, &tree->root);
}

static Node* InsertBSTAux(int value, Node* root) {
	if (root == NULL) {
		root = newNode(value);
	} else if (value < root->value) {
		root->left = InsertBSTAux(value, root->left);
	} else if (value > root->value) {
		root->right = InsertBSTAux(value, root->right);
	} else {
		errx(0, "Erro ao inserir na árvore: '%d' já pertece à árvore.", value);
	}
	return root;
}

// static void InsertBSTAux(int value, Node** root) {
// 	if (*root == NULL) {
// 		*root = newNode(value);
// 	} else if (value < (*root)->value) {
// 		InsertBSTAux(value, &(*root)->left);
// 	} else if (value > (*root)->value) {
// 		InsertBSTAux(value, &(*root)->right);
// 	} else {
// 		errx(0, "Erro ao inserir na árvore: '%d' já pertece à árvore.", value);
// 	}
// }

int DeleteBST(int value, BST* tree) {

	if (tree->root == NULL) {
		errx(0, "Erro ao remover na árvore: Árvore vazia.");
	}

	return DeleteBSTAux(value, &tree->root);
}

static int DeleteBSTAux(int value, Node** root) {

	int removed;

	if (*root == NULL) {
		errx(0, "Erro ao remover na árvore: '%d' não pertece à árvore.", value);
	} else if (value < (*root)->value) {
		removed = DeleteBSTAux(value, &(*root)->left);
	} else if (value > (*root)->value) {
		removed = DeleteBSTAux(value, &(*root)->right);
	} else {

		Node* aux = *root;
		removed = (*root)->value;

		if ((*root)->left == NULL) {
			*root = (*root)->right;
		} else if ((*root)->right == NULL) {
			*root = (*root)->left;
		} else {
			aux = GreatestToTheLeft(&(*root)->left, *root);
		}

		free(aux);
	}

	return removed;
}

static Node* GreatestToTheLeft(Node** root, Node* parent) {

	Node* removed;

	if ((*root)->right == NULL) {
		removed = *root;
		parent->value = (*root)->value;
		*root = (*root)->left;
	} else {
		removed = GreatestToTheLeft(&(*root)->right, parent);
	}

	return removed;
}

// int DeleteBST(int value, BST* tree) {

// 	if (tree->root == NULL) {
// 		errx(0, "Erro ao remover na árvore: Árvore vazia.");
// 	}

// 	tree->root = DeleteBSTAux(&value, tree->root);

// 	return value;
// }

// static Node* DeleteBSTAux(int* value, Node* root) {

// 	if (root == NULL) {
// 		errx(0, "Erro ao remover na árvore: '%d' não pertece à árvore.", *value);
// 	} else if (*value < root->value) {
// 		root->left = DeleteBSTAux(value, root->left);
// 	} else if (*value > root->value) {
// 		root->right = DeleteBSTAux(value, root->right);
// 	} else {
// 		Node* aux = root;
// 		*value = root->value;
// 		if (root->left == NULL) {
// 			root = root->right;
// 			free(aux);
// 		} else if (root->right == NULL) {
// 			root = root->left;
// 			free(aux);
// 		} else {
// 			root->left = GreatestToTheLeft(root->left, root);
// 		}
// 	}

// 	return root;
// }

// static Node* GreatestToTheLeft(Node* root, Node* parent) {

// 	if (root->right == NULL) {
// 		parent->value = root->value;
// 		Node* aux = root;
// 		root = root->left;
// 		free(aux);
// 	} else {
// 		root->right = GreatestToTheLeft(root->right, parent);
// 	}

// 	return root;
// }

void PrintBST(BST tree) {

	if (tree.root == NULL) {
		errx(0, "Erro ao printar árvore: Árvore vazia.");
	}

	printf("{ ");
	PrintBSTAux(tree.root);
	printf("\b\b }\n");
}

// if (root->right != NULL) printf(", "); // É uma alternativa // Será que é mesmo?
static void PrintBSTAux(Node* root) {
	if (root != NULL) {
		PrintBSTAux(root->left);
		printf("%d, ", root->value);
		PrintBSTAux(root->right);
	}
}