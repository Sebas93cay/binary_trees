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
 * new_offspring - changes child of a parent node
 * @parent: pointer to the parent node
 * @old_son: pointer to old second
 * @new_son: pointer to new son
 */
void new_offspring(bst_t *parent, bst_t *old_son, bst_t *new_son)
{
	if (parent->left == old_son)
		parent->left = new_son;
	else
		parent->right = new_son;
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
		{
			node = least_node(node->right);
			node->left = node_to_remove->left;
			if (node->left)
				node->left->parent = node;
			if (node != node_to_remove->right)
			{
				node->parent->left = node->right;
				node->right = node_to_remove->right;
				node->right->parent = node;
			}
		}
		else
			node = node->left;
		if (node)
		{
			node->parent = node_to_remove->parent;
			if (node->parent)
				new_offspring(node->parent, node_to_remove, node);
		}
		else
			new_offspring(node_to_remove->parent, node_to_remove, NULL);
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
 * bst_remove - removes a node from a Binary Search Tree
 * @root: a pointer to the root node of the tree where you will
 * remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree after removing the
 * desired value
 */
bst_t *bst_remove(bst_t *root, int value)
{
	return (bst_remove_recursive(root, value, root));
}
