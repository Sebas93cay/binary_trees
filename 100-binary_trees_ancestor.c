#include "binary_trees.h"
/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node
 * @second: a pointer to the second node
 * Return: a pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *tmp_node = NULL;

	if (!first || !second)
		return (NULL);
	tmp_node = (binary_tree_t *)second;
	while (tmp_node)
	{
		if (first == tmp_node)
			return ((binary_tree_t *)first);
		tmp_node = tmp_node->parent;
	}
	return (binary_trees_ancestor(first->parent, second));
}
