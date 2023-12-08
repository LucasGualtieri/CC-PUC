#ifndef AVL_H
#define AVL_H

#include "Node.h"

#define private static

typedef struct AVL {

	Node* root;

	void (*Insert) (int, struct AVL*);
	int (*Delete) (int, struct AVL*);

	void (*Print) (struct AVL);
	void (*PrintPre) (struct AVL);

	int (*Height) (struct AVL);

	void (*Close) (struct AVL*);
} AVL;

AVL newAVL();

void InsertAVL(int, AVL* tree);
private Node* InsertAVLAux(int, Node*);

#define max(val1, val2) (val1 > val2 ? val1 : val2)
#define getFactor(root) (rightHeight(root) - leftHeight(root))
#define rightHeight(root) (root->right == NULL ? 0 : root->right->level)
#define leftHeight(root) (root->left == NULL ? 0 : root->left->level)

private Node* Balance(Node* root);
private Node* SimpleRotationLeft(Node* root);
private Node* SimpleRotationRight(Node* root);
private Node* DoubleRotationRightLeft(Node* root);
private Node* DoubleRotationLeftRight(Node* root);

// int DeleteAVL(int, AVL*);
// private int DeleteAVLAux(int, Node**);
// private Node* GreatestToTheLeft(Node**, Node*);

void PrintPreAVL(AVL);
private void PrintPreAVLAux(Node*);

void PrintAVL(AVL);
private void PrintAVLAux(Node*);

int HeightAVL(AVL);
private int HeightAVLAux(Node*, int);

void CloseAVL(AVL*);
private void CloseAVLAux(Node* root);

#endif