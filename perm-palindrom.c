/*
 * Given a string, print if any permutation of the string can form a palindrom
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum {
	TRUE=0,
	FALSE
} boolean;


int
main() {
	char *str = "abcdabcdeefg";
	int i, cnt = 0, hash[26], sz=strlen(str);
	boolean flag;

	for (i=0; i<26; ++i) hash[i] = 0;

	for (i=0; i<sz; ++i) hash[*(str+i) - 'a']++;

	flag = TRUE;
	if (sz%2 == 0) {
		for (i = 0; i<26; ++i) {
			if (hash[i]%2 == 1) {
				flag = FALSE;
				break;
			}
		}
	} else {
		cnt = 0;
		for (i = 0; i<26; ++i) {
			if (hash[i]%2 == 1) {
				++cnt;
				if (cnt > 1) {
					flag = FALSE;
					printf("exits for i=%d with cnt %d\n", i, cnt);
					break;
				}
			} 
		}
	}
	if (flag == TRUE)
		printf("%s can form a palindrom\n", str);
	else 
		printf("%s cannot form a palindrom\n", str);
}
