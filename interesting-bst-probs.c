#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int val;
	struct node *left;
	struct node *right;
};

struct node *create_node(int val)
{
	struct node *node;

	node = (struct node *)malloc(sizeof(struct node));
	node->val = val;
	node->left = NULL;
	node->right = NULL;

	return (node);
}

struct node *
insert_node(struct node *node, int val)
{
	if (node == NULL)
		return (create_node(val));
	if (val < node->val)
		node->left = insert_node(node->left, val);
	if (val > node->val)
		node->right = insert_node(node->right, val);
	return (node);
}

/*
 * While deleting a node, replace it with the next min.
 * Next min. in a BST is the left most child on the right
 * sub tree from the node.
 */
struct node *
next_min(struct node *node)
{
	struct node *tmp = node;
	while (tmp->left != NULL)
		tmp = tmp->left;
	return (tmp);
}

struct node *
delete_node(struct node *node, int val)
{
	if (node == NULL)
		return (node);
	if (val < node->val)
		node->left = delete_node(node->left, val);
	else if (val > node->val)
		node->right = delete_node(node->right, val);
	else {
		if (node->left == NULL) {
			struct node *tmp = node->right;
			free(node);
			return (tmp);
		} else if (node->right == NULL) {
			struct node *tmp = node->left;
			free(node);
			return (tmp);
		} else {
			struct node *tmp = next_min(node->right);
			node->val = tmp->val;
			node->right = delete_node(node->right, tmp->val);
		}
	}
	return node;
}

/*
 * nth largest element from start
 * Just traverse in-order and print the nth element
 */
void
nth_largest_from_end(struct node *root, int *cnt, int nth)
{
	if (root == NULL || (*cnt) >= nth)
		return ;
	
	nth_largest_from_end(root->left, cnt, nth);
	(*cnt)++;
	if ((*cnt) == nth) {
		printf("\n%d-th largest start = %d\n", nth, root->val);
		return ;
	}
	nth_largest_from_end(root->right, cnt, nth);
}

/*
 * Reverse in-order so that the nth element is nth from start
 */
void
nth_largest_from_end(struct node *root, int *cnt, int nth)
{
	if (root == NULL || (*cnt) >= nth)
		return ;
	
	nth_largest_from_end(root->right, cnt, nth);
	(*cnt)++;
	if ((*cnt) == nth) {
		printf("\n%d-th largest from end = %d\n", nth, root->val);
		return ;
	}
	nth_largest_from_end(root->left, cnt, nth);
}

void
in_order(struct node *root)
{
	if (root == NULL)
		return ;
	in_order(root->left);
	printf(" %d", root->val);
	in_order(root->right);
}

bool
push(int *stack, int *top, int key) {
	if (*top == 0) {
		printf("Push Failed: stack full\n");
		return (false);
	}
	if (*top == 10) *top = (*top) - 1;
	stack[*top] = key;
	*top = (*top) -1;
	return (true);
}

int
pop(int *stack, int *top) {
	if (*top == 10) {
		printf("Pop: Stack empty\n");
		return (-1);
	}
	printf("Pop return stack[%d]=%d\n", *top, stack[*top]);
	*top = (*top) +1;
	return (*(stack+(*top)-1));
}

/*
 * Push values in nodes that leads up to "key" into a stack.
 * This stack can be used to find the lowest common ancestor
 * For BST, lowest ancestor is the node such that it between
 * the two keys.
 */
bool
path_to_key(struct node *node, int key, int *stack, int *top) {

	if (node == NULL) return (false);

	if (node->val == key) {
		push(stack, top, key);
		return (true);
	}
	if (path_to_key(node->left, key, stack, top) == true) {
		push(stack, top, node->val);
		return (true);
	}
	if (path_to_key(node->right, key, stack, top) == true) {
		push(stack, top, node->val);
		return (true);
	}

	return (false);
} 

int
find_ancestor(struct node *node, int key1, int key2) {

	int stack1[10], top1 = 10;
	int stack2[10], top2 = 10;
	int i, j;

	if(path_to_key(node, key1, stack1, &top1) == false) {
		printf("%d: key not found\n", key1);
		return (-1);
	}

	if(path_to_key(node, key2, stack2, &top2) == false) {
		printf("%d: key not found\n", key2);
		return (-1);
	}

	for (i = top1+1, j=top2+1; i <10 && j<10; ++i, ++j) {
		if (stack1[i] != stack2[j])
			break;
	}
	if (i == 10 || j == 10)
		return (-1);

	return (stack1[--i]);

}

