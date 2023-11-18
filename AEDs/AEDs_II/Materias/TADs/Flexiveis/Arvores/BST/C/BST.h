#ifndef BST_H
#define BST_H

#include "Node.h"

typedef struct BST {
	Node* root;
	void (*Insert) (int, struct BST*);
	int (*Delete) (int, struct BST*);
	void (*Print) (struct BST);
} BST;

BST newBST();

void InsertBST(int, BST* tree);
static Node* InsertBSTAux(int, Node*);
// static void InsertBSTAux(int, Node**);

int DeleteBST(int, BST*);
static int DeleteBSTAux(int, Node**);
static Node* GreatestToTheLeft(Node**, Node*);

// int DeleteBST(int, BST*);
// static Node* DeleteBSTAux(int*, Node*);
// static Node* GreatestToTheLeft(Node* root, Node* parent);

void PrintBST(BST);
static void PrintBSTAux(Node*);

#endif