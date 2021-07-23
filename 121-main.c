#include <stdio.h>
#include "binary_trees.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code on failure
 */
int main(void)
{
	avl_t *root;
	avl_t *node;

	root = NULL;
	/*node = avl_insert(&root, 98);*/
	/*node = avl_insert(&root, 402);*/
	/*printf("\nInserted: %d\n", node->n);*/
	/*node = avl_insert(&root, 46);*/
	/*printf("\nInserted: %d\n", node->n);*/
	/*binary_tree_print(root);*/
	node = avl_insert(NULL, 128);
	printf("\nInserted: %p\n", (void *)node);
	binary_tree_print(root);
	/*node = avl_insert(&root, 256);*/
	/*printf("\nInserted: %d\n", node->n);*/
	/*binary_tree_print(root);*/
	/*node = avl_insert(&root, 512);*/
	/*printf("\nInserted: %d\n", node->n);*/
	/*binary_tree_print(root);*/
	/*node = avl_insert(&root, 540);*/
	/*printf("\nInserted: %d\n", node->n);*/
	/*binary_tree_print(root);*/
	/*node = avl_insert(&root, 550);*/
	/*printf("\nInserted: %d\n", node->n);*/
	/*binary_tree_print(root);*/
	/*node = avl_insert(&root, 545);*/
	/*printf("\nInserted: %d\n", node->n);*/
	/*binary_tree_print(root);*/
	/*node = avl_insert(&root, 530);*/
	/*printf("\nInserted: %d\n", node->n);*/
	/*binary_tree_print(root);*/
	/*node = avl_insert(&root, 410);*/
	/*printf("\nInserted: %d\n", node->n);*/
	/*binary_tree_print(root);*/
	/*node = avl_insert(&root, 300);*/
	/*printf("\nInserted: %d\n", node->n);*/
	/*binary_tree_print(root);*/
	/*node = avl_insert(&root, 290);*/
	/*printf("\nInserted: %d\n", node->n);*/
	/*binary_tree_print(root);*/

	binary_tree_delete(root);
	return (0);
}
