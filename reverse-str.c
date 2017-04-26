#include <stdio.h>
#include <string.h>

void
revstr(char *str) {

	char tmp;
	int i, j;

	if (str == NULL || strlen(str) <1)
		return ;

	for (i = 0, j = strlen(str) -1; i <j; ++i, --j) {
		tmp = *(str+i);
		*(str+i) = *(str+j);
		*(str+j) = tmp;
	}
}

int main()
{

	// char s[] = "string is a string";
	char s[] = "";

	printf("strlen = %d\n", strlen(s));

	revstr(s);
	printf("rev. string %s\n", s);

}
