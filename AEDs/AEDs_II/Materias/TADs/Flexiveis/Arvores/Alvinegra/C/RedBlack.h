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

typedef struct Children {
	Node *child, *grandChild;
} Children;

RedBlack newRedBlack();

private Node* SimpleRotationLeft(Node*);
private Node* SimpleRotationRight(Node*);
private Node* DoubleRotationRightLeft(Node*);
private Node* DoubleRotationLeftRight(Node*);
private Children Balance(Node*, Children children);

void InsertRedBlack(int, RedBlack*);
private Children InsertRedBlackAux(int, Node*);

private bool is4No(Node* i);
private void fragmentar(Node* i);
private Children newChildren(Node* child, Node* grandChild);

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