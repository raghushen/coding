#include <stdio.h>

int
partition(int *arr, int l, int h) {
	int pivot = *(arr+h);
	int i = l, j=0;

	for (j = l, j < h; ++j) {
		if (pivot < *(arr+j)) {
			swap(arr, j, i);
			i++;
		}
	}
	swap(arr, h, i);
	return (i+1); 
}

void
quickSort(arr, l, h) {

	while (l < h) {
		int p = partition(arr, l, h);

		quickSort(arr, l, p-1);
		quickSort(arr, p+1, h);
	}
}
