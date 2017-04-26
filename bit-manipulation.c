#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	FALSE=0,
	TRUE
} bool;

/*
 * Given an arry of numbers where every number but for one appears in pair.
 * Find that number.
 */
void
find_unique_in_array(int *arr, int sz) {
	int i, result = arr[0];

	for (i=1; i<sz; ++i) {
		result = result^arr[i];
	}
	printf("Result = %d\n", result);
}

/*
 * Given a signed integer, print absolute value of the integer
 */
void
abs_val(signed int i) {
	unsigned int result;
	// int mask = i >> sizeof(int) * 8-1;
	int mask = i >> 31;

	printf("Mask %d\n", mask);

	result = (i+mask) ^ mask;

	printf("Absolute Value of %i = %u\n", i, result);
}

/*
 * Return Number of bits set in an integer/char
 */
int
no_of_bits_set(unsigned char val) {
	int cnt;
	for (cnt=0; val; cnt++) {
		val &= val-1;
	}
	return (cnt);
}

/*
 * Utility fn. for rev_bits(below)
 * Return if bit at nth position is set or not
 */
int
nth_bit_set(unsigned char val, int n) {
	return ( (1<<n) & val);
}

/*
 * Given an unsigned char(or unsigned int) reverse the bits
 * and return the new char/int.
 */
unsigned char
rev_bits(unsigned char val) {
	int i;
	unsigned char result=0;

	// For each position in val, check if a bit set.
	// keep pushing result left with that bit
	for (i=0; i<sizeof(val)*8; ++i) {
		result = (result << 1) | ((nth_bit_set(val, i)) ? 1 : 0);
		// printf("rev_bits: %d-th bit in %u is %u result = %u\n",
		//     i, val, nth_bit_set(val, i), result);
	}
	return (result);
}

/*
 * Given a string, return if all chars are unique(yes) or not(no)
 */
bool
char_set_unique(char *s) {
	int i, sz=strlen(s);
	unsigned int hash_tbl = 0;

	for (i=0; i<sz; ++i) {
		if (hash_tbl & (1<<(s[i]-'a')))
			return (FALSE);
		hash_tbl |= (1 << (s[i]-'a'));
	}
	
	return (TRUE);
}

main() {
	int arr[] = {4, 5, 1, 2, 5, 3, 1, 4, 2, 3, 5};
	int i, sz=sizeof(arr)/sizeof(arr[0]);
	signed int si=-14;
	unsigned char val=181;
	char str[] = "abcdefgha";
	
	// Find only no. that appears odd no. of times in an array
	// find_unique_in_array(arr, sz);


	// Return Absolute value of a given signed int
	// abs_val(si);
	
	// Return no. of bits set in an unsigned integer/char
	// printf("rev_bits = %d\n", rev_bits(val));

	// Given a char. string, are all char unique?
	char_set_unique(str) == TRUE ?
	    printf("%s - Yes\n", str) : printf("%s - No\n", str);
}
