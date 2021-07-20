#include "binary_trees.h"


/**
 * binary_tree_height_2- measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: height of the tree, if tree is NULL returns 0
 */
size_t binary_tree_height_2(const binary_tree_t *tree)
{
	size_t height_l, height_r, max_height;

	if (tree == NULL)
		return (0);
	height_l = binary_tree_height_2(tree->left);
	height_r = binary_tree_height_2(tree->right);
	max_height = (height_l > height_r) ? height_l : height_r;
	return (max_height + 1);
}

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: a pointer to the root node of the tree to measure the balance factor
 * Return: balance factor of the binary tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_height_2(tree->left) -
			binary_tree_height_2(tree->right));
}
