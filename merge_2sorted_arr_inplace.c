/*
 * Merge two sorted array without additional space.
 * {2, 4, 5, 6} and {1, 3} after sort
 * {1, 2, 3, 4} and {5, 6}
 */
#include <stdio.h>

void
swap(int *A1, int *A2, int i, int j) {
	int tmp = A1[i];
	A1[i] = A2[j];
	A2[j] = tmp;
}

void
merge_sorted_arr_no_xtra_space(int *arr1, int *arr2, int s1, int s2) {

	int i, j, k;

	for (i=0, j=0; i<s1 && j<s2; ) {
		if (arr1[i] <= arr2[j]) {
			++i;
		} else if (arr2[j] < arr1[i]) {
			swap(arr1, arr2, i, j);
			i++; k=j;
			while (k<s2-1 && arr2[k] > arr2[k+1]) {
				swap(arr2, arr2, k, k+1);
				k++;
			}
		}
	}
}

int
main() {
	// int A1[] = {1, 3, 5, 7, 15};
	// int A2[] = { 2, 6, 22};
	int A1[] = {1, 3, 5, 7};
	int A2[] = {2, 6};
	int i;
	int s1 = sizeof(A1)/sizeof(A1[0]);
	int s2 = sizeof(A2)/sizeof(A2[0]);

	merge_sorted_arr_no_xtra_space(A1, A2, s1, s2);
	
	printf("\nA1 = ");
	for (i = 0; i < s1; ++i)
		printf("%d ", A1[i]);
	printf("\nA2 = ");
	for (i = 0; i < s2; ++i)
		printf("%d ", A2[i]);
	
}
