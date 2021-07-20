#include "binary_trees.h"
/**
 * binary_tree_size- measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: size of the tree, if tree is NULL returns 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size(tree->left) +
		binary_tree_size(tree->right) + 1);
}
/**
 * check_complete - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * @index: the position in the tree
 * @numnodes: the amount of nodes
 * Return: size of the tree, if tree is NULL returns 0
 */
int check_complete(const binary_tree_t *tree, size_t index, size_t numnodes)
{
	if (tree == NULL)
		return (1);

	if (index >= numnodes)
		return (0);

	return (check_complete(tree->left, 2 * index + 1, numnodes) &&
	       check_complete(tree->right, 2 * index + 2, numnodes));
}
/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: size of the tree, if tree is NULL returns 0
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t numnodes;

	numnodes = binary_tree_size(tree);
	if (tree == NULL)
		return (1);
	return (check_complete(tree, 0, numnodes));
}
