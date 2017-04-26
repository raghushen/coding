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
