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
