#include "binary_trees.h"
/**
 * bst_insert_recursively - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to
 * insert the value
 * @value: value of the new node to insert
 * @parent: parent of the tree
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
	else if (value > (*tree)->n)
		return (bst_insert_recursively(&(*tree)->right, value, *tree));
	return (bst_insert_recursively(&(*tree)->left, value, *tree));
}

/**
 * bst_insert - inserts a value in a Binary Search Tree
 * @tree: a double pointer to the root node of the BST to
 * insert the value
 * @value: value of the new node to insert
 * Return: return a pointer to the created node, or NULL on failure
 * If the address stored in tree is NULL, the created node will
 * become the root node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *parent = NULL;

	if (!tree)
		return (NULL);
	if (*tree)
		parent = (*tree)->parent;

	return (bst_insert_recursively(tree, value, parent));
}

/**
 * avl_auto_balance - balance path above node to make sure every
 * sub tree in the path is a valid avl tree
 * @node: node to start path
 */
void avl_auto_balance(avl_t *node)
{
	int balance_parent, balance_node = 0;
	avl_t *parent = NULL;

	if (node->parent == NULL)
		return;

	parent = node->parent;
	balance_parent = binary_tree_balance(node->parent);
	balance_node = binary_tree_balance(node);
	if (balance_parent > 1)
	{
		if (balance_node == -1)
			node = binary_tree_rotate_left(node);
		parent = binary_tree_rotate_right(parent);
	}
	else if (balance_parent < -1)
	{
		if (balance_node == 1)
			node = binary_tree_rotate_right(node);
		parent = binary_tree_rotate_left(parent);
	}
	avl_auto_balance(node->parent);
}

/**
 * avl_insert - inserts a value in an AVL Tree
 * @tree: double pointer to the root node of the AVL tree
 * for inserting the value
 * @value: value to store in the node to be inserted
 * Return: a pointer to the created node, or NULL on failure
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *newnode = NULL;

	if (!tree)
		return (NULL);

	newnode = bst_insert(tree, value);
	avl_auto_balance(newnode);
	return (newnode);
}
