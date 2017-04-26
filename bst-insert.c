#include <stdio.h>

typedef struct node {
	int val;
	struct node *l;
	struct node *r;
} Node;

Node *
create_node(int val)
{
	Node *new_node = (Node *)malloc(sizeof(Node));
`	new_node->val = val;
	new_node->l = NULL;
	new_node->r = NULL

	return (new_node);
}

Node *
bst_insert(Node *root, int val)
{
	if (root == NULL) return(create_node(val));

	if (val < root->val)
		root->l = bst_insert(root->l, val);
	else
		root->r = bst_insert(root->r, val);
	return (root);
}

Node *
bst_delete(Node *head, int val) {
	if (head == NULL) return (head);
	if (head->val > val)
		head->left = bst_delete(head->left, val);
	else if (head->val < val)
		head->right = bst_delete(head->right, val);
	else {
		if (head->left == NULL) {
			Node *tmp = head->right;
			free(head);
			return (tmp);
		} else if (head->right == NULL) {
			Node *tmp = head->left;
			free(head);
			return (tmp);
		} else {
			Node *tmp = next_min(head->right);
			head->val = tmp->val;
			bst_delete(head->right, tmp->val);
		}
	}
	return (head);
}
