#include "Node.h"

Node* newNode(int value) {

	Node* node = malloc(sizeof(Node));

	node->value = value;
	node->left = node->right = NULL;

	node->Close = CloseNode;

	return node;
}

void CloseNode(Node* root) {
	// free(root);
}