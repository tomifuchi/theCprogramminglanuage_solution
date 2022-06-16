



#include <stdio.h>
#define MAXLINE		20/*maximum input line size*/

int getlines(char line[], int maxline);
void copy(char to[], char from[]);

/* Revise the program so that for an abitrary line,
 * it will print its length. And print it's content
 * as much as possible.
*/

int main()
{
	int len; //current length
	int max; //maximum line length seen so far
	char line[MAXLINE]; //current input line
	char longest[MAXLINE]; //the longest line

	max = 0;
	while ((len = getlines(line, MAXLINE)) > 0)
		if (len > max)
		{
			max = len;
			copy(longest, line);
		}
	printf("Longest line length: %d\n", max + 1);
	if (max > 0) 
		printf("%s", longest);
	return 0;
}

/* getlines: read line into s, return length */
int getlines(char s[], int lim)
{
	int c,i;

	for (i = 0; i < lim - 1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c == '\n')
	{
		s[i] = c;
		++i;
	}
	s[i] = '\0';

	//Should i exceeded lim then.
	if(i == lim - 1 && c != '\n' && c != EOF){
		while((c = getchar()) != EOF && c != '\n')
			++i;
	}
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\0')
		++i;
}
