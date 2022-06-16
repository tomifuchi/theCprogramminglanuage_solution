#include <stdio.h>

//Replace blanks to a blank
main()
{
	int c, blk;

	blk = 0; //Only need this
	while((c=getchar()) != EOF)
	{
		if (c == ' ' || c == '\t') 
		{
			if (blk == 0)
			{	
				blk = 1;
				putchar(' ');
			}
		}
		else
		{
			blk = 0;
			putchar(c);
		}
	}
}
