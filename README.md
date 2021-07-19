# 0x1D. C - Binary trees

## Content:

* **[0. New node](./0-binary_tree_node.c):** C function that creates a binary tree node with a given parent and value.
	* Returns a pointer to the new node, or `NULL` on failure.

* **[1. Insert left](./1-binary_tree_insert):** C function that inserts a node as the left-child of another.
  * Returns a pointer to the new node, or `NULL` on failure.
  * If the given `parent` already contains a left node, the new node takes its place and the old left-child becomes the left-child of the new node.

* **[2. Insert right](./2-binary_tree_insert_right.c):** C function that inserts a node as the right-child of another.
  * Returns a pointer to the new node, or `NULL` on failure.
  * If the given `parent` already contains a right node, the new node takes its
  place and the old right-child becomes the right-child of the new node.

* **[3. Delete](./3-binary_tree_delete.c):** C function that deletes an entire binary tree.

* **[4. Is leaf](./4-binary_tree_is_leaf.c):** C function that checks
  if a given node is a leaf.
  * Returns `1` if the node is a leaf, `0` otherwise.

* **[5. Is root](./5-binary_tree_is_root.c):** C function that checks
  if a given node is a root.
  * Returns `1` if the node is a root, `0` otherwise.

* **[6. Pre-order traversal](./6-binary_tree_preorder.c):** C function that
  traverses a tree using pre-order traversal.

* **[7. In-order traversal](./7-binary_tree_inorder.c):** C function that
  traverses a tree using in-order traversal.

* **[8. Post-order traversal](./8-binary_tree_postorder.c):** C function that
  traverses a tree using post-order traversal.

* **[9. Height](./9-binary_tree_height.c):** C function that returns the height of a binary tree.

* **[10. Depth](./10-binary_tree_depth.c):** C function that returns the depth of a given node in a binary tree.

* **[11. Size](./11-binary_tree_size.c):** C function that returns the size of a binary tree.

* **[12. Leaves](./12-binary_tree_leaves.c):** C function that returns the number of leaves in a binary tree.

* **[13. Nodes](./13-binary_tree_nodes.c):** C function that returns the number of nodes in a binary tree with at least one child.

* **[14. Balance factor](./14-binary_tree_balance.c):** C function that returns the balance factor of a binary tree.

* **[15. Is full](./15-binary_tree_is_full.c):** C function that checks if a binary tree is full.
  * Returns `1` if a tree is full, `0` otherwise.

* **[16. Is perfect](./16-binary_tree_is_perfect.c):** C function that checks if a binary tree is perfect.
  * Returns `1` if a tree is perfect, `0` otherwise.

* **[17. Sibling](./17-binary_tree_sibling.c):** C function that returns a pointer to the sibling of a given node in a binary tree.
  * Returns `NULL` if no sibling is found.
  
* **[18. Uncle](./18-binary_tree_uncle.c):** C function that
  returns a pointer to the uncle of a given node in a binary tree.
  * Returns `NULL` if no uncle is found.
  
## Authors

* **Juan Sebastian Caicedo Alfonso**<[Sebas93cay](https://github.com/Sebas93cay)> and **Jaime Andres Aricapa Perez**<[Jaricapa-holberton](https://github.com/Jaricapa-holberton)>