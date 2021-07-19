#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a node as the left-child of another node
 * @parent: pointer to parent node
 * @value: value field
 * Return: left node
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_left;
    /* check if exist root */
	if (!parent)
		return (NULL);
    /* if exists, create new node at left */
	new_left = malloc(sizeof(binary_tree_t));
    /* check if left node was created */
	if (!new_left)
		return (NULL);
    /* assing values and prepare pointers */
	new_left->n = value;
	new_left->parent = parent;
    /* because is left, right points to NULL*/
	new_left->right = NULL;
	new_left->left = parent->left;
    /* check if the node is not a leaf */
	if (parent->left != NULL)
		parent->left->parent = new_left;
    /* update pointer */
	parent->left = new_left;

	return (new_left);
}
