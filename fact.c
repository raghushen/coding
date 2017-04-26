#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int
fact(int n) {
    if (n == 0 || n == 1) return (n);
    return (n*fact(n-1));
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d", fact(n));
    return 0;
}
