#include <stdio.h>

int
fib(int n)
{
	if (n == 0 || n == 1) return (n);
	return (fib(n-1) + fib(n-2));
}

long long F[100];

long long
fib_memoization(int n) {
	if (F[n] != -1) return (F[n]);
	F[n] = fib_memoization(n-1) + fib_memoization(n-2);
	printf("Returning %d\n", F[n]);
	return (F[n]);
}

int
main(int argc, char *argv[])
{
	int i, n;

	if (argc < 2) {
		printf("Usage: %s <val>\n", argv[0]);
		return(1);
	}

	n = atoi(argv[1]);

	F[0] = 0;
	F[1] = F[2] = 1;
	for (i=3; i<100;++i) F[i] = -1;

	// printf("Fib seq.%d = %d\n", n, fib(n));
	 printf("Fib seq. %d = %lld\n", n, fib_memoization(n));
}
