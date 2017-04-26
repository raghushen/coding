#include <stdio.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid;
    char y='Y';
    char *ptr;
    ptr=&y;
    pid = fork();
    if (pid == 0)
    {
        y='Z';
        printf(" *** Child process ***\n");
        printf(" Address is %p\n",ptr);
        printf(" char value is %c\n",y);
        printf(" mod %d\n",1001%2);
        sleep(5);
    }
    else
    {
        sleep(5);
		y = 'A';
        printf("\n ***parent process ***\n",&y);
        printf(" Address is %p\n",ptr);
        printf(" char value is %c\n",y);
    }
}
