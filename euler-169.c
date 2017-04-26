#include <stdio.h>

int
no_of_ways(int n) {
	if (n==0) { printf ("N==0, return 1\n") ; return (1); }

	printf("Enter N = %d\n", n);
	if (n%2 == 0) {
		printf("Even N = %d\n", n);
		return no_of_ways(n/2) + no_of_ways(n-1);
	}

	printf("Odd before Return N = %d\n", n);
	return (no_of_ways(n/2));
}

int
main() {
	int n;
	printf("Enter no.:");
	scanf("%d", &n);
	printf("\n");
	printf("Result: %d\n", no_of_ways(n));
}
