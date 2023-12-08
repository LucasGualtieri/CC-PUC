#include "Node.h"

Node* newNode(int value) {

	Node* node = malloc(sizeof(Node));

	node->value = value;
	node->left = node->right = NULL;

	node->setLevel = SetLevelNode;
	node->Close = CloseNode;

	return node;
}

void SetLevelNode(Node* node) {
	node->level = max(leftHeight(node), rightHeight(node)) + 1;
}

void CloseNode(Node* root) {
	free(root);
}