#include <stdio.h>

#define MAX(X,Y) (X > Y)? X:Y
#define MIN(X,Y) (X < Y)? X:Y


int
collect_max(int *a, int s, int e, int x, int y) {
	// if (s==e || s==e-1||s==e-2)
	int x, y;
	if (s==e) return (*(a+s));
	if (s == e-1) return (MAX(*(a+s), *(a+e)));

	x = *(a+s) + MIN(collect_max(a, s+2, e), collect_max(a, s+1, e-1));
	y = *(a+e) + MIN(collect_max(a, s+1, e-1), collect_max(a, s, e-2));
	printf("X = %d, Y = %d\n", x, y);
	return (MAX(x, y));
}

int
main() {
	int arr[] = {6,9,1,2,16,8};
	int sz=sizeof(arr)/sizeof(int);
	printf("Max. value of first player %d\n", collect_max(arr, 0, sz));
}
