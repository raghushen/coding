/*
 * This prog. reverse a given linked list
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct dnode {
	int val;
	struct dnode *next;
	struct dnode *prev;
} Dnode;

typedef struct node {
	int val;
	struct node *next;
} Node;

/* Recursive */
Node *
rec_rev(Node *head)
{
	Node *r;

	if (head == NULL || head->next == NULL) return (head);

	r = rec_rev(head->next);
	head->next->next = NULL;
	head->next = NULL;

	return (r);
}

Node *
create_node(int val) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	return (node);

}

Dnode *
create_dnode(int val) {
	Dnode *node = (Dnode *)malloc(sizeof(Dnode));
	node->val = val;
	node->next = NULL;
	node->prev = NULL;

	return (node);
}

void
create_list(Node **head, int val)
{
	Node *tmp;

	if (*head == NULL) {
		*head = create_node(val);
		return ;
	}
	tmp = *head;
	while(tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = create_node(val);
}

void
create_dlist(Dnode **head, int val)
{
	Dnode *tmp;

	if (*head == NULL) {
		*head = create_dnode(val);
		return ;
	}
	tmp = *head;
	while(tmp->next != NULL)
		tmp = tmp->next;

	tmp->next = create_dnode(val);
	tmp->next->prev = tmp;
}

Node *
rev_list(Node *h) {

	Node *r;

	if (h==NULL || h->next==NULL) return (h);

	r = rev_list(h->next);
	h->next->next = h;
	h->next = NULL;
	return (r);
}

Node *
rev_recursive(Node **head, Node *node)
{
	Node *tmp;
	if (node == NULL) return (node);
	if (node->next == NULL) {
		*head = node;
		return (node);
	}

	tmp = rev_recursive(head, node->next);

	tmp->next = node;
	node->next = NULL;
	return (node);
}

/* Reverse a doubly linked list */
Dnode *
rev_dlist(Dnode *head) {
	Dnode *r;

	if (head == NULL) return (head);
	if (head->next == NULL) {
		head->prev = NULL; // Needed?
		return (head);
	}
	r = rev_dlist(head->next);
	head->next->next = head;
	head->prev = head->next;
	head->next = NULL;

	return (r);
}

void
print_list(Node *head)
{
	Node *tmp = head;
	printf("\nList:  ");
	while (tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
}

void
print_dlist(Dnode *head)
{
	Dnode *tmp = head;
	printf("\nList:  ");
	while (tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
}

int
main()
{
	Node *head = NULL;
	Node *tmp = NULL;

	Dnode *dhead = NULL;
	Dnode *dtmp = NULL;
	
	/* Create single and double linked lists */

	create_list(&head, 1);
	create_dlist(&dhead, 1);

	create_list(&head, 2);
	create_dlist(&dhead, 2);

	create_list(&head, 3);
	create_dlist(&dhead, 3);

	create_list(&head, 4);
	create_dlist(&dhead, 4);

	create_list(&head, 5);
	create_dlist(&dhead, 5);

	create_list(&head, 6);
	create_dlist(&dhead, 5);

	create_list(&head, 7);
	create_dlist(&dhead, 7);

	create_list(&head, 8);
	create_dlist(&dhead, 8);

	create_list(&head, 9);
	create_dlist(&dhead, 9);

	// rev_recursive(&head, head);
	// print_list(head);
	// rev_recursive(&head, head);
	printf("\nRev. ");
	head = rev_list(head);
	print_list(head);

	printf("\nDlist:");
	print_dlist(dhead);
	dhead = rev_dlist(dhead);
	print_dlist(dhead);
}
