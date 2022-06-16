#include <stdio.h>


//A simple line to line copy program
main()
{
	int c;

	//USe this in turn to understand how
	//getchar in this library works.
	c = getchar();
	putchar(c);
	c = getchar();
	putchar(c);
	c = getchar();
	putchar(c);
	//while (c != '\n')
	//{
	//	putchar(c);
	//	c = getchar();
	//}
	
	//Version 2
	//while((c=getchar())!=EOF)
	//	putchar(c);

	//return 0;
}
