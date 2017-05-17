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

/*
 * Find the max. height of the given tree.
 */
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

/*
 * Another version to get height.
 * NB: get_height1 is called with level=0 for root
 */
 int
get_height1(Node_t *root, int level) {
    int lh, rh;


    if (root == NULL) return(level);
    lh = get_height1(root->l, level+1);
    rh = get_height1(root->r, level+1);

    return (lh > rh ? lh : rh);
}

int
get_height2(Node_t *root) {
    int lh, rh;

    if (root == NULL)
        return (0);
    lh = get_height2(root->l);
    rh = get_height2(root->r);
    return(1+ (lh>rh? lh:rh));
}

/*
 * Print top view: Left side: reverse order from left most node to root.
 *                 Right side: nodes from root to right most node.
 */
void
print_top_left(Node * root)  // Utility fn. for top_view
{
    Node *tmp;
    if (root == NULL) return;
    else {
        print_top_left(root->l);
        printf("%d ", root->v);
    }
}

void
top_view(Node *root) {
    Node_t *tmp;

    print_top_left(root);
    tmp = root->r;
    while (tmp != NULL) {
        printf("%d ", tmp->v);
        tmp=tmp->r;
    }
}

/*
 * Print the total tound of all the nodes at a given level
 * The value is returned in count.
 */
void
nodes_at_level(Node *root, int level, int cur, int *count) {
    int tmp;

    if (root == NULL)
        return ;

    if (cur > level)  {
        return ;
    }
    if (cur == level) *count += 1;
    nodes_at_level(root->l, level, cur+1, count);
    nodes_at_level(root->r, level, cur+1, count);
    return ;
}

/*
 * Print all ancestors leading up to a given node from root.
 */
bool
print_ancestors(Node_t *root, int key) {
    if (root == NULL) {
         return (false);
    }
    if (root->val == key) {
         return (true);
    }

    if (root->l != NULL) {
        if (print_ancestors(root->l, key)) {
            printf("%d ", root->val);
            return (true);
        }
    }
    if (root->r != NULL) {
        if (print_ancestors(root->r, key))
            printf("%d ", root->val);
            return (true);
    }
    return (false);
}

/*
 * Print node that do not have any siblings.
 * i.e., node that has only one child.
 */
void
node_with_no_siblings(Node_t *node) {

    if (node == NULL) return ;

    if (node->r && !node->l) {
        printf("%d ", node->r->val);
    }
    if (node->l && !node->r) {
        printf("%d ", node->l->val);
    }
    if (node->l != NULL)
        node_with_no_siblings(node->l);
    if (node->r != NULL)
        node_with_no_siblings(node->r);
    return ;
}

/*
 * calculate width of a tree at each level starting from root(level 0)
 * The result is stored in a count[] array.
 * The assumption is that count is big enough to accomodate all the levels
 */
void
width_at_level(Node_t *root, int level, int *count, int sz) {
    if (root == NULL) return ;

    width_at_level(root->l, level+1, count, sz);
    width_at_level(root->r, level+1, count, sz);
    *(count+level) += 1;
    return ;
}

int
max_tree_width(int *count, int sz) {
	int i, max = *(count+0);
	for (i=1; i<sz; ++i) {
		max = max>*(count+i)? max:*(count+i);
	}
	return (max);
}

int
main() {
	Node *root=NULL;
	int num_nodes = 0;
	int count[] = {0,0,0,0,0};
	int sz=sizeof(count)/sizeof(count[0]);

	root = t_insert(root, 50);
	t_insert(root, 40);
	t_insert(root, 30);
	t_insert(root, 60);
	t_insert(root, 70);
	t_insert(root, 55);
	t_insert(root, 45);
	t_insert(root, 42);
	t_insert(root, 47);
	t_insert(root, 43);
	
	//		50
	//             /  \
	//           40    60
	//          / \    / \
	//         30 45  55  70
	//            / \
	//          42  47
	//           \
	//            43

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
	// printf("Top view: ");
	// top_view(root);
	// printf("\n");
	// top_view(root);
	
	// nodes_at_level(root, 2, 0, &num_nodes);
    	// printf("Nodes at level 2: %d\n", num_nodes);

     	// print_ancestors(root, 43);
    	// node_with_no_siblings(root);
	
	width_at_level(root, 0, count, sz);
	printf("Max width of the tree %d\n", max_tree_width(count, sz));

}
