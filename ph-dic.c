/*
 * Given a ph. no.(7 digit), and the no. to alphabet mapping on the phone,
 * generate all possible words given number may represent.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char keypad[10][5] = { "", "", "ABC", "DEF", "GHI", "JKL", "MNO", "PQRS", 
					"TUV", "WXYZ" };

char dic[10][6] = { "ABCDE", "BCDEF", "DEFGH", "IJKLM", "ADGJM", "BEGLN",
					"CFHJM" , "LORTX", "NRUWA", "AAAAA" };

/*
 * Can create better data structure for dic. (like a trie tree) so the
 * search is more optimized
 */
bool
match_found(char *op) {
	int i;
	for (i=0; i<10; ++i)
		if (strncmp(dic[i], op, strlen(op)) == 0)
			return (true);
	return (false);
}

void
word_combo(int *N, int n, int c, char *op) {
 
	int i;

	// We have reached filling output string, print if there is a match
	if (c == n) {
		if (match_found(op)) {
			printf("%s\n", op);
		}
		return ;
	}

	int l = strlen(keypad[N[c]]);


	// If digit is 0 or 1, use  0 in place
	if (N[c] == 0 || N[c] == 1) {
		op[c] = '0';
		word_combo(N, n, c+1, op);
		return ;
	}

	// For each i in keypad char for "current", iterate for every
	// char at that key button(e.g: for 2: "A", "B", "C"
	for (i=0; i<l; ++i) {
		op[c] = keypad[N[c]][i];
		// printf("op[%d] = %c\n", c, op[c]);
		word_combo(N, n, c+1, op);
	}
}

int
main() {
	 int n_arr[] = { 2,3,4,5,6 };
	// int n_arr[] = { 2,2,2,2,2 };
	
	int size = sizeof(n_arr)/sizeof(n_arr[0]);
	char result[size + 1];

	memset((void *)result, 0, size);

	/* word_combo(input_number, size_of_input, cur_location, output_string); */
	 word_combo(n_arr, size, 0, result);
}
