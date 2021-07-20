#include "binary_trees.h"
/**
 * binary_tree_rotate_left- performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *root, *right_child;

	if (!tree)
		return (NULL);
	root = tree;
	right_child = tree->right;
	if (right_child)
	{
		if (right_child)
			root->right = right_child->left;
		right_child->left = root;
		root->parent = right_child;
		right_child->parent = NULL;
		return (right_child);
	}
	return (tree);
}
