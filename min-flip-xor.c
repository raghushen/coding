/*
 * Given A, B and C, find no. of bits that needs to be flipped in A(or B)
 * so that A XOR B = C.
 */
#include <stdio.h>

int
min_no_flips(unsigned int a,unsigned int b,unsigned int c) {
	int i, cnt = 0;
	unsigned int res, mask = 0;
	for (i=0; i<32; ++i) {
		mask = (1<<i);
		res = mask & c;
		if (res) { // if i-th bit is set, i-th bit in a and b should be diff.
			if ( !((mask&a) ^ (mask&b)) ) cnt++;
		} else {
			if ( ((mask&a) ^ (mask&b)) ) cnt++;
		}
	}
	return (cnt);
}

int
main() {
	unsigned int A = 20;
	unsigned int B = 2;
	unsigned int C = 19;

	printf("%d\n", min_no_flips(A, B, C));
	
}
