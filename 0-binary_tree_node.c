#include "binary_trees.h"

/**
 * binary_tree_node-Create a new node in the tree
 * @parent: pointer to node parent
 * @value: value field
 * Return: A pointer to the new node.
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = NULL;

	new = malloc(sizeof(binary_tree_t));
	if (new)
	{
		new->n = value;
		new->parent = parent;
		new->left = new->right = NULL;
		return (new);
	}
	return (NULL);
}
