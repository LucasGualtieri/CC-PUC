#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct Node {

	int value, level;
	struct Node *left, *right;

	void (*Close) (struct Node*);

} Node;

Node* newNode(int value);
void CloseNode(struct Node*);

#endif