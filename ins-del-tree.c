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

int
main()
{
	int i, cnt = 0;
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

	// printf("\nDeleting 54\n");
	// delete_node(root, 54);
	// in_order(root);

	// printf("\nDeleting 50\n");
	// delete_node(root, 50);
	// printf("Inorder : ");
	// in_order(root);
	// printf("\n");
	
	
	printf("Ancestor of 4 and 77 is %d\n", 
	find_ancestor(root, 4, 77));

}
