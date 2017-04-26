/*
 * Sort intput stream with "r", "w", "b" so that all "r"s are ahead of
 * all "w"s and all "w"s are ahead of all "b"s.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void
swap(char *a,int i,int j) {
	char t;
	t = *(a+i);
	*(a+i) = *(a+j);
	*(a+j) = t;
}

void
d_sort(char *s) {
	int i, size = strlen(s);
	int rp, bp;

	rp = bp =0;

	for (i=0; i<size; ++i) {
		switch (*(s+i)) {
			case 'w':
				break;
			case 'b':
				swap(s, bp, i);
				++bp; 
				break;
			case 'r':
				swap(s, rp, i);
				swap(s, bp, i);
				++rp;
				++bp; 
				break;
			default:
				printf("Invalide char");
		}
	}
}

int
main() {
	char s[] = "wbrrbbrbwwbrwwrr";

	d_sort(s);
	printf("Sorted array: %s\n", s);

}
