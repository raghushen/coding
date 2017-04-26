/* Print all possible permutation of a string */
#include <stdio.h>
#include <string.h>

void
swap(char *a, char *b)
{
	char ch;
	ch = *a;
	*a = *b;
	*b = ch;
}


void
permute(char *a, int l, int r)
{
	int i;

	if (l == r)
		 printf("%s\n", a);
	else {
		for (i = l; i <= r; ++i) {
			swap(a+l, a+i);
			permute(a, l+1, r);
			swap(a+l, a+i);
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
