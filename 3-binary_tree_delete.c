#include "binary_trees.h"
/**
 * binary_tree_delete - Delete a binary tree.
 * @tree: A pointer to the root node of the tree to delete.
 * Return: void
 */
void binary_tree_delete(binary_tree_t *tree)
{
    /* check if the tree exists */
	if (tree != NULL)
	{
		binary_tree_delete(tree->left);
		binary_tree_delete(tree->right);
		free(tree);
	}
}
