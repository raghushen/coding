#include <stdio.h>

int main(){
    const int a = 0;
    *(int *)&a = 39;
    printf("%d", a);
}
