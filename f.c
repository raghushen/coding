#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int main(){
    int a0, t, cnt, dev, rem; 
    scanf("%d",&t);
    for( a0 = 0; a0 < t; a0++){
        int n; 
        scanf("%d",&n);
        dev = n; cnt = 0;
        printf("Num = %d\n", n);
        while (dev > 0) {
            rem = dev%10;
            dev = dev/10;
            printf("dev=%d, rem=%d\n", dev, rem);
			if (rem != 0)
            	if (n%rem == 0) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
