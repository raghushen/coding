/*
 * Given 2D array such that the values are increasing from left to right
 * and top to bottom, write an efficient algo. to find its cordinates a
 * given val.
 */

#include <stdio.h>

int matrix[4][5] =	{ { 1, 2, 3, 4, 5 },
					  { 6, 7, 8, 9, 10 },
					  { 11, 12, 13, 14, 15},
					  { 16, 17, 18, 19, 20}
					};

int
// There are couple of ways 2D array can be passed:
// Method a: pass the whole array as below:
// search_matrix(int arr[4][5], int val, int i, int j, int n, int m)
// Or,
// Pass pointer to lows of array of length 5.
search_matrix(int (*arr)[5], int val, int i, int j, int n, int m)
{
	int ret = 1;
	if (arr[i][j] == val) {
		printf("Found match: Arr[%d][%d]\n", i, j);
		return (0); // Bool 1=true, 0 = false
	}
	if (i < n && j < m && j >= 0) {
		if (val < arr[i][j])
			ret = search_matrix(arr, val, i, j-1, n, m);
		else if (val > arr[i][j])
			ret = search_matrix(arr, val, i+1, j, n, m);
	} else {
		printf("Did not find element\n");
		return ret;
	}
}

int
main(int argc, char *argv[])
{
	/*
	 * Note: search starts from top right corner: matrix[0][n]
	 * Nb: Index goes from rows: (0 - 3) and col: (0 - 4) 
	 */
	// search_matrix, [][], [0], [4] n=4, m=5)
	if (argc < 2) {
		printf("Usage %s <val>\n", argv[0]);
		return (1);
	}
	search_matrix(matrix, atoi(argv[1]), 0, 4, 4, 5);
}
