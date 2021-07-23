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
 * avl_auto_balance_remove - balance path of node up to root of the tree
 * after a node has been removed
 * @node: node
 * Return: pointer to the root of the tree after being balanced
 */
avl_t *avl_auto_balance_remove(avl_t *node)
{
	int node_balance = 0;

	node_balance = binary_tree_balance(node);
	if (node_balance > 1)
	{
		if (binary_tree_balance(node->left) < 0)
			node->left = binary_tree_rotate_left(node->left);
		node = binary_tree_rotate_right(node);
	}
	else if (node_balance < -1)
	{
		if (binary_tree_balance(node->right) > 0)
			node->right = binary_tree_rotate_right(node->right);
		node = binary_tree_rotate_left(node);
	}
	if (node->parent)
		return (avl_auto_balance_remove(node->parent));
	else
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
	bst_t *node_to_remove = NULL, *parent = NULL;

	if (!node)
		return (NULL);
	if (node->n == value)
	{
		node_to_remove = node;
		if (node->right)
			node = replace_with_node_at_right(node_to_remove);
		else
		{
			parent = node->parent;
			node = node->left;
		}
		if (node)
		{
			node->parent = node_to_remove->parent;
			if (node->parent)
				ASSIGN_NEW_CHILD(node->parent, node_to_remove, node);
		}
		else
			ASSIGN_NEW_CHILD(node_to_remove->parent, node_to_remove, NULL);
		if (root == node_to_remove)
			root = node;
		free(node_to_remove);
		if (node)
			avl_auto_balance_remove(node);
		else
			avl_auto_balance_remove(parent);
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
