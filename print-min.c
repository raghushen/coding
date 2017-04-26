/*
 * if f is a fn. that return min. of 2 numbers
 * f(2) = min(int, int)
 * Extend this to f(3) = min(int, min(int, int))
 * Given "n" print f(n) function
 */
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

char *
print_min(int n) {
    char *str;
    char *t_str;
    
    if (n < 2) return(NULL);
    str = (char *) malloc(10000*sizeof(char));
    if (n == 2) {
        memset(str, 0, 10000);
        sprintf(str, "min(int, int)");
    } else {
        memset(str, 0, 1000);
        t_str = print_min(n-1);
        sprintf(str, "min(int, %s)", t_str);
        free(t_str);
    }
    return (str);
}

int main(){
    int n; 
    scanf("%d",&n);
    printf("%s\n", print_min(n));
    return 0;
}
