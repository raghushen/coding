#include <stdio.h>
#include <stdarg.h>

static void
var_msg(int n, char *fmt, ...)
{
	va_list	ap;
	char	msgbuf[255];

	va_start(ap, fmt);
	vsprintf(msgbuf, fmt, ap);
	printf("va string[?%d]: %s\n", n, msgbuf);
	va_end(ap);
}

main()
{
	var_msg(1, "first %s", "string");
	var_msg(2, "Second %s %s", "string", "list");
}
