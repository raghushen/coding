/*
 * Given an arry of coin values and a sum, find how many ways you can get
 * the sum using any number/combination of coins from the array.
 * You can assume infinite number of coins of each denomination.
 */

#include <stdio.h>

int
no_of_ways(int *coins, int sz, int sum) {
	int r, c;
	int result[sz][sum+1];

	result[0][0] = 0;
	for (c=1; c<=sum; ++c) {
		if (c%(*(coins+0)) == 0) {
			result[0][c] = 1;
		} else {
			result[0][c] = 0;
		}
	}
	for (r=1; r<sz; ++r) {
		for (c=0; c<=sum;++c) {
			if (c < *(coins+r)) result[r][c] = result[r-1][c];
			else if (*(coins+r) == c) result[r][c] = result[r-1][c] + 1;
			else {
				result[r][c] = result[r-1][c]+result[r][c-*(coins+r)];
			}
		}
	}
	return (result[sz-1][sum]);
}

int
main() {
	int coins[] = {2, 3, 4, 7};
	int sum, sz=sizeof(coins)/sizeof(coins[0]);

	printf("Enter sum:");
	scanf("%d", &sum);
	
	printf("No. of ways: %d\n", no_of_ways(coins, sz, sum)); 
}
