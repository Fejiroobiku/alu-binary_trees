#include "binary_trees.h"

/**
 *binary_tree_size - function measures the size of a binary tree
 *@tree: pointer to the root node of the tree to measure the size
 *Return: size of tree
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_size(tree->left) + 1 + binary_tree_size(tree->right));
}

/**
 *binary_tree_height - function measures the height of binary tree
 *@tree: pointer to the root node of the tree to measure the height
 *Return: value to return
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	int l_height, r_height;

	if (
		tree == NULL ||
		(tree->left == NULL && tree->right == NULL && tree->parent == NULL)
		)
		return (0);
	else if (tree->parent != NULL)
	{
		l_height = binary_tree_height(tree->left);
		r_height = binary_tree_height(tree->right);
		return (1 + (l_height > r_height ? l_height : r_height));
	}
	return (binary_tree_height(tree->left));
	return (binary_tree_height(tree->right));
}

/**
 *_pow - function calculates base to the power of exponent
 *@base: base to insert
 *@exponent: exponent to insert
 *Return: result
 */

size_t _pow(int base, int exponent)
{
	int result = 1;
	int i;

	if (exponent < 0)
	{
		base = 1 / base;
		exponent = -exponent;
	}

	for (i = 0; i < exponent; i++)
		result *= base;
	result *= base;
	return (result);
}

/**
 *binary_tree_is_perfect - function checks if a binary is perfect
 *@tree: pointer to the root node of the tree to check
 *Return: value to return
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (_pow(2, binary_tree_height(tree)) - 1 == binary_tree_size(tree))
		return (1);
	return (0);
}