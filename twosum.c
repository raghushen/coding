#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target) {
    int i, j;
    
    if (numsSize == 0) return (NULL);
    
    int *r = (int *) malloc(2 * sizeof(int));
    for (i=0; i<numsSize-1; ++i) {
        for (j=i+1; j<numsSize; ++j) {
            if (*(nums+i) + *(nums+j) == target) {
                *(r+0) = i;
                *(r+1) = j;
                return (r);
            }
        }
    }
    return (NULL);
}

int
main() {
    int A[3]={3,2,4};
    int *R;
    
    R = twoSum(A, 3, 6);
    printf("[%d, %d]\n", *(R+0), *(R+1));
}
