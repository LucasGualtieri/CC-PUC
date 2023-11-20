#include "Node.h"

Node* newNode(int value) {
	Node* node = malloc(sizeof(Node));
	node->value = value;
	node->left = node->right = NULL;
	return node;
}