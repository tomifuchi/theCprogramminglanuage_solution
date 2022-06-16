



#include <stdio.h>
#define MAXLINE		50 /*maximum input line size*/

int getlines(void);
void copy(void);

int max; //maximum line length seen so far
char line[MAXLINE]; //current input line
char longest[MAXLINE]; //the longest line


int main()
{
	int len; //current length

	extern int max;
	extern char longest[];

	max = 0;
	while ((len = getlines()) > 0)
		if (len > max)
		{
			max = len;
			copy();
		}
	if (max > 0) //if theres a line
		printf("%s", longest);
	return 0;
}

/* getlines: rea line into s, return length */
int getlines(void)
{
	int c,i;
	extern char line[];

	for (i = 0; i < MAXLINE - 1 && (c=getchar())!=EOF && c!='\n'; ++i)
		line[i] = c;
	if (c == '\n')
	{
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}

/* copy: copy 'from' into 'to'; assume to is big enough */
void copy(void)
{
	int i;
	extern char longest[], line[];

	i = 0;
	while ((longest[i] = line[i]) != '\0')
		++i;
}
