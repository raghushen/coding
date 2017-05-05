/*
 * Given price of stock everyday, find what price when bought would maximize profit when sole.
 * Note: you can not sell before buying the share.
 */
#include <stdio.h>

int
get_max_profit(int *a, int sz) {
	int i, j, cur_max, total_max;

	cur_max = total_max = 0;
	
	for (i=0; i<sz-1; ++i) {
		if (a[i] > a[i+1]) { // Optimize loop by starting with a value where we make non-zero profit.
			continue;
		}
		for (j=i+1; j<sz; ++j) {
			cur_max = a[j] - a[i];
			total_max = (cur_max > total_max)? cur_max : total_max;
			if (cur_max <= 0) {
				i = j-1; // Loop will add +1 to make it j
				break;
			}
		}	
	}

	return (total_max);
}

int
get_max_profit_optimized(int *a, int sz) {
	int i, min_thus_far, max_profit, cur_profit;

	max_profit=cur_profit=0;
	min_thus_far = *(a+0);
	for (i=2; i<sz; ++i) {
		min_thus_far = (min_thus_far > *(a+i))? *(a+i) : min_thus_far;
		cur_profit = *(a+i) - min_thus_far;
		max_profit = (cur_profit > max_profit)? cur_profit : max_profit;
	}
	return (max_profit);
}

int
main() {
	// int y_price[]={6,5,4,3,2,1};
	int y_price[]={10, 7, 5, 8, 11, 9, 4, 12};
	int sz=sizeof(y_price)/sizeof(int);

	printf("Max Profit is %d\n", get_max_profit(y_price, sz));
	printf("Max Profit optimized %d\n", get_max_profit_optimized(y_price, sz));

}
