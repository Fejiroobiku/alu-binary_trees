#include "binary_trees.h"

/**
 *binary_tree_depth - function measures depth of a node in a binary tree
 *@tree: pointer to node to meaursure the depth
 *Return: value to return
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	int dep = 0;

	if (tree == NULL)
		return (0);
	while (tree->parent != NULL)
	{
		dep++;
		tree = tree->parent;
	}

	return (dep);
}