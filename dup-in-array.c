/*
 * Given an array of size n+1 that has numbers between [1-n], find the
 * duplicates.
 * Algo. Traverse the list and use the array element as the index and jump
 * to that index and make it -ve if its positive. If its already -ve, we've
 * already visited the index and the number and hence the index should be 
 * duplicate.
 * NB: It works only if duplicate repreates just once. and don't include
 * zero.
 */
#include <stdio.h>
#include <math.h>

void
find_dup(int *A, int sz) {
	int i;

	for(i=0; i<sz; ++i) {
		if (A[A[i]] >= 0) 
			A[abs(A[i])] = -A[abs(A[i])];
		else
			printf("%d ", abs(A[i]));
	}
}

int
main() {
	int arr[] = {2, 7, 4, 1, 8, 6, 1, 7, 5, 3, 8};
	int sz=sizeof(arr)/sizeof(arr[0]);
	find_dup(arr, sz);
}
