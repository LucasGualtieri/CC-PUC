#include "Node.h"
#include "RedBlack.h"

Node* newNode(int value, bool color) {

	Node* node = malloc(sizeof(Node));

	node->color = color;
	node->value = value;
	node->left = node->right = NULL;

	node->Close = CloseNode;

	return node;
}

void CloseNode(Node* root) {
	free(root);
}