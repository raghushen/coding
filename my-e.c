#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

struct digits {
    int val;
    struct digits *next;
};

struct digits *
create_digit(int val) {
    struct digits *new_digit = (struct digits *) malloc(sizeof(struct digits));
    new_digit->val = val;
    new_digit->next = NULL;
    return (new_digit);
}

void
print_num(struct digits *head) {
    if (head == NULL) return;
    print_num(head->next);
    printf("%d", head->val);
}

void
multiply(struct digits **head, int val) {
    struct digits *tmp_p, *tmp_n;
    int p, r, q, c = 0;
    
    if (*head == NULL) {
        *head = create_digit(val);
        return ;
    }
    c = 0; tmp_p = *head;
    while (tmp_p != NULL) {
        p = (tmp_p->val * val) + c;
        r = p%10;
        c = p/10;
        tmp_p->val = r;
        printf("while1: ->val=%d, val=%d, r=%d, c=%d\n", tmp_p->val, val, r, c);
		tmp_n = tmp_p;
        tmp_p = tmp_p->next;
    }
    while (c != 0) {
        tmp_n->next = create_digit(c);
        r = c%10;
        c = c/10;
        tmp_n->val = r;
        printf("while2: ->val=%d, val=%d, r=%d, c=%d\n", tmp_n->next->val, val, r, c);
        tmp_n = tmp_n->next;
    }
    tmp_p = *head; printf("while3: ");
    while (tmp_p != NULL) {
        printf("%d ", tmp_p->val);
        tmp_p=tmp_p->next;
    }
    printf("\n");
    
    return ;
}

int main(){
    int i, n; 
    struct digits *tmp, *head = NULL;
    scanf("%d",&n);

    
    for (i = 1; i <= n; ++i)
        multiply(&head, i);
    
    
    tmp = head;
    while (tmp != NULL) {
        printf("%d ", tmp->val);
        tmp=tmp->next;
    }
    printf("\n");
    print_num(head);
    
    return 0;
}
