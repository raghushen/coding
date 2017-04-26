#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main() {
    int q, a0; 
    scanf("%d",&q);
    for(a0 = 0; a0 < q; a0++){
        long n; int r7, r4;
        scanf("%ld",&n);
        if (n > 3) {
            r7 = n%7;
            r4 = n%4;
            if (r7 == 0 || r7 == 1 || r4 == 0)
                printf("%ld - Yes\n", n);
            else
                printf("%ld-No\n", n);
        } else {
            printf("%ld - No\n", n);
        }
    }
    return 0;
}
