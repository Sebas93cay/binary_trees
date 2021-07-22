#include "binary_trees.h"





avl_t *avl_rebalance(avl_t *node, avl_t **tree);

/**
 * avl_insert - Inserts a new node in a AVL tree.
 *
 * @tree: The node of the tree be inserted in the AVL tree.
 * @value: The value of the new node.
 *
 * Return: pointer to new node in AVL tree, NULL otherwise or if value
 *         already exists.
 */
avl_t *avl_insert(bst_t **tree, int value)
{
	avl_t *parent;

	if (!tree)
		return (NULL);
	if (!*tree)
	{
		*tree = (avl_t *)binary_tree_node(NULL, value);
		return (*tree);
	}

	parent = *tree;
	while (parent)
	{
		if (value == parent->n)
			return (NULL);
		if (value < parent->n)
		{
			if (parent->left)
				parent = parent->left;
			else
			{
				parent->left = (avl_t *)binary_tree_node(parent, value);
				return (avl_rebalance(parent->left, tree));
			}
		}
		else
		{
			if (parent->right)
				parent = parent->right;
			else
			{
				parent->right = (avl_t *)binary_tree_node(parent, value);
				return (avl_rebalance(parent->right, tree));
			}
		}
	}
	return (*tree);
}

/**
 * avl_rebalance - Rebalancing algorithm for the AVL tree.
 *
 * @node: The node of the tree be traversed upwards the AVL tree checking
 *        each subtree's balance.
 * @tree: The root of the AVL tree.
 *
 * Return: pointer to new node in AVL tree.
 */
avl_t *avl_rebalance(avl_t *node, avl_t **tree)
{
	int balance, balance_prev;
	avl_t *parent = node->parent;

	balance = balance_prev = 0;
	while (parent)
	{
		balance_prev = balance;
		balance = binary_tree_balance(parent);

		/* Left */
		if (balance > 1)
		{
			/* Right */
			if (balance_prev < 0)
				binary_tree_rotate_left((binary_tree_t *) parent->left);
			/* Left */
			parent = (avl_t *) binary_tree_rotate_right((binary_tree_t *) parent);
		}
		/* Right */
		if (balance < -1)
		{
			/* Left */
			if (balance_prev > 0)
				binary_tree_rotate_right((binary_tree_t *) parent->right);
			/* Right */
			parent = (avl_t *) binary_tree_rotate_left((binary_tree_t *) parent);
		}
		/* Update root if affected */
		if (!parent->parent)
			*tree = parent;
		parent = parent->parent;
	}
	return (node);
}

