#include <stdio.h>
#include <string.h>
#include <sys/types.h>

int
is_poly(char *s) {
	int i = 0, j = strlen(s)-1;

	while (i < j) {
		printf("Cmp: %c %c\n", *(s+i), *(s+j));
		if (*(s+i) != *(s+j))
			return(0);
		i++; j--;
	}
	return (1);
}


int
main(int argc, char *argv[]) {
	int x = strlen(argv[1]);

	char s[x];

	if (argc != 2) {
		printf("Invalide input\n");
		return(0);
	}

	if (is_poly(argv[1]))
		printf("Poly\n");
	else
		printf("Not Poly\n");
}

