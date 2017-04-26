#include <stdio.h>
#include <stdlib.h>

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
 * Reverse in-order so that the nth element is nth from start
 */
void
nth_largest(struct node *root, int *cnt, int nth)
{
	if (root == NULL || (*cnt) >= nth)
		return ;

	
	nth_largest(root->right, cnt, nth);
	(*cnt)++;
	if ((*cnt) == nth) {
		printf("\n%d-th largest = %d\n", root->val);
		return ;
	}
	nth_largest(root->left, cnt, nth);
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

void
pre_order(struct node *root)
{
	if (root == NULL)
		return ;
	printf(" %d", root->val);
	in_order(root->left);
	in_order(root->right);
}

void
post_order(struct node *root)
{
	if (root == NULL)
		return ;
	in_order(root->left);
	in_order(root->right);
	printf(" %d", root->val);
}

int
main()
{
	int cnt = 0;
	struct node *root = NULL;

	root = insert_node(root, 50);
	insert_node(root, 10);
	insert_node(root, 23);
	insert_node(root, 19);
	insert_node(root, 54);
	insert_node(root, 77);
	insert_node(root, 4);
	insert_node(root, 30);

	in_order(root);

	nth_largest(root, &cnt, 4);

	printf("\nDeleting 54\n");
	delete_node(root, 54);
	in_order(root);

	printf("\nDeleting 50\n");
	delete_node(root, 50);
	in_order(root);
}
