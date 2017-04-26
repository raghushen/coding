#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

void
create_node(struct ListNode **head, int val) {
    if (*head == NULL) {
        (*head) = (struct ListNode *) malloc(sizeof (struct ListNode));
        (*head)->next = NULL;
        (*head)->val = val;
    } else {
        (*head)->val = val;
        (*head)->next = NULL;
    }
}


struct ListNode * 
addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *t1 = l1, *t2=l2;
    struct ListNode *head, **tmp;
    
    head = NULL;
    
    create_node(&head, 0);
    tmp = &head;
    
    int r=0, co=0;
    while(1) {
        if (t1 != NULL && t2 != NULL) {
            r = (t1->val+t2->val+co)%10;
            create_node(tmp, r);
            tmp = &(*tmp)->next;
            co = (t1->val+t2->val+co)/10;
            t1 = t1->next;
            t2 = t2->next;
            continue;
        } else if (t1 != NULL && t2 == NULL) {
            r = (t1->val +co)%10;
            create_node(tmp, r);
            tmp = &(*tmp)->next;
            co = (t1->val+co)/10;
            t1 = t1->next;
            continue;
        } else if (t2 != NULL && t1 == NULL) {
            r = (t2->val +co)%10;
            create_node(tmp, r);
            tmp = &(*tmp)->next;
            co = (t2->val+co)/10;
            t2 = t2->next;
            continue;
        } else if (t1 == NULL && t2 == NULL) {
            if (co != 0)
               create_node(tmp, co);
            break;
        }
    }
    return (head);
}
 

int
main() {

	struct ListNode *t1, *t2, **t, *head, *tmp;
	int i;


	t1 = t2 = NULL;

	t = &t1;
	create_node(t, 3);
	t = &((*t)->next);
	create_node(t, 7);

	t = &t2;
	create_node(t, 9);
	t = &((*t)->next);
	create_node(t, 2);

	head = addTwoNumbers(t1, t2);

	printf("h1 = [");
	tmp = t1;
	while (tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}

	printf("]\nh2 = [");
	tmp = t2;
	while (tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}

	printf("]\nResult: [");
	tmp = head;
	while (tmp != NULL) {
		printf("%d ", tmp->val);
		tmp = tmp->next;
	}
	printf("]\n");
}
