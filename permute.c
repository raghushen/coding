#include <stdio.h>
#include <string.h>

void
swap(char *s, int l, int r) {
	char ch;

	ch = *(s+l);
	*(s+l) = *(s+r);
	*(s+r) = ch;
}

void
permute(char *str, int s, int e) {

	int i;

	if (s==e) printf("%s\n", str);

		for (i=s; i<=e; ++i) {
			swap(str, i, s);
			permute(str, s+1, e);
			swap(str, i, s);
		}
}

int
main() {
	char s[] = "abce";
	permute(s, 0, strlen(s)-1);
}
