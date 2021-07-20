#include "binary_trees.h"
/**
 * binary_tree_nodes- counts the nodes in a binary tree
 * @tree: a pointer to the root node of the tree to count the nodes
 * Return: number of leaves or 0 if the tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (0);
	return (binary_tree_nodes(tree->left) +
			binary_tree_nodes(tree->left) + 1);
}
