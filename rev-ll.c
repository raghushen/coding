/*
 * This prog. reverse a given linked list
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int val;
	struct node *next;
} Node;

/* Recursive */
Node *
rec_rev(Node *head)
{
	if (head == NULL) return (head);
	head->next = rec_rev(head->next);
	
}

Node *
create_node(int val) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
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

int
main()
{
	Node *head = NULL;
	create_list(&head, 1);
	create_list(&head, 2);
	create_list(&head, 3);
	create_list(&head, 4);
	create_list(&head, 5);
	create_list(&head, 6);
	create_list(&head, 7);
	create_list(&head, 8);
	create_list(&head, 9);
	print_list(head);
	rev_recursive(&head, head);
	print_list(head);
	rev_recursive(&head, head);
	print_list(head);
}
