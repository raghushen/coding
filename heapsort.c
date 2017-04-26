#include <stdio.h>

void
swap(int *A, int i, int j) {
	int tmp = *(A+i);
	*(A+i) = *(A+j);
	*(A+j) = tmp;
}

/*
 * Heapify from not "i" to n.
 * NB: It will not heapify the whole tree, but put node i to its
 * final place.
 */
void
heapify(int *A, int i, int n) {
	int c = i;
	int l = 2*i + 1;
	int r = 2*i +2;

	if (l < n && *(A+c) < *(A+l)) c=l;
	if (r < n && *(A+c) < *(A+r)) c=r; // r<n check incase no right child

	if (c!=i) {
		swap(A, c, i);
		heapify(A, c, n);
	}
}

void
heapsort(int *A, int n) {
	int i;

	/*
	 * For all non-leaf nodes, heapify from bottom-up.
	 * NB: Complete Binary tree of size n has (n/2)-1 non-leaf nodes
	 * and n -(n/2) +1 leaf nodes.
	 */
	for (i=n/2-1; i>=0; --i) {
		heapify(A, i, n);
	}

	/*
	 * For each node starting from last(n-1), swap with root(0) and
	 * last node and heapify reduced size, since last element is
	 * already sorted and removed from the tree by reducing the size.
	 * NB: rest of the tree execpt of the root is already heapified after
	 *     the swap. Just need to call heapify for the swapped element.
	 */
	for (i=n-1; i>0; --i) {
		swap(A, 0, i);
		heapify(A, 0, i);
	}
}

int
main() {
	int i;
	int A[] = {3, 8, 1, 6, 7, 5, 2, 9, 4};
	int sz = sizeof(A)/sizeof(A[0]);

	// heapify(A, 0, sz);
	heapsort(A, sz);

	for (i=0;i<sz;++i) {
		printf("%d ", A[i]);
	}
	printf("\n");
}
