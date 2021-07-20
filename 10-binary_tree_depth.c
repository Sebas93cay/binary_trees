#include "binary_trees.h"
/**
 * binary_tree_depth- measures the depth of a binary tree
 * @tree: a pointer to the root node of the tree to measure the height.
 * Return: height of the tree, if tree is NULL returns 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree || tree->parent == NULL)
		return (0);
	return(binary_tree_depth(tree->parent) + 1);
}


