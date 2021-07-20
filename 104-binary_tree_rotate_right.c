#include "binary_trees.h"
/**
 * binary_tree_rotate_left- performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *root, *left_child;

	if (!tree)
		return (NULL);
	root = tree;
	left_child = tree->left;
	if (left_child)
	{
		if (left_child)
			root->left = left_child->left;
		left_child->right = root;
		root->parent = left_child;
		left_child->parent = NULL;
		return (left_child);
	}
	return (tree);
}