/* To Do: Extend the above to print the path between the two keys. */

/*
 * Get the height of the tree.
 */
int
get_height(struct node *node, int level) {
	int ll, rl;

	if (node == NULL) return (level);

	ll = get_height(node->left, level+1);
	rl = get_height(node->right, level+1);

	return (ll > rl ? ll:rl);
}

/*
 * Another meathod to get lowest ancestor without using stack
 */
struct node *
get_ancestor(struct node *node, int key1, int key2) {
	struct node *l_lca, *r_lca;

	if (node == NULL) return (NULL);
	if (node->val == key1 || node->val == key2) {
		return (node);
	}
	l_lca = get_ancestor(node->left, key1, key2);
	r_lca = get_ancestor(node->right, key1, key2);

	/* If both l_lca and r_lca are not null, key1 and key2 are diff.
   * paths(one on left and one on right). We assume keys are not dup.ed.
   */
	if (l_lca && r_lca) return (node);

	/*
 	 * Else, return node that has both.
 	 */
	return (l_lca != NULL ? l_lca : r_lca);

}

/*
 * Routine used to print boundry nodes in a tree.
 * For the left side, its preorder.
 */
void
print_left(struct node *root) {
	if (root->left) {
		printf("%d ", root->val);
		print_left(root->left);
	} else if (root->left) {
		printf("%d ", root->val);
		print_left(root->left);
	}
}

/*
 * Routine used to print boundry nodes in a tree.
 * For right side, its post order
 */
void
print_right(struct node *root) {
	if (root->right) {
		print_left(root->right);
		printf("%d ", root->val);
	} else if (root->left) {
		print_left(root->right);
		printf("%d ", root->val);
	}
}

/*
 * To print leaves, print left leaves then right.
 */
void
print_leaf(struct node *root) {
	if (root) {
		print_leaf(root->left);
		if (root->left == NULL && root->right == NULL)
			printf("%d ", root->val);
		print_leaf(root->right);
	}
}

/*
 * Routine to print boundary of a give tree.
 */
void
print_boundry(struct node *root) {
	if (root) {
		// printf("%d ", root->val);
		print_left(root);
		print_leaf(root->left);
		print_leaf(root->right);
		print_right(root);
	}
}

/*
 * Print all the nodes at a given "level".
 * 'cur' starts at root node(level 1) and travers down to 'level'.
 */
void
print_nodes_at(struct node *root, int cur, int level) {
	if (root == NULL) return ;
	if (cur == level-1) {
		printf("%d ", root->val);
		return ;
	}
	if (root->left)
		print_nodes_at(root->left, cur+1, level);
	if (root->right)
		print_nodes_at(root->right, cur+1, level);

	return ;
}

int
main()
{
	int i, cnt = 0;
	struct node *root = NULL;
	struct node *lca;

//			50
//		   / \
//        10   54
//        /  \    \
//       4   23    77
//          /  \
//         19  30
//              \
//              35

	root = insert_node(root, 50);
	insert_node(root, 10);
	insert_node(root, 23);
	insert_node(root, 19);
	insert_node(root, 54);
	insert_node(root, 77);
	insert_node(root, 4);
	insert_node(root, 30);
	insert_node(root, 35);

	in_order(root);
  
  /*
 * Uncomment each functions to test them.
 */

	nth_largest(root, &cnt, 4);

	// printf("\nDeleting 54\n");
	// delete_node(root, 54);
	// in_order(root);

	// printf("\nDeleting 50\n");
	// delete_node(root, 50);
	// printf("Inorder : ");
	// in_order(root);
	// printf("\n");
	
	
	// printf("Ancestor of 4 and 77 is %d\n", find_ancestor(root, 4, 77));
	// print_boundry(root);

	// lca = get_ancestor(root, 4, 30);
	// printf("LCA is %d\n", lca->val);
	
	// Get height of the tree
	// printf("Height of the tree is: %d\n", get_height(root, 0));

	// Print nodes at a given level
	printf("Nodes at level 3: ");
	print_nodes_at(root, 0, 3);
}
