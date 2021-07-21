#include "binary_trees.h"
/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to
 * insert the value
 * @value: value of the new node to insert
 * Return: return a pointer to the created node, or NULL on failure
 * If the address stored in tree is NULL, the created node will
 * become the root node
 */
bst_t *bst_insert_recursively(bst_t **tree, int value, bst_t *parent)
{
	if (value == (*tree)->n)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = malloc(sizeof(bst_t));
		if (!(*tree))
			return (NULL);
		(*tree)->parent = parent;
		(*tree)->n = value;
		(*tree)->left = NULL;
		(*tree)->right = NULL;
		return (*tree);
	}
	else if(value > (*tree)->n)
		return (bst_insert_recursively(&(*tree)->right, value, *tree));
	return (bst_insert_recursively(&(*tree)->left, value, *tree));
}

bst_t *bst_insert(bst_t **tree, int value)
{
	if (!tree)
		return (NULL);

	return (bst_insert_recursively(tree, value, NULL));
}
