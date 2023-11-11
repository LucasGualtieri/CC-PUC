#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct Node {
	int value;
	struct Node *left, *right;
} Node;

Node* newNode(int value);

#endif