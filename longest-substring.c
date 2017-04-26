#include <stdio.h>
#include <string.h>

int lengthOfLongestSubstring(char* s) {
		int i=1, j, max, n = strlen(s);
	int new_start = 0;
	int cur_max = 1;
	int total_max = 1;

	for (i = 1; i < n; ++i) {
		cur_max = 0;
		for (j=new_start; j < i; ++j) {
			if (s[j] == s[i]) {
				new_start = j+1;
				total_max = (cur_max > total_max) ? cur_max : total_max;
				cur_max = i - j;
				printf("s[%d] = s[%d] = %c: same - cur = %d, total = %d\n",
				    j, i, s[i], cur_max, total_max);
				break;
			}
			cur_max++;
		}
		total_max = (cur_max > total_max) ? cur_max : total_max;
		printf("bump up by 1: cur = %d, total = %d\n", cur_max, total_max); 
	}
	return (total_max);
}

int
main()
{
	char s[] = "abcabcbb";
	printf("Max. substring length of %s = %d\n", s,
		lengthOfLongestSubstring(s));
}
