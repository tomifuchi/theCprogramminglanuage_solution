#include <stdio.h>

#define IN	1	/*In a word*/ 
#define OUT	0	/*Out of a word*/

/*Count lines, words, characters of the input*/
main()
{
	int c, state, nl, nw, nc ;
	
	nl = nw = nc = 0;
	state = OUT;

	while((c=getchar()) != EOF)
	{
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t')
			state=OUT;	
		else if (state == OUT)
		{
			state = IN;
			++nw;
		}
	}
	printf("Lines:%d Words:%d Characters:%d\n", nl, nw, nc);
}
