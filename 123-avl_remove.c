#include "binary_trees.h"
/**
 * least_node - find the least node of a tree
 * @root: pointer to the root of the tree
 * Return: a pointer to the least node of the tree
 */
bst_t *least_node(bst_t *root)
{
	if (!root)
		return (NULL);
	if (root->left)
		return (least_node(root->left));
	else
		return (root);
}

/**
 * replace_with_node_at_right - replace node_to_remove with the
 * lease node in the right tree
 * @node_to_remove: node to remove;
 * Return: node which was node_to_remove replaced for
 */
bst_t *replace_with_node_at_right(bst_t *node_to_remove)
{
	bst_t *node = NULL;

	node = least_node(node_to_remove->right);
	node->left = node_to_remove->left;
	if (node->left)
		node->left->parent = node;
	if (node != node_to_remove->right)
	{
		node->parent->left = node->right;
		if (node->right)
			node->right->parent = node->parent;
		node->right = node_to_remove->right;
		node->right->parent = node;
	}
	return (node);
}

/**
 * bst_remove_recursive - remove a node recursively
 * @node: node to start looking for value in the tree
 * @value: value to remove in the tree
 * @root: root of the tree
 * Return: a pointer to the new root node of the tree
 * after removing the desired value
 */
bst_t *bst_remove_recursive(bst_t *node, int value, bst_t *root)
{
	bst_t *node_to_remove = NULL;

	if (!node)
		return (NULL);
	if (node->n == value)
	{
		node_to_remove = node;
		if (node->right)
			node = replace_with_node_at_right(node_to_remove);
		else
			node = node->left;
		if (node)
		{
			node->parent = node_to_remove->parent;
			if (node->parent)
			{
				if (node->parent->left == node_to_remove)
					node->parent->left = node;
				else
					node->parent->right = node;
			}
		}
		else
		{
			if (node_to_remove->parent->left == node_to_remove)
				node_to_remove->parent->left = NULL;
			else
				node_to_remove->parent->right = NULL;
		}
		if (root == node_to_remove)
			root = node;
		free(node_to_remove);
		return (root);
	}
	else
	{
		if (value > node->n)
			return (bst_remove_recursive(node->right, value, root));
		else
			return (bst_remove_recursive(node->left, value, root));
	}
}
/**
 * avl_remove - removes a node from an AVL tree
 * @root: pointer to the root node of the tree for removing a node
 * @value: value to remove in the tree
 * Return: a pointer to the new root node of the tree after removing
 * the desired value, and after rebalancing
 */
avl_t *avl_remove(avl_t *root, int value)
{
	if (!root)
		return (NULL);
	root = bst_remove_recursive(root, value, root);
	return (root);
}
