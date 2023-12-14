#ifndef RED_BLACK_H
#define RED_BLACK_H

#include "Node.h"

#define private static

typedef struct RedBlack {

	Node* root;

	void (*Insert) (int, struct RedBlack*);
	int (*Delete) (int, struct RedBlack*);
	Node* (*Search) (int, struct RedBlack);

	void (*Print) (struct RedBlack);
	void (*PrintPre) (struct RedBlack);
	void (*PrintPos) (struct RedBlack);

	int (*Height) (struct RedBlack);

	void (*Close) (struct RedBlack*);

} RedBlack;

RedBlack newRedBlack();

private Node* Balance(Node*);
private Node* SimpleRotationLeft(Node*);
private Node* SimpleRotationRight(Node*);
private Node* DoubleRotationRightLeft(Node*);
private Node* DoubleRotationLeftRight(Node*);

void InsertRedBlack(int, RedBlack*);
private void InsertRedBlackAux(int, Node*, Node*, Node*);

// int DeleteRedBlack(int, RedBlack*);
// private int DeleteRedBlackAux(int, Node**);
// private Node* GreatestToTheLeft(Node**, Node*);

Node* SearchRedBlack(int, RedBlack);
private Node* SearchRedBlackAux(int, Node*);

int HeightRedBlack(RedBlack);

void PrintRedBlack(RedBlack);
private void PrintRedBlackAux(Node*);

void PrintPreRedBlack(RedBlack);
private void PrintPreRedBlackAux(Node*);

void PrintPosRedBlack(RedBlack);
private void PrintPosRedBlackAux(Node*);

void CloseRedBlack(RedBlack*);
private void CloseRedBlackAux(Node* root);

#endif