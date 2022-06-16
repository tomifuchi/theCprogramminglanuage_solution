#include <stdio.h>

//Counts tabs, blanks and newlines
main()
{
	int c, tb, blk, nl;

	nl = tb = blk = 0;

	while((c=getchar()) != EOF)
		if (c == '\n')
			++nl;
		else if (c == ' ')
			++blk;
		else if (c == '\t')
			++tb;

	printf("Tabs:%d Blanks:%d Newlines:%d\n", tb, blk, nl);
}
