#include "binary_trees.h"
/**
 * binary_tree_rotate_right - performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *left_child, *parent;

	if (!tree)
		return (NULL);
	parent = tree->parent;
	left_child = tree->left;
	if (left_child)
	{
		tree->left = left_child->right;
		if (left_child->right)
			left_child->right->parent = tree;
		left_child->right = tree;
		tree->parent = left_child;
		left_child->parent = parent;
		if (parent)
		{
			if (parent->left == tree)
				parent->left = left_child;
			else
				parent->right = left_child;
		}
		return (left_child);
	}
	return (tree);
}
