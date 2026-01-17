#include <stdlib.h>
#include <stdio.h>
#include "binary_trees.h"

int main(void)
{
	binary_tree_t *root;

	root = binary_tree_node(NULL, 98);
	root->left = binary_tree_node(root, 12);
	root->right = binary_tree_node(root, 402);

	binary_tree_insert_right(root->left, 54);
	binary_tree_insert_right(root, 128);

	printf("root: %d\n", root->n);
	printf("root->left: %d\n", root->left->n);
	printf("root->left->right: %d\n", root->left->right->n);
	printf("root->right: %d\n", root->right->n);
	printf("root->right->right: %d\n", root->right->right->n);

	return 0;
}