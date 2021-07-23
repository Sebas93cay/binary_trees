#include <stdio.h>
#include <stdlib.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	avl_t *tree;
	/*int array[] = {*/
	/*79, 47, 68, 87, 84, 91, 21, 32, 34, 2,*/
	/*20, 22, 98, 1, 62, 95*/
	/*};*/
	/*size_t n = sizeof(array) / sizeof(array[0]);*/

	/*tree = array_to_avl(array, n);*/
	/*if (!tree)*/
	/*return (1);*/
	/*binary_tree_print(tree);*/

	/*tree = avl_remove(tree, 47);*/
	/*printf("Removed 47...\n");*/
	/*binary_tree_print(tree);*/

	/*tree = avl_remove(tree, 79);*/
	/*printf("Removed 79...\n");*/
	/*binary_tree_print(tree);*/

	/*tree = avl_remove(tree, 32);*/
	/*printf("Removed 32...\n");*/
	/*binary_tree_print(tree);*/

	/*tree = avl_remove(tree, 34);*/
	/*printf("Removed 34...\n");*/
	/*binary_tree_print(tree);*/

	/*tree = avl_remove(tree, 22);*/
	/*printf("Removed 22...\n");*/
	/*binary_tree_print(tree);*/
	int array[] = {
		79, 47, 68
	};
	int num_to_delete[] = {47, 79, 68};
	size_t i = 0;
	size_t n_del = sizeof(num_to_delete) / sizeof(num_to_delete[0]);
	size_t n = sizeof(array) / sizeof(array[0]);

	tree = array_to_avl(array, n);
	if (!tree)
		return (1);
	printf("Tree:\n");
	binary_tree_print(tree);
	for (i = 0; i < n_del; i++)
	{
		tree = avl_remove(tree, num_to_delete[i]);
		printf("Removed %i...\n", num_to_delete[i]);
		binary_tree_print(tree);
	}

	binary_tree_delete(tree);
	return (0);
}
