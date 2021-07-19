#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to parent node
 * @value: value field
 * Return: left node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *left_new;

	if (!parent)
		return (NULL);

	left_new = malloc(sizeof(binary_tree_t));

	if (!left_new)
		return (NULL);

	left_new->n = value;
	left_new->parent = parent;
	left_new->right = NULL;
	left_new->left = parent->left;

	if (parent->left != NULL)
		parent->left->parent = left_new;

	parent->left = left_new;

	return (left_new);
}
