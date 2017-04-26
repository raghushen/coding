/*
 * Given a string, can you find if it has any dup char. in it.
 * Use 32 integer as a hash map and set the bits corresponding to each
 * char. If the bit is already set, then there is a duplicate.
 */
#include <stdio.h>
#include <string.h>

typedef enum {
	FALSE=0,
	TRUE
} bool;

bool
is_unique(char *s) {
	int sz = strlen(s);
	int i, bit_hash=0;

	for (i=0; i<sz; ++i) {
		if (bit_hash&(1<<(*(s+i)-'a'))) return (FALSE);
		bit_hash |= 1<<(*(s+i)-'a');
	}
	return (TRUE);
}

int
main() {
	char *s = "abcdea";

	if (is_unique(s)) printf("Yes\n");
	else printf("No\n");
}
