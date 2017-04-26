/*
 * Given an arry of numbers where every number but for one appears in pair.
 * Find that number.
 */
#include <stdio.h>
#include <stdlib.h>

int
main() {
	int arr[] = {4, 5, 1, 2, 5, 3, 1, 4, 2, 3, 5};
	int i, sz=sizeof(arr)/sizeof(arr[0]);
	int result = arr[0];

	for (i=1; i<sz; ++i) {
		result = result^arr[i];
	}
	printf("Result = %d\n", result);
}
