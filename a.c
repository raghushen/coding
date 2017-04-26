#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int
findmax(int *a, int s) {
    int i;
    if (a == NULL) return (-1);
    int max = *(a+0);
    for (i=0; i<s; ++i) max = max > *(a+i) ? max : *(a+i);
    
    return (max);
}
int
findmin(int *a, int s) {
    int i;
    if (a == NULL) return (-1);
    int min = *(a+0);
    for (i=0; i<s; ++i) min = min < *(a+i) ? min : *(a+i);
    
    return (min);
}

int main(){
    int i, j, k, a_max, b_max, c=0;
    int n; 
    int m; 
	int a_i, b_i;

    scanf("%d %d",&n,&m);
    int *a = malloc(sizeof(int) * n);

    for(a_i = 0; a_i < n; a_i++){
       scanf("%d",&a[a_i]);
    }
    int *b = malloc(sizeof(int) * m);
    for(b_i = 0; b_i < m; b_i++){
       scanf("%d",&b[b_i]);
    }
    
    a_max = findmax(a, n);
    b_max = findmin(b, m);
    
    if (b_max >= a_max) {
        for (i=a_max; i<=b_max; ++i) {
            for (j=0; j<n; ++j) {
                if (i%a[j]!= 0) break;
            }
            for (k=0; k<m; ++k) {
                if (b[k]%i != 0) break;
            }
            if (j==n && k==m) {
				printf("c=%d\n", c);
				++c;
			} else printf("j=%d k=%d\n", j, k);
        }
        printf("%d", c);
    }    
    return 0;
}
