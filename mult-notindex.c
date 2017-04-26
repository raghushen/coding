/*
 * Given a sequence, find the seq. that has multiple of all elements
 * except for that index.
 */
#include <stdio.h>

int
mult_but_index(int *a, int sz) {
	int i, j, prod,  prod_thus_far=1;

	for (i=0; i<sz; ++i) {
		if (i==0)
			prod_thus_far = 1;
		else
			prod_thus_far = *(a+i-1) * prod_thus_far;

		prod=1;
		for (j=i+1; j<sz; ++j) {
			prod *= *(a+j);
		}
		printf("%d ", prod*prod_thus_far);
	}
}

int
main() {
	int a[] = {1,2,3,4,5};
	int sz = sizeof(a)/sizeof(int);

	printf("size of arr %d\n", sz);
	mult_but_index(a, sz);
	printf("\n");
}
