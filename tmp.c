#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Logic:
 *  * 1. current lowest from the start will be the buying/selling price
 *   * 2. As we check more samples, selling price is changed to the new sample as long as price is increasing.
 *    * 3. If current price sample is less than previously considered buying price, then we restart step 1,2, with new start as current price and remembering last profit.
 *     * 4. If the new price band turns out to generate more profit than last price band, we forget last priceband and repeat steps 1-4.
 *      */
void max_profit (int *price, int start, int end, int buy, int *profit)
{
	/* function parameter - profit is profit from last price band*/

	/* current buy and sell prices and profit */
	int b = price[start];
	int p = 0;
	
	/* while price does not drop below current buying price, calculate profit */
	int i = start+1;
	while (i <= end) {
		p = price[i] - b;
		if (p > *profit) {
			/* new price band is better than old one, forget old band profit */
			*profit = p;
		}
		/*
 * 		 * Note: since current buy price is better than last buy price, if current 
 * 		 		 *       sell price is better than last band sell price, new band will always
 * 		 		 		 *       have better profit, hence *profit will never increase unless p > *profit.
 * 		 		 		 		 */

		/* price dropped, time to track the new price band */ 
		if (price[i] < b) {
			break;
		}
		i++;
	}

	if (i <= end) {
		/* process new price band */
		max_profit (price, i, end, b, profit);
	}

	return;
}

int main (int argc, char **argv) 
{
	int i, n, *price, profit=0;

	printf("\nEnter the number of price samples:");
	scanf("%d", &n);
	price = (int *) malloc (sizeof(int) * n);
	
	printf("\nEnter %d price samples separated by space:", n);
	for (i=0; i<n; i++) {
		scanf("%d", &price[i]);
	}
	
	max_profit(price, 0, n-1, 0, &profit);
	
	printf("\nMax possibel profit is => %d\n", profit);
	return 0;
}

