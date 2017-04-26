#include <stdio.h>
#include <stdlib.h>

struct Node {
	int val;
	struct Node *next;
};

void
create_node(struct Node **node, int val) {
	if ((*node) == NULL) {
		*node = (struct Node *) malloc(sizeof(struct Node));
		(*node)->next = NULL;
		(*node)->val = val;
	} else {
		(*node)->val = val;
		(*node)->next = NULL;
	}
}

int
main()
{
	struct Node *h1, *h2, **t, *tmp;
	h1 = h2 = NULL;
	int i;

	t = &h1;
	for (i=0; i<4; ++i) {
		create_node(t, 9);
		t = &((*t)->next);
	}

	t = &h2;
	for (i=0; i<5; ++i) {
		create_node(t, 8);
		t = &((*t)->next);
	}

	printf("T1 = :");
	tmp=h1;
	while (tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}

	printf("\nT2 = :");
	tmp=h2;
	while (tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
}
