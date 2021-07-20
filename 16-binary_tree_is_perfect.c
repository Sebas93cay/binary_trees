#include "binary_trees.h"

/**
 * binary_tree_size_2 - measures the size of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: size of the tree, if tree is NULL returns 0
 */
size_t binary_tree_size_2(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (binary_tree_size_2(tree->left) +
			binary_tree_size_2(tree->right) + 1);
}

/**
 * binary_tree_height_2- measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: height of the tree, if tree is NULL returns 0
 */
size_t binary_tree_height_3(const binary_tree_t *tree)
{
	size_t height_l, height_r, max_height;

	if (tree == NULL)
		return (0);
	height_l = binary_tree_height_3(tree->left);
	height_r = binary_tree_height_3(tree->right);
	max_height = (height_l > height_r) ? height_l : height_r;
	return (max_height + 1);
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: a pointer to the root node of the tree to check
 * Return: if tree is perfect returns 1, otherwise 0
 * if tree is null returns 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height_r, height_l, size_r, size_l;

	if (!tree)
		return (0);
	height_l = binary_tree_height_3(tree->left);
	height_r = binary_tree_height_3(tree->right);
	size_l = binary_tree_size_2(tree->left);
	size_r = binary_tree_size_2(tree->right);
	if (height_r == height_l &&
			size_r == size_l &&
			size_l == height_l * height_l - 1)
		return (1);
	return (0);
}
