#include <stdio.h>

#define IN	1	/*In a word*/ 
#define OUT	0	/*Out of a word*/

/*Count lines, words, characters of the input*/
/*How do you test this program ?
 *IN the book it said that definition of a word
 *is any sequence of characterS, repeat characters.
 *So by entering
 * a b c we will get 1 line, 3 words, and 6 letters*/
main()
{
	int c, state, nl, nw, nc ;
	
	nl = nw = nc = 0;
	state = OUT;

	while((c=getchar()) != EOF)
	{
		++nc; //Counts newlines, and blanks, tabs.
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
