/* Reverse a string */
#include <stdio.h>

void
str_rev(char *s)
{
	if (*s != '\0')
		str_rev(s+1);
	printf("%c", *s);
}

int
main()
{
	str_rev("this is a string");
}

--------------------------------------------------------------------------

/* Fibonacci series - loop and recursive */
#include <stdio.h>

main()
{
	int n;

	printf("Enter:");
	scanf("%d", &n);

	/* printf("Fib(%d) = %d\n", n, fib(n)); */
	printf("Fib(%d) = %d\n", n, fib_loop(n));
}

int
fib_loop(int n)
{
	int i;
	int a = 0, b = 1, c;

	if (n == 0 || n == 1)
		return(n);
	for(i=0; i < n; ++i) {
		c = a + b;
		a = b;
		b = c;
	}
	return (c);
}

int
fib(int n)
{
	if ((n == 1) || (n == 0))  return n;
	printf("%d ", n);
	return (fib(n-2) + fib(n-1));
}

--------------------------------------------------------------------------

/* How to define variable args */
#include <stdio.h>
#include <sys/varargs.h>

static void
var_msg(int n, char *fmt, ...)
{
	va_list ap;
	char	msgbuf[255];

	va_start(ap, fmt);
	vsprintf(msgbuf, fmt, ap);
	printf("va string[?%d]: %s\n", n, msgbuf);
	va_end(ap);
}

main()
{
	var_msg(1, "first %s", "string");
	var_msg(2, "Second %s %s", "string", "list");
}

--------------------------------------------------------------------------

/* How to define variable no. of args to a fn. */
#include <stdio.h>
#include <stdarg.h>

static void
var_msg(int n, char *fmt, ...)
{
	va_list	ap;
	char	msgbuf[255];

	va_start(ap, fmt);
	vsprintf(msgbuf, fmt, ap);
	printf("va string[%d]: %s\n", n, msgbuf);
	va_end(ap);
}

main()
{
	var_msg(1, "first %s", "string");
	var_msg(2, "Second %s %s", "string", "list");
}


--------------------------------------------------------------------------
/* Pointer to a pointer */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

void InsertStudent(char*** students);

int main()
{

char** students = NULL;
int** marks = NULL;
char line[100];
int menu;
	

	InsertStudent(&students);
	InsertStudent(&students);
	InsertStudent(&students);
 
	
	printf("In main %s\n", students[0]);
	printf("In main %s\n", students[1]);
	printf("In main %s\n", students[2]);
 
return 0;

}


/* function InsertStudent */
void InsertStudent(char*** students)
{

	int  i=0;

	if (*students == NULL) {
		printf("student null\n");
		*students = (void *) malloc(1);
		(*students)[0] = NULL;
	}
 	while ((*students)[i] != NULL) i++;

	*students = (void *)realloc(*students, 1);
	(*students)[i] = (char *)malloc(10);
	(*students)[i+1] = NULL;
	
	printf("Enter the name[%d]:", i);
	scanf("%s", (*students)[i]);

}/*end InsertStudent*/

--------------------------------------------------------------------------
/* How to modify a const variable - but not adviced */
#include <stdio.h>

int main(){
	const int a = 0;
	*(int *)&a = 39;   /* NB: when we use *() its another variable, not a */
	printf("%d", a);
}
--------------------------------------------------------------------------

/* Swamp without thrid variable */
swap(int *a, int *b)
{
	if ( a != b ) {
		*a = *a ^ *b;
		*b = *a ^ *b;
		*a = *a ^ *b;
	}
}
--------------------------------------------------------------------------
/* Insertion Sort */
#include <stdio.h>

int arr[6] = { 4, 7, 2, 6, 3, 1 };

void
push_right(int a, int b)
{
	int k;
	for (k = b; k > a; --k)
		arr[k] = arr[k - 1];
}

