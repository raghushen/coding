#include <stdio.h>
#include <string.h>

int count_decoding(char *digit, int n)
{
	int count[n+1], i;
	count[0] = 1;
	count[1] = 1;

	for (i = 2; i <= n; ++i) {
		count[i] = 0;

		/* If last digit is not 0, last digit will add to the no. of words */
		if (digit[i-1] > '0') {
			count[i] = count[i-1];
			printf("digit[%d-1] = %c\n", (i), digit[i-1]);
		}

		/* If second last digit is smaller than 2 and last digit is smaller
 		   than 7(<26), last 2 digits form a valid char */
		if (digit[i-2] < '2' || (digit[i-2] == '2' && digit[i-1] < '7')) {
			printf("d[%d-2] = %c, [%d-1] = %c\n\n", (i), digit[i-1],
			    (i), digit[i-1]);
			count[i] += count[i-2];
		}
	}
	return (count[n]);
}

int
my_cnt_decode(char *digit, int n)
{
	int i;
	int count[n];

	count[0]=1; // Assume first digit is non-zero
	for (i=1; i< n; ++i) {
		if (digit[i] > '0') {
			count[i] = count[i-1];
			printf("digit[%d-1] = %c; cnt[%d]=%d\n", i,
			    digit[i-1], i, count[i]);
		}

		if (i > 1) {
			if (digit[i-2] < '2' || (digit[i-2] == '2' && digit[i-1] < '7')) {
				printf("c[i] = c[i-2] + c[i]\n");
				printf("c[%d] = %d + %d\n", i, count[i-2], count[i]);
				count[i] = count[i-2] + count[i];
			}
		} else { // i == 1
			if (digit[0] < '2' || (digit[0] == '2' && digit[1] < '7')) 
				count[1] = 2; // count[0] + 1
		}
	} 
	return (count[n-1]);
}

int
main()
{
	char digit[] = "1221";
	int n = strlen(digit);
	printf("size of string = %d\n", n);
	printf("Count is %d\n", count_decoding(digit, n));
	printf("my-Count is %d\n", my_cnt_decode(digit, n));
}
