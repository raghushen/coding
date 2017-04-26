/*
 * Given no. of eggs(e) and number of floors(f), what is the optimal number
 * of drops you need to find where the eggs starts to break when dropped.
 */
#include <stdio.h>

/*
 * How to pass 2D array:
 * 1) pass the whole array if you know the size up front:
 * 		int fn(int A[4][5]) {
 * 		    arr[i][j] = 3; // referenced like this
 * 	  and called by:
 * 	     fn(A);
 *
 * 2) If no. of collums known globally:
 * 		fn(int A[][5], int m) {
 * 			arr[i][j] = 4 // referenced like this.
 * 	   and called like:
 * 	   		fn(A, 4); 
 *
 * 3) If n and m are variables:
 * 		fn(int m, int n, int A[][n]) {  // Note n is passed before array
 *			arr[i][j] = 4;
 *		and called like
 *			fn(n, m, A);
 *
 * 4) Using a Pointer:
 * 		Note: 2D array is just a 1D array with rows added at the end.
 * 		fn(int *A, int n, int m) {
 * 		 int i, j;
 * 		 for(i=0;i<m;++i)
 * 		    for (j=0;j<n;++j)
 * 		       *((A+i*n)+j) = 4;
 *
 * 		 and called like:
 * 		     fn(A, n, m);
 */

#define MAX(X, Y) X > Y ? X : Y

void
calc_no_of_drops(int A[2][8], int e, int f) {
	int r, c, i, j, k;
	int min_arr[8], min_val;

	for (c=0; c<f; ++c) A[0][c] = c;
	for (r=0; c<e; ++r) A[r][0] = 0;

	for (r=1; r<e; ++r) {
		for (c=0; c<f; ++c) {
			for (i=c, j=1; i>0, j<=c; ++j, --i) {
				if (c < r)
					A[r][c] = A[r-1][c];
				else {
					min_arr[j-1] = 1 + (MAX(A[r-1][c-i], A[r][c-j]));
					// printf("MAX([r-1][c-%d], [r][c-%d])\n", i, j);
				}
				min_val = min_arr[0];
				for (k=1; k<j; ++k) {
					min_val = min_val < min_arr[k]? min_val : min_arr[k];
				}
				A[r][c] = min_val;
			}
			// printf("\n");
		}
	}
}

int
main() {
	// int e, f;

	// printf("Enter # of eggs: ");
	// scanf("%d", &e);
	// printf("Enter # of floors: ");
	// scanf("%d", &f);

	int A[2][8];
	int i, j;

	calc_no_of_drops(A, 2, 8);
	// for (i=0;i<2;++i) {
	// 	for (j=0;j<8;++j) {
	// 		printf("A[%d][%d]=%d ", i, j, A[i][j]);
	// 	}
	// printf("\n");
	// }

	// Last element in the array has the answer
	printf("2-eggs, 7 floors: No. of drops: %d\n", A[1][7]);
}
