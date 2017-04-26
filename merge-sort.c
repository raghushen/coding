#include <stdio.h>

void
merge(int *arr, int l, int m, int r) {
	int a[m-l+1], b[r-m];
	int i, j, k;


	for (i=0; i<=m-l; ++i) {
		a[i] = *(arr+l+i);
		printf("a[%d] = %d ", i, a[i]);
	}

	printf("\n");
	for (i=0; i<r-m; ++i) {
		b[i] = *(arr+m+1+i);
		printf("b[%d] = %d ", i, b[i]);
	}
	printf("\n");

	i=j=0; k=l;
	while (k<r-l) {
		if (a[i] < b[j]) {
			printf("from a[%d] k=%d\n", a[i], k);
			*(arr+k) = a[i++];
		} else {
			printf("from b[%d] k=%d\n", b[j], k);
			*(arr+k) = b[j++];
		}
		k++;
	} 
}

void
mergesort(int *arr, int l, int r) {

	int m = l + (r-l)/2;

	if (r == l) return;

	mergesort(arr, l, m);
	mergesort(arr, m+1, r);
	merge(arr, l, m, r);
}

int
main() {
	int i, sz, arr[] = {1, 5, 7, 3, 10, 7, 2};
	sz = sizeof(arr)/sizeof(arr[0]);
	mergesort(arr, 0, sz-1);
	// merge(arr, 0, 3, sz-1);
	for (i = 0; i<sz; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
