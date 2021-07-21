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
bst_t* array_to_bst(int* array, size_t size)
{
	size_t i;
	bst_t* tree = NULL;

	for (i= 0; i < size; i++)
	{
		bst_insert(&tree, array[i]);
	}
	return (tree);
}
