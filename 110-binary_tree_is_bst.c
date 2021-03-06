#include "binary_trees.h"

/**
 * check_bst_compare - checks if a binary tree is a valid Binary Search Tree
 * and check if all node's values are between min_value and max_value
 * @tree: a pointer to the root node of the tree to check
 * @has_min: turns on check on min_value
 * @min_value: min_value
 * @has_max: turns on check on max_value
 * @max_value: max_value
 * Return: 1 if tree is a valid BST, and 0 otherwise or a value is outside
 * min_value and max_value
 */
int check_bst_compare(const binary_tree_t *tree, int has_min, int min_value,
		int has_max, int max_value)
{
	if (!tree)
		return (1);

	if (has_min && tree->n <= min_value)
		return (0);
	if (has_max && tree->n >= max_value)
		return (0);
	if (check_bst_compare(tree->left, has_min, min_value, 1, tree->n) &&
			check_bst_compare(tree->right, 1, tree->n, has_max, max_value))
		return (1);
	return (0);
}

/**
 * binary_tree_is_bst- checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * Return: 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (check_bst_compare(tree, 0, 0, 0, 0));
}
