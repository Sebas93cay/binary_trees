#include "binary_trees.h"
/**
 * binary_tree_rotate_left- performs a left-rotation on a binary tree
 * @tree: a pointer to the root node of the tree to rotate
 * Return: a pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *right_child, *parent;

	if (!tree)
		return (NULL);
	parent = tree->parent;
	right_child = tree->right;
	if (right_child)
	{
		tree->right = right_child->left;
		right_child->left = tree;
		tree->parent = right_child;
		right_child->parent = parent;
		if (parent)
		{
			if (parent->left == tree)
				parent->left = right_child;
			else
				parent->right = right_child;
		}
		return (right_child);
	}
	return (tree);
}
