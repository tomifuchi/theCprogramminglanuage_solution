#include <stdio.h>

#define MAX_WORD_LENGTH		9//World longest word is 190,000 we dont' tollerate that shit here. 51 array place should be for larger than 50 characters.

//Draws a histogram of the length of words.
main()
{
	int c, i, j, wlen;
	int nword[MAX_WORD_LENGTH];

	//Initializing the array
	for(i = 0; i < MAX_WORD_LENGTH; ++i)
		nword[i] = 0;

	wlen = 0;
	while((c=getchar()) != EOF)
	{
		//Lowercase only
		if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) 
			++wlen;
		else if (c == ' '|| c == '\n' || c == '\t')
		{
			//number of x - length word is in nword[x]
			if(wlen > 0){
			  if(wlen < MAX_WORD_LENGTH)
			    ++nword[wlen];
			  //More than maximum at index 0 and
			  else 
			   ++nword[0];
			}
			wlen = 0;
		}
	}

	//Print
	//printf("Word histogram\n");
	//for(i = 0; i < MAX_WORD_LENGTH; ++i)
	//{
	//	//Print non zero element in array.
	//	if (nword[i] > 0)
	//	{
	//		if(i == 0)
	//			//number of word
	//			//that's Larger than MAX_WORD_LENGTH characters
	//			printf(">%d|", MAX_WORD_LENGTH);
	//		else
	//			printf(" %d|", i);
	//		for (j = 0; j < nword[i]; ++j)
	//			printf("X");
	//		printf("\n");
	//	}
	//}
	
	//Print vertically
	printf("Word histogram\n");
	//Height of the histogram (Which is the largest number
	//of frequency in nword[];
	int altitude= 0;
	for(i = 0;i < MAX_WORD_LENGTH; ++i){
		if (altitude < nword[i])
			altitude = nword[i];
	}
	//Decreasing altitude
	//Imagine a line scanning each altitude
	while(altitude > 0){
	  for(i = 0;i < MAX_WORD_LENGTH; ++i){
		if (nword[i] - altitude >= 0)
			printf("X");
		else
			printf(" ");
	  }
	  printf("\n");
	  altitude = altitude - 1;
	}
	for(i = 0;i < MAX_WORD_LENGTH; ++i){
		printf("-");
	}
	printf("\n");
	for(i = 0;i < MAX_WORD_LENGTH; ++i){
		printf("%d",i);
	}
	printf("\n");
}
