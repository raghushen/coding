#include <stdio.h>
#include <stdlib.h>

typedef enum {
	FALSE=0,
	TRUE
} bool;

typedef struct node {
	int v;
	struct node *l;
	struct node *r;
} Node;

Node *create_node(int val) {
	Node *node = (Node *)malloc(sizeof(Node));
	node->v = val;
	node->r=NULL;
	node->l=NULL;
	return(node);
};

void
in_order(Node *head) {
	if (head == NULL) return ;
	in_order(head->l);
	printf("%d ", head->v);
	in_order(head->r);
}

Node *
add_node(Node *node, int val) {

	if (node == NULL) {
		node = create_node(val);
		return (node);
	}
	if (val < node->v)
		node->l = add_node(node->l, val);
	else
		node->r = add_node(node->r, val);

	return (node);
}

Node *
find_next_min(Node *node) {
	Node *tmp = node;
	while(tmp->l != NULL)
		tmp = tmp->l;
	return (tmp);
}

Node *
delete_node(Node *head, int val) {
	Node *tmp;

	if (head == NULL) return (head);
	if (val < head->v)
		head->l = delete_node(head->l, val);
	else if (val > head->v) 
		head->r = delete_node(head->r, val);
	else { // hit the node to delete
		if (head->r == NULL) {
			tmp = head->l;
			free(head);
			return (tmp);
		} else {
			tmp = find_next_min(head->r);
			head->v = tmp->v;
			head->r = delete_node(head->r, tmp->v);
		}
	}
	return (head);

}

Node *
create_B_tree(int *a, int sz) {
	Node *head;
	int i;

	head = create_node(*(a+0));
	for (i=1; i<sz; ++i) {
		add_node(head, *(a+i));
	}
	return (head);
}

struct Queue {
	Node *node;
	struct Queue *next;
	struct Queue *prev;
};

struct Queue *HEAD = NULL;
struct Queue *TAIL = NULL;

struct Queue *
create_Q_node(Node *node) {
	struct Queue *tmp;
	tmp = (struct Queue *)malloc(sizeof(struct Queue));
	tmp->node = node;
	tmp->next = NULL;
	tmp->prev = NULL;

	return (tmp);
}

void
enqueue(Node *node) {
	struct Queue *tmp;

	if (node == NULL) return ;

	tmp = create_Q_node(node);
	if (TAIL == NULL) {
		TAIL = tmp;
		HEAD = TAIL;
	} else {
		TAIL->next = tmp;
		tmp->prev = TAIL;
		TAIL = tmp;
	}
}

Node *
dequeue() {
	struct Queue *q_tmp = HEAD;
	Node *tmp;

	if (HEAD == NULL) return (NULL);
	if (HEAD == TAIL) {
		HEAD = TAIL = NULL;
	} else {
		HEAD = HEAD->next;
		HEAD->prev = NULL;
	}
		tmp = q_tmp->node;
		free(q_tmp);
		return (tmp);
}

bool
queue_empty() {
	if (HEAD == NULL) return (TRUE);
	else return (FALSE);
	// HEAD == NULL ? return(TRUE) : return (FALSE);
}

void
BFT(Node *head) {
	Node *node;

	if (head == NULL) return;

	printf("BFT: ");

	enqueue(head);
	
	while (queue_empty() == FALSE) {
		node = dequeue();
		if (node->l != NULL) enqueue(node->l);
		if (node->r != NULL) enqueue(node->r);
		printf("%d ", node->v);
	}
	printf("\n");
}

int
main() {
	int arr[] = {50, 40, 60, 30, 45, 41, 70, 65, 47, 62};
	int sz = sizeof(arr)/sizeof(arr[0]);

	Node *head;
	
	head = create_B_tree(arr, sz);
	printf("In Order: ");
	in_order(head);
	printf("\n");

	BFT(head);

	delete_node(head, 50);

	printf("In Order: ");
	in_order(head);
	printf("\n");

	BFT(head);
}
