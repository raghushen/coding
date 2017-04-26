#include <stdio.h>

void
swap(int *A, int i, int j) {
	int tmp=*(A+i);

	*(A+i) = *(A+j);
	*(A+j) = tmp;
}

int
partition(int *A, int l, int h) {
	int pivot = *(A+h);

	int i, j;
	i = l-1; j = l+1;

	for (j=l; j<=h-1; ++j) {
		if (*(A+j) < pivot) {
			++i;
			swap(A, i, j);
		}
	}
	swap(A, i+1, h);
	return (i+1);
}

void
quicksort(int *A, int l, int h) {
	int pi;

	if (l < h) {
		pi = partition(A, l, h);
		quicksort(A, l, pi-1);
		quicksort(A, pi+1, h);
	}
}

int
main() {
	int A[]= { 10, 2, 3, 5, 15, 18, 4, 12};
	int i, sz=sizeof(A)/sizeof(A[0]);

	quicksort(A, 0, sz-1); // NB: closed set, inclusive(sz-1 and not sz)
	for (i=0; i<sz; ++i) printf("%d ", A[i]);
}
