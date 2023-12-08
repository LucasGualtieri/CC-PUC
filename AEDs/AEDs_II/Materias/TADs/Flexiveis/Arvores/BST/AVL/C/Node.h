#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

typedef struct Node {

	int value, level;
	struct Node *left, *right;

	void (*setLevel) (struct Node*);
	void (*Close) (struct Node*);

} Node;

Node* newNode(int value);
void SetLevelNode(struct Node*);
void CloseNode(struct Node*);

#endif