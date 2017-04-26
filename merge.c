#include <stdio.h>

void
merge(int *arr, int l, int m, int r)
{
	int i, j, k = 0;
	int x, y;
	int L[10];
	int R[10];

	for (i = l, x = 0; i < m; ++i, ++x)  {
		L[x] = *(arr+i);
	}
	for (j = m, y = 0; j <= r; ++j, ++y)  {
		R[y] = *(arr+j);
	}

	for (x=0, y=0, k=l; x<m-l || y<r-m+1; ++k) {
		if (L[x] < R[y]) {
			*(arr+k) = L[x];
			++x;
		} else {
			*(arr+k) = R[y];
			y++;
		}
		if (x >= m-l) {
			*(arr+k) = R[y];
			y++;
		}
		if (y>=r-m+1) {
			*(arr+k) = L[x];
			x++;
		}
	}
	printf("x=%d, y=%d, k=%d\n", x, y, k);
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
	int sz, i;
	int arr[] = { 4, 7, 2, 6, 3, 1, 9 };

	sz = sizeof(arr)/sizeof(arr[0]);

	// mergesort(arr, 0, 6);
	merge(arr, 0, 3, 6);

	printf("Sorted arr:\n");
	for (i = 0; i < 6; ++i)
		printf("%d ", arr[i]);
	printf("\n");
}
