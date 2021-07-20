#include "binary_trees.h"
/**
 * binary_tree_height_4 - measures the height of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: height of the tree, if tree is NULL returns 0
 */
size_t binary_tree_height_4(const binary_tree_t *tree)
{
	size_t height_l, height_r, max_height;

	if (tree == NULL)
		return (0);
	height_l = binary_tree_height_4(tree->left);
	height_r = binary_tree_height_4(tree->right);
	max_height = (height_l > height_r) ? height_l : height_r;
	return (max_height + 1);
}


/**
 * traverse_level - traverse a level in a binary tree
 * @tree: tree to traverse level
 * @level: level to traverse
 * @func: a pointer to a function to call for each node.
 */
void traverse_level(const binary_tree_t *tree, int level, void (*func)(int))
{
	if (!tree)
		return;
	if (level == 0)
		func(tree->n);
	else
	{
		traverse_level(tree->left, level - 1, func);
		traverse_level(tree->right, level - 1, func);
	}
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: tree to traverse level
 * @level: level to traverse
 * @func: a pointer to a function to call for each node.
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	unsigned int level;

	for (level = 0; level < binary_tree_height_4(tree); level++)
	{
		traverse_level(tree, level, func);
	}
}
