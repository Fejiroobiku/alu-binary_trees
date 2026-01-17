#include "binary_trees.h"

/**
 *binary_tree_is_root - function checks if node is a root
 *@node: pointer to the node to check
 *Return: value to return
 */

int binary_tree_is_root(const binary_tree_t *node)
{
	if (node == NULL || node->parent != NULL)
		return (0);
	return  (1);
}