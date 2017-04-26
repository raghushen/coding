#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int v;
	struct node *l;
	struct node *r;
} Node;

Node *
create_node(int val) {
	Node *node;
	node = (Node *) malloc(sizeof(Node));
	node->v = val;
	node->l = NULL;
	node->r = NULL;
	return (node);
}

void
in_order(Node *node) {
	if (node == NULL) return;
	in_order(node->l);
	printf("%d ", node->v);
	in_order(node->r);
}

Node *
t_insert(Node *node, int val) {
	if (node == NULL) {
		node = create_node(val);
		return (node);
	}
	if (node->v > val)
		node->l = t_insert(node->l, val);
	else
		node->r = t_insert(node->r, val);

	return (node);
}

Node *
t_next_min(Node *node) {
	Node *t = node;
	while (t->l != NULL) {
		t = t->l;
	}
	printf("next Min.: %d\n", t->v);
	return (t);
}

Node *
t_delete(Node *node, int val) {

	Node *t;

	if (node == NULL) return (NULL);

	if (node->v > val)
		node->l = t_delete(node->l, val);
	else if (node->v < val)
		node->r = t_delete(node->r, val);
	else {
		if (node->l == NULL) {
			t = node->r;
			free(node);
			return (t);
		} else {
			t = t_next_min(node->r);
			node->v=t->v;
			node->r = t_delete(node->r, t->v);
		}
	}
	return (node);
}

#define MAX(X,Y) X > Y ? X : Y

int
max_height(Node *root) {
	int lh, rh;
	// Since root node is at level 0, we return -1, if root node
	// were at level 1, return 0
	if (root == NULL) return (-1);
	// else {
		printf("At Node %d\n", root->v);
		lh = max_height(root->l);
		rh = max_height(root->r);
		if (lh > rh)
			return (lh+1);
		else
			return (rh+1);
	// }
}

int
find_height(Node *root, int cur) {
	static int max = 0;

	if (root == NULL) {
		printf("NULL: cur = %d, max = %d\n", cur, max);
		return (max);
	}
	if (root->l != NULL) {
		printf("At L %d: cur = %d, max = %d\n", root->v, cur, max);
		find_height(root->l, cur + 1);
	} 
	if (root->r != NULL) {
		printf("At R %d: cur = %d, max = %d\n", root->v, cur, max);
		find_height(root->r, cur + 1); 
	}
	printf("End %d: cur = %d, max = %d\n", root->v, cur, max);
	max = max > cur ? max : cur;
	return (max);
}

void top_view(Node * root)
{
	Node *tmp;
	if (root == NULL) return;
	else {
		top_view(root->l);
		printf("%d ", root->v);
	}
	tmp = root->r;
	while (tmp != NULL) {
		printf("%d ", tmp->v);
		tmp = tmp->r;
	}
}

int
main() {
	Node *root;

	root = t_insert(root, 50);
	t_insert(root, 10);
	t_insert(root, 23);
	t_insert(root, 19);
	t_insert(root, 54);
	t_insert(root, 77);
	t_insert(root, 4);
	t_insert(root, 30);
	t_insert(root, 65);

	printf("Inorder: ");
	in_order(root);
	printf("\n");

	// printf("Delete Node 10\n");
	// t_delete(root, 10);

	// printf("Inorder after delete: ");
	// in_order(root);
	// printf("\n");

	// printf("Height of the tree %d\n", find_height(root, 0));
	// printf("Height of the tree %d\n", max_height(root));
	printf("Top view: ");
	top_view(root);
	printf("\n");
	top_view(root);

}
