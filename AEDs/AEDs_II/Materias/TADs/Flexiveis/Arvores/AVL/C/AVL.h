#ifndef AVL_H
#define AVL_H

#include "Node.h"

#define private static

typedef struct AVL {

	Node* root;

	void (*Insert) (int, struct AVL*);
	int (*Delete) (int, struct AVL*);
	Node* (*Search) (int, struct AVL);

	void (*Print) (struct AVL);
	void (*PrintPre) (struct AVL);
	void (*PrintPos) (struct AVL);

	int (*Height) (struct AVL);

	void (*Close) (struct AVL*);

} AVL;

AVL newAVL();

#define max(val1, val2) (val1 > val2 ? val1 : val2)
#define getFactor(root) (rightHeight(root) - leftHeight(root))
#define rightHeight(root) (root->right == NULL ? 0 : root->right->level)
#define leftHeight(root) (root->left == NULL ? 0 : root->left->level)

private Node* Balance(Node*);
private Node* SimpleRotationLeft(Node*);
private Node* SimpleRotationRight(Node*);
private Node* DoubleRotationRightLeft(Node*);
private Node* DoubleRotationLeftRight(Node*);

void InsertAVL(int, AVL*);
private Node* InsertAVLAux(int, Node*);

// int DeleteAVL(int, AVL*);
// private int DeleteAVLAux(int, Node**);
// private Node* GreatestToTheLeft(Node**, Node*);

Node* SearchAVL(int, AVL);
private Node* SearchAVLAux(int, Node*);

int HeightAVL(AVL);

void PrintAVL(AVL);
private void PrintAVLAux(Node*);

void PrintPreAVL(AVL);
private void PrintPreAVLAux(Node*);

void PrintPosAVL(AVL);
private void PrintPosAVLAux(Node*);

void CloseAVL(AVL*);
private void CloseAVLAux(Node* root);

#endif