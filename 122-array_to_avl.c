#include "binary_trees.h"
/**
 * array_to_avl - builds an AVL tree from an array
 * @array: a pointer to the first element of the array to be converted
 * @size: number of element in the array
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	size_t counter = 0;
	avl_t *tree = NULL;

	if (!array)
		return (NULL);
	for (counter = 0; counter < size; counter++)
	{
		avl_insert(&tree, array[counter]);
	}
	return (tree);
}
