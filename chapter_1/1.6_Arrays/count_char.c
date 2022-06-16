#include <stdio.h>

#define ALPHABET_LEN 	26

//Draws a histogram of the freqency of the letters.
main()
{
	int c, i, j;
	int nchar[ALPHABET_LEN];

	//Initializing the array
	for(i = 0; i < ALPHABET_LEN; ++i)
		nchar[i] = 0;

	while((c=getchar()) != EOF)
		if((c >= 'a' && c <= 'z')||(c >= 'A' && c <= 'Z'))
			++nchar[c - 'a'];

	//Print
	printf("Characters histogram\n");
	for(i = 0; i < ALPHABET_LEN; ++i)
	{
		printf("%c|", i+'a');
		if (nchar[i] > 0)
			for (j = 0; j < nchar[i]; ++j)
				printf("X");
		printf("\n");
	}
}
