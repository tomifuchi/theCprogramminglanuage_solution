#include <stdio.h>

//Replace tabs, backslash, backspace with
//\t, \\, \b
main()
{
	int c;

	while((c=getchar()) != EOF)
	{
		if (c == '\t'){
			c = 't';
			putchar('\\');
		}
		//Some how getchar don't detects \b oh well.
		if (c == '\b'){
			c = 'b';
			putchar('\\');
		}
		if (c == '\\'){
			putchar('\\');
		}
		putchar(c);
	}
}
