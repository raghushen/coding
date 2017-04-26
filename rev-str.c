#include <stdio.h>
#include <string.h>

void
rev_str(char *s)
{
	int i, j, n = strlen(s);
	char ch;
	for (i=0, j=n-1; i < j; ++i, --j) {
		ch = *(s+i);
		*(s+i) = *(s+j);
		*(s+j) = ch;
	}
}

int
main()
{
	char s[] = "my string";

	rev_str(s);
	printf("rev.ed string %s\n", s);
}
