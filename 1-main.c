#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

int main(void)
{
	binary_tree_t *root;

	/* Create root and children */
	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);

	/* Insert new left children */
	binary_tree_insert_left(root->right, 128);
	binary_tree_insert_left(root, 54);

	/* Debug print */
	printf("root: %d\n", root->n);
	printf("root->left: %d\n", root->left->n);
	printf("root->left->left: %d\n", root->left->left->n);
	printf("root->right: %d\n", root->right->n);
	printf("root->right->left: %d\n", root->right->left->n);

	return 0;
}