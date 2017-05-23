/*
 * Find missing number from a list of consecutive numbers.
 * E.g: {1, 2, 3, 4, 6, 7, 8} - return 5
 */
 #include <stdio.h>

int
find(int *A, int l, int r) {

    int val;

    int m = l + (r-l)/2;
    printf("l=%d, m=%d r=%d\n", l, m, r);

    if (l == r) return (*(A+l)-1);
    if (l == r-1) return (*(A+l)+1);


    printf("Cmp[%d]: %d and %d\n", l+m, *(A+m), (*A)+m);

    if (*(A+m) > (*A) + m) {
        val = find(A, l, m);
    } else {
        val = find(A, m, r);
    }
    return (val);
}

int
main() {
    int A[] = { 0, 2, 3, 4, 5, 6, 7, 8};
    // int A[] = { 3, 4, 5, 6, 7, 9, 10};
    int sz = sizeof(A)/sizeof(A[0]);
    printf("Missing no. %d\n", find(A, 0, sz-1));
}
