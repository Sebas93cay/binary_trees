#include "binary_trees.h"
/**
 * binary_tree_height- measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: height of the tree, if tree is NULL returns 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l, height_r, max_height;

	if (tree == NULL || (tree->right == NULL && tree->left == NULL))
		return (0);
	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);
	max_height = (height_l > height_r) ? height_l : height_r;
	return (max_height + 1);
}

