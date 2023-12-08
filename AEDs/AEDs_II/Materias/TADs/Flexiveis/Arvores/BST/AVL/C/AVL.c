#include <stdio.h>
#include <err.h>

#include "AVL.h"

AVL newAVL() {

	AVL tree;

	tree.root = NULL;

	tree.Insert = InsertAVL;
	// tree.Delete = DeleteAVL;

	tree.Print = PrintAVL;
	tree.PrintPre = PrintPreAVL;
	tree.Height = HeightAVL;
	tree.Close = CloseAVL;
	
	return tree;
}

void InsertAVL(int value, AVL* tree) {
	tree->root = InsertAVLAux(value, tree->root);
}

private Node* InsertAVLAux(int value, Node* root) {

	if (root == NULL) {
		root = newNode(value);
	} else if (value < root->value) {
		root->left = InsertAVLAux(value, root->left);
	} else if (value > root->value) {
		root->right = InsertAVLAux(value, root->right);
	} else {
		printf("Erro ao inserir na árvore: '%d' já pertece à árvore.", value);
		// errx(0, "Erro ao inserir na árvore: '%d' já pertece à árvore.", value);
	}

	return Balance(root);
}

private Node* Balance(Node* root) {

	root->setLevel(root);

	printf("factor: %d\n", getFactor(root));

	if (getFactor(root) == 2) {
		if (getFactor(root->right) == 1) {
			puts("SimpleRotationLeft");
			root = SimpleRotationLeft(root);
		} else {
			puts("DoubleRotationRightLeft");
			root = DoubleRotationRightLeft(root);
		}
	} else if (getFactor(root) == -2) {
		if (getFactor(root->left) == -1) {
			puts("SimpleRotationRight");
			root = SimpleRotationRight(root);
		} else {
			puts("DoubleRotationLeftRight");
			root = DoubleRotationLeftRight(root);
		}
	}

	return root;
}

private Node* SimpleRotationLeft(Node* root) {

	Node* aux = root->right;
	root->right = aux->left;
	aux->left = root;

	root->setLevel(root);
	aux->setLevel(aux);

	return aux;
}

private Node* SimpleRotationRight(Node* root) {

	Node* aux = root->left;
	root->left = aux->right;
	aux->right = root;

	root->setLevel(root);
	aux->setLevel(aux);

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

// int DeleteAVL(int value, AVL* tree) {

// 	if (tree->root == NULL) {
// 		errx(0, "Erro ao remover na árvore: Árvore vazia.");
// 	}

// 	return DeleteAVLAux(value, &tree->root);
// }

// private int DeleteAVLAux(int value, Node** root) {

// 	int removed;

// 	if (*root == NULL) {
// 		errx(0, "Erro ao remover na árvore: '%d' não pertece à árvore.", value);
// 	} else if (value < (*root)->value) {
// 		removed = DeleteAVLAux(value, &(*root)->left);
// 	} else if (value > (*root)->value) {
// 		removed = DeleteAVLAux(value, &(*root)->right);
// 	} else {

// 		Node* aux = *root;
// 		removed = (*root)->value;

// 		if ((*root)->left == NULL) {
// 			*root = (*root)->right;
// 		} else if ((*root)->right == NULL) {
// 			*root = (*root)->left;
// 		} else {
// 			aux = GreatestToTheLeft(&(*root)->left, *root);
// 		}

// 		free(aux);
// 	}

// 	return removed;
// }

// private Node* GreatestToTheLeft(Node** root, Node* parent) {

// 	Node* removed;

// 	if ((*root)->right == NULL) {
// 		removed = *root;
// 		parent->value = (*root)->value;
// 		*root = (*root)->left;
// 	} else {
// 		removed = GreatestToTheLeft(&(*root)->right, parent);
// 	}

// 	return removed;
// }

void PrintAVL(AVL tree) {

	if (tree.root == NULL) {
		errx(0, "Erro ao printar árvore: Árvore vazia.");
	}

	printf("{ ");
	PrintAVLAux(tree.root);
	printf("\b\b }\n");
}

private void PrintAVLAux(Node* root) {
	if (root != NULL) {
		PrintAVLAux(root->left);
		printf("%d, ", root->value);
		PrintAVLAux(root->right);
	}
}

void PrintPreAVL(AVL tree) {

	if (tree.root == NULL) {
		errx(0, "Erro ao printar árvore: Árvore vazia.");
	}

	printf("{ ");
	PrintPreAVLAux(tree.root);
	printf("\b\b }\n");
}

private void PrintPreAVLAux(Node* root) {
	if (root != NULL) {
		printf("%d, ", root->value);
		PrintPreAVLAux(root->left);
		PrintPreAVLAux(root->right);
	}
}

int HeightAVL(AVL tree) {

	if (tree.root == NULL) {
		errx(0, "Erro ao printar árvore: Árvore vazia.");
	}

	int left = leftHeight(tree.root);
	int right = rightHeight(tree.root);

	return left > right ? left : right;
}

void CloseAVL(AVL* tree) {
	CloseAVLAux(tree->root);
	tree->root = NULL;
}

void CloseAVLAux(Node* root) {
	if (root != NULL) {
		CloseAVLAux(root->left);
		CloseAVLAux(root->right);
		root->Close(root);
	}
}

private void CloseAVLAux(Node* root);