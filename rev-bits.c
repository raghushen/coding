/*
 * Reverse the bits set in a number. For easy use, use 8 bit number(char)
 * eg: Reverse of 20: 00010100 is 40: 00101000
 */
#include <stdio.h>

void
bit_rev1(char num) {
	int i, sz = sizeof(num)*8;
	// unsigned int t, rev;
	char t = 0;
	char rev = 0;

	for (i=0; i<sz; ++i) {
		t = (1 << i) & num;
		if (t) {
			// printf("loop %d bit set %d new set %d\n", i, t, sz-i); 
			rev = rev | (1 << (sz-1-i));
		}
	}
	printf("bit_rev1 of %d is %d\n", num, rev);
}

/*
 * swap (0-7), (1-6), (2-5), (3-4)
 */
void
bit_rev2(char num) {
	int i=0, j=sizeof(num)*8;
	char i_bit, j_bit, new_num = 0;

	for (i=0, j=sizeof(num)*8-1; i < j; ++i, --j) {
		/* Swap bits i and j */
		new_num = (new_num | ((1<<i)&num) << (j-i)); 
		new_num = (new_num | ((1<<j)&num) >> (j-i)); 
	} 
	printf("bit_rev2 of %d is %d\n", num, new_num);
}

int
main(int argc, char *argv[]) {

	char num;
	
	if (argc != 2) {
		printf("Usage: %s [num < 256]\n", argv[0]);
		return (1);
	}

	num = atoi(argv[1]);

	bit_rev1(num);
	bit_rev2(num);
}
