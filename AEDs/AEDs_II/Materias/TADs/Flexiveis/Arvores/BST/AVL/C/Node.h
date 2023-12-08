#ifndef NODE_H
#define NODE_H

#include <stdlib.h>

#define max(val1, val2) (val1 > val2 ? val1 : val2)
#define rightHeight(root) (root->right == NULL ? 0 : root->right->level)
#define leftHeight(root) (root->left == NULL ? 0 : root->left->level)

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