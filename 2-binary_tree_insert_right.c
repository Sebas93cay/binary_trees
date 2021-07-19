#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a node as the right-child of another node
 * @parent: pointer to parent node
 * @value: value field
 * Return: right node
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_right;
    /* check if exist root */
	if (!parent)
		return (NULL);
    /* if exists, create new node at right */
	new_right = malloc(sizeof(binary_tree_t));
    /* check if right node was created */
	if (!new_right)
		return (NULL);
    /* assing values and prepare pointers */
	new_right->n = value;
	new_right->parent = parent;
    /* because is right, left points to NULL*/
	new_right->right = NULL;
	new_right->right = parent->right;
    /* check if the node is not a leaf */
	if (parent->right != NULL)
		parent->right->parent = new_right;
    /* update pointer */
	parent->right = new_right;

	return (new_right);
}
