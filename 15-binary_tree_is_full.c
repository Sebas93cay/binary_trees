#include "binary_trees.h"

/**
 * binary_tree_is_full- checks if a binary tree is full
 * @tree: a pointer to the root node of the tree to check
 * Return: if tree is full returns 1, otherwise 0
 * if tree is null returns 0
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int children = 0;

	if (!tree)
		return (0);
	if (tree->left)
		children++;
	if (tree->right)
		children++;
	if (children == 0)
		return (1);
	else if (children == 1)
		return (0);
	return (binary_tree_is_full(tree->left) *
			binary_tree_is_full(tree->right));
}
