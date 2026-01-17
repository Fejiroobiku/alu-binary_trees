#include "binary_trees.h"

/**
 * binary_tree_leaves - count the number of leaves
 *@tree: pointer to first node in tree
 * Return: number of leaves in tree
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (
		binary_tree_leaves(tree->left) +
		(
		 tree->left == NULL && tree->right == NULL &&
		 (tree->parent->parent->left != NULL &&
		  tree->parent->parent->right != NULL) ? 1 : 0) +
		binary_tree_leaves(tree->right)
		);
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
		return (1 + (l_height >= r_height ? l_height : r_height));
	}
	return (binary_tree_height(tree->left));
	return (binary_tree_height(tree->right));
}

/**
 * right_height - calculates the height of the right subtree
 * @tree: pointer to first node in right subtree
 * Return: height of right subtree
 */

int right_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->right) + 1);
}

/**
 * left_height - calculate the height of the left subtree
 * @tree: pointer to first in left subtree
 * Return: height of left subtree
 */

int left_height(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (binary_tree_height(tree->left) + 1);
}

/**
 *binary_tree_balance - function measures the balance factor of a binary tree
 *@tree: pointer to the root node of the tree to measure the balance factor
 *Return: tree balance
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int right, left;

	if (tree == NULL)
		return (0);
	right = right_height(tree->right);
	left = left_height(tree->left);
	if (
		left == 0 && tree->right != NULL &&
		(binary_tree_leaves(tree->right) % 2 != 0)
		)
		return (-right - 1);
	else if (
		right == 0 && tree->left != NULL &&
		(binary_tree_leaves(tree->left) % 2 != 0)
		)
		return (left + 1);
	return (left - right);
}