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
	if (*tree == NULL)
	{
		*tree = binary_tree_node(parent, value);
		return (*tree);
	}
	if (value == (*tree)->n)
		return (NULL);
	else if(value > (*tree)->n)
		return (bst_insert_recursively(&(*tree)->right, value, *tree));
	return (bst_insert_recursively(&(*tree)->left, value, *tree));
}

bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent = NULL;

	if (!tree)
		return (NULL);
	if (*tree)
		parent = (*tree)->parent;

	return (bst_insert_recursively(tree, value, parent));
}
