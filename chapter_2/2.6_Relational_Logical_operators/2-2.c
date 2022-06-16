



#include <stdio.h>
#define MAXLINE		1000/*maximum input line size*/

int getlines(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len; //current length
	char line[MAXLINE]; //current input line

	while ((len = getlines(line, MAXLINE)) > 0)
		printf("%s", line);
	return 0;
}

/* getlines: read line into s, return length */
int getlines(char s[], int lim)
{
	int c, i = 0;
	for(i = 0;i < lim - 1;++i){
		c = getchar();
		if(c == EOF)
			break;
		else if (c == '\n')
			break;
		else
		s[i] = c;
	}
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	return i;
}
