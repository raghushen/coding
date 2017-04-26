/*
 * Given an array and a number "k", print how many pairs differ by
 * k-bits. e.g: {2,4,1,3,1} and k=2, has 5pairs that diff. by 2 bits.
 */
#include <stdio.h>

int
bits_diff(int *a, int sz, int k) {
	int i, j, val;
	int cnt, result = 0;

	for (i = 0; i<sz-1; ++i) {
		for (j=i+1; j<sz; ++j) {
			val = *(a+i) ^ *(a+j);
			for (cnt=0; val; cnt++)
				val &= val-1;
			printf("Pair(%d, %d): diff=%d\n", *(a+i), *(a+j), cnt);
			if (cnt == k) result++;
		}
	}
	return (result);
}

int
main() {
	int arr[] = {2, 4, 1, 3, 1};
	int k, sz=sizeof(arr)/sizeof(arr[0]);

	printf("Enter no. of bits to differ: ");
	scanf("%d", &k);

	printf("No. of pairs differ by %d-bits: %d\n", k, bits_diff(arr, sz, k));
}