int
main()
{
	int i, j, l, tmp;

	for (i = 1; i < 6; ++i) {
		for (j = 0; j < i; ++j) {
			if (arr[i] < arr[j]) {
				tmp = arr[i];
				push_right(j, i);
				arr[j] = tmp;
			}
		}
	}
	printf("Sorted array:\n");
	for (i = 0; i < 6; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
--------------------------------------------------------------------------
/* Mergesort XXX - Segfaults inside merge() routine */
nclude <stdio.h>

void
merge(int *arr, int l, int m, int r)
{
	int i, j, k = 0;
	int x, y;
	int L[10];
	int R[10];

	for (i = l, x = 0; i < m; ++i, ++x)
		L[x] = *(arr+i);
	for (j = m, x = 0; i < r; ++j, ++x)
		R[x] = *(arr+j);

	x = 0; y = 0; k = 0;
	while ((x < i) || (y < j)) {
		if (L[x] < R[y]) {
			*(arr+k) = L[x++];
		} else {
			*(arr+k) = R[y++];
		}
		k++;
	}
}

void
mergesort(int *arr, int l, int r)
{
	int m;
	if (l < r) {
		printf("mergesort: l = %d, r = %d\n", l, r);
		m = l + ((r-l)/2);
		mergesort(arr, l, m);
		mergesort(arr, m+1, r);
		merge(arr, l, m, r);
	}
}

int
main()
{
	int i;
	int arr[7] = { 4, 7, 2, 6, 3, 1, 9 };

	mergesort(arr, 0, 6);

	printf("Sorted arr:\n");
	for (i = 0; i < 6; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}

--------------------------------------------------------------------------
/* QuickSort - just psudo code */
#include <stdio.h>

int
partition(int *arr, int low, int high)
{
	int i, j, pivot;

	/* Always choose high as pivot */
	pivot = *(arr+high);
	i = low;
	for (j = low; j < high; ++j) {
		if (*(arr+j) < pivot) {
			swap((arr+j), (arr+i));
			i++;
		}
	}
	swap((arr+high), (arr+i));
	return i;
}

void
quicksort(int *arr, int low, int high)
{
	int pi; /* Partition Index */

	if (low < high) {
		pi = partition(arr, high, low);

		/* value at pi in right place */
		quicksort(arr, low, pi -1);
		quicksort(arr, pi + 1, high);
	}
}

--------------------------------------------------------------------------
/* Heap Sort */

#include <stdio.h>


void
swap(int *i, int *j)
{
	int tmp = *i;
	*i = *j;
	*j = tmp;
}

/* Heapify subtree, with root at i and size n */
/* Note, root of the whole array is arr[0] */
void
heapify(int *arr, int n, int i)
{
	int h = i;
	int l = 2*i + 1;
	int r = 2*i +2;

	/* If left child is more than node */
	if (l < n && arr[l] > arr[i])
		h = l;
	
	if (r < n && arr[l] > arr[i])
		h = r;

	/* if h is not i, need to swap */
	if (h != i) {
		swap(&arr[i], &arr[h]);
		heapify(arr, n, h);
	}
}

void
heapsort(int *arr, int n)
{
	int i;
	/* Build a heap starting from the middle */
	for (i = n/2 -1; i > 0; --i)
		heapify(arr, n, i);

	/* Delete higest value, which is currently at top by swaping with
 * 	 * last element...hence push largest element to end of the array*/
	for (i = n - 1; i >= 0; --i) {
		swap(&arr[0], &arr[i]); // push current root to end

		/* Heapify reduced heap */
		heapify(arr, i, 0);
	}
}

int
main()
{
	int arr[] = {12, 11, 13, 5, 6, 7};
	int i, n = sizeof(arr)/sizeof(arr[0]);

	heapsort(arr, n);

	printf("Sorted array: ");
	for (i = 0; i < n; ++i)
		printf("%d ", arr[i]);
	printf("\n");
		
}



--------------------------------------------------------------------------
/* Binary Search Tree(BST)  Insertion, Deletion and nth largest */
#include <stdio.h>
#include <stdlib.h>

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
 *  * Reverse in-order so that the nth element is nth from start
 *   */
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

int
main()
{
	int cnt = 0;
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

	printf("\nDeleting 54\n");
	delete_node(root, 54);
	in_order(root);

	printf("\nDeleting 50\n");
	delete_node(root, 50);
	in_order(root);
}


--------------------------------------------------------------------------
/* Linked List: Insert */
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

--------------------------------------------------------------------------
/*
 * Map a - 1, b - 2, c - 3, ... z - 26; give a sequence "12213" determine
 * what possible matches can be found: abbac, lbac, lbm...
 */
#include <stdio.h>
#include <string.h>

int count_decoding(char *digit, int n)
{
	int count[n+1], i;
	count[0] = 1;
	count[1] = 1;

	for (i = 2; i <= n; ++i) {
		count[i] = 0;

		/*
		 * If last digit is not 0, last digit will add to the no. of
		 * words */
		if (digit[i-1] > '0') {
			printf("digit[%d-1] = %c\n", (i), digit[i-1]);
			count[i] = count[i-1];
		}

		/*
 		 * If second last digit is smaller than 2 and last digit is
 		 * smaller than 7(<26), last 2 digits form a valid char
 		 * */
		if (digit[i-2] < '2' || (digit[i-2]=='2' && digit[i-1] < '7')) {
			printf("d[%d-2] = %c, [%d-1] = %c\n\n", (i), digit[i-1],
				(i), digit[i-1]);
			count[i] += count[i-2];
		}
	}
	return (count[n]);
}

int
main()
{
	char digit[] = "1221";
	int n = strlen(digit);
	printf("size of string = %d\n", n);
	printf("Count is %d\n", count_decoding(digit, n));
}

--------------------------------------------------------------------------
/* Find sum of max. sub-sequence in an array */

#include <stdio.h>

#define RETURN_MAX(X, Y) (X < Y) ? Y : X

int
max_sub_seq(int *A, int size)
{
	int cur_max = 0;
	int total_max = 0;
	int i, s = sizeof(A)/sizeof(A[0]);
	/* NB: s is not no. of arr elements,
	 * its sizeof(ptr)/sizeof(int) which is 2 */

	printf("Size = %d\n", size);
	for (i = 0; i < size; ++i) {
		cur_max = RETURN_MAX(A[i], (A[i] + cur_max));
		total_max = RETURN_MAX(cur_max, total_max);
		printf("cur-max = %d, total_max = %d\n", cur_max, total_max);
	}
	return (total_max);
}

int
main()
{
	int A[] = { -4, 15, -6, 18, 2, -20 };

	printf("Max. cont. sub-seq = %d\n",
		max_sub_seq(A, sizeof(A)/sizeof(A[0])));
	/*
 	 * NB: sizeof(A) here is not size of pointer but
 	 * sizeof array times size of integer. Hence had to device
	 * by size of integer to get no. of elements.
 	 */
}

--------------------------------------------------------------------------
/* Print all possible permutations of a string */
/* NB: Its not fully working */
#include <stdio.h>
#include <string.h>

void
swap(char *a, char *b)
{
    char ch;
    ch = *a;
    *a = *b;
    *b = ch;
}


void
permute(char *a, int l, int r)
{
    int i;

    if (l == r) 
         printf("%s\n", a);
    else {
        for (i = l; i <= r; ++i) {
            swap(a+l, a+i);
            permute(a, l+1, r);
            swap(a+l, a+i);
        }
    }
}

int
main()
{
    char str[] = "abc";
    int s = sizeof(str);
    permute(str, 0, s);
}

--------------------------------------------------------------------------




ven 2D array such that the values are increasing from left to right
 * and top to bottom, write an efficient algo. to find its cordinates a
 *  * given val.
 *   */

#include <stdio.h>

int matrix[4][5] =	{ { 1, 2, 3, 4, 5 },
					  { 6, 7, 8, 9, 10 },
					  { 11, 12, 13, 14, 15},
					  { 16, 17, 18, 19, 20}
					};

// There are couple of ways 2D array can be passed:
// Method a: pass the whole array as below:
// search_matrix(int arr[4][5], int val, int i, int j, int n, int m)
// Or,
// Pass pointer to lows of array of length 5.
int
search_matrix(int (*arr)[5], int val, int i, int j, int n, int m)
{
	int ret = 0;
	if (arr[i][j] == val) {
		printf("Found match: Arr[%d][%d]\n", i, j);
		return (1); // Bool 1=true, 0 = false
	}
	if (i < n && j < m && j >= 0) {
		if (val < arr[i][j])
			ret = search_matrix(arr, val, i, j-1, n, m);
		else if (val > arr[i][j])
			ret = search_matrix(arr, val, i+1, j, n, m);
	} else {
		printf("Did not find element\n");
		return ret;
	}
}

int
main(int argc, char *argv[])
{
	/*
 	 * Note: search starts from top right corner: matrix[0][n]
 	 * Nb: Index goes from rows: (0 - 3) and col: (0 - 4) 
 	 */
	// search_matrix, [][], [0], [4] n=4, m=5)
	if (argc < 2) {
			printf("Usage %s <val>\n", argv[0]);
			return (1);
	}
	search_matrix(matrix, atoi(argv[1]), 0, 4, 4, 5);
}
--------------------------------------------------------------------------
--------------------------------------------------------------------------
--------------------------------------------------------------------------
