#include <stdio.h>

int
main() {
	int n = 13;
	int cnt=0;

	for (cnt=0; n; cnt++)
		n &= n-1;
	printf("%d\n", cnt);
}
