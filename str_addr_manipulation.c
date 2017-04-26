#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <stdint.h>
#include <stdlib.h>

main()
{
	int 	i;
	uintptr_t addr, tmpaddr;
	unsigned char	*rptr;
	char *str = "This is a long string with stuff that make no sense";
	char *str1 = "xxxxxx";

	rptr = (unsigned char *)malloc(100);
	bzero(rptr, 100);

	addr = (uintptr_t)rptr; /* NB: assignment. addr long not ptr */
	bcopy((caddr_t)str, (caddr_t)addr, strlen(str));

	printf("After bcopy: %s\n", rptr);

	tmpaddr = addr;
	printf("kaddr string: %s\n", (char *)addr);
	
	printf("Print as indiv. chars: ");
	for(i=0; i<strlen(str); ++i, tmpaddr++) 
		printf("%c", (char)(*(char *)(tmpaddr))); /* NB: type cast */
	printf("\n");
	
	/* bzero after 10 char */
	bzero((void *)(addr+13), 3);
	printf("After truncated the string is: %s\n", rptr);
	printf("Rest of the string is: %s\n", (rptr+17));
	bcopy((caddr_t)str1, (caddr_t)(addr+13), 6);

	printf("After bcopy xxxx: %s\n", rptr);
}
