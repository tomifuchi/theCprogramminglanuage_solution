#include <stdio.h>

#define IN	1	/*In a word*/ 
#define OUT	0	/*Out of a word*/

/*1 word per line, accounting for more blanks and spaces*/
main()
{
	int c, state;
	
	state = OUT;

	while((c=getchar()) != EOF)
	{
		if (c == ' ' || c == '\t' || c == '\n')
		{
			if(state == IN)
			{
				state = OUT;
				putchar('\n');
			}
		}
		else if (state == OUT)
			state = IN;
		
		if (state == IN)
			putchar(c);
	}
}

