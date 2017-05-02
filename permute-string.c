/*
 * Print all possible permutation of a string.
 * Algo.:
 *	Recursively permute smaller and smaller strings.
 *	Swap elements in each position with first char.
 *	For ex.: "ABCD"
 *	1) Swap A with A, then A with B, then A with C then A with D.
 *	   We get: "ABCD, BACD, CBAD, DBCA"
 *		* Now permute reduced string: starting from "ABCD"
 *	   	i.e: "BCD":
 *			Now swap First with every  char.
 *			i.e: B with B, B with C and B with D
 *		  	   "BCD", "CBD", DCB"
 *				Now permute substring starting from "BCD"
 *				i.e.: "CD".
 *					Now swap the sub string:
 *					"CD" and "DC"
 *						Permute substring: starting from "CD"					
 *						i.e: "D".
 *						Since there are no more substring, print the string: "ABCD" and return.
 *						Perumte substring: "DC", i.e.: "C"
 *						Since no more substrings, print: ABDC.
 *				Now permute substring "CBD"...and so on...
 */  
#include <stdio.h>
#include <string.h>

void
swap(char *a, char *b)
{
	char ch;
	ch = *a;
	*a = *b;
	*b = ch;.
}


void
permute(char *a, int l, int r)
{
	int i;

	/* If there are no more substrings */
	if (l == r)
		 printf("%s\n", a);
	else {
		/*
		 * For each char. in the string, swap with the first char.
		 * i.e: Replace 'A' in "ABCD" with each char. in the string:
		 *      ABCD(A and A), BACD(A and B), CBAD(A and C) and DBCA(A and D).
		 */
		for (i = l; i <= r; ++i) {
			swap(a+l, a+i);
			permute(a, l+1, r);
			swap(a+l, a+i);  /* During unwind, restore back to previous level in recursion */
		}
	}
}

int
main()
{
	char str[] = "abc";
	int s = sizeof(str);
	permute(str, 0, s);
}
