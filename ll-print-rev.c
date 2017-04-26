#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
};

struct node *
new_node(int val)
{
	struct node *tmp = (struct node *)malloc(sizeof(struct node));

	tmp->val = val;
	tmp->next = NULL;
	return (tmp);
}

struct node *
add_node(struct node *head, int val)
{
	struct node *tmp = head;

	if (tmp == NULL) {
		return (new_node(val));
	} else {
		while (tmp->next != NULL) {
			tmp = tmp->next;
		}
		tmp->next = new_node(val);
		return (tmp->next);
	}
}

void
print_list(struct node *head)
{
	while(head->next != NULL) {
		printf("%d ", head->val);
		head = head->next;
	}
	/* Print the last element */
	printf("%d ", head->val);
}

void
print_reverse(struct node *head)
{
	if (head == NULL)
		return ;
	print_reverse(head->next);
	printf("%d ", head->val);
}

int
main()
{
	struct node *head = NULL;

	head = add_node(head, 1);
	printf("main: %d\n", head->val);
	add_node(head, 2);
	add_node(head, 3);
	add_node(head, 4);

	print_list(head);

	add_node(head, 5);

	printf("\nPrint reverse:");
	print_reverse(head);
	printf("\n");
}
