#include <stdio.h>

int
permute(int n) {
	if (n == 1) return (n);
	else
		return (n * permute(n-1));
}

int
main() {
	int n;
	scanf("%d", &n);

	printf("Perm(%d): %d\n", permute(n));
}
