



#include <stdio.h>
#define MAXLINE		50 /*maximum input line size*/
#define TABWIDTH	4

int getlines(void);
void detab(int pos);

int  detab_len;
char line[MAXLINE]; //current input line
char detab_line[MAXLINE]; //the longest line

//Writing with external variables looks fun, but it's not clearn.
int main()
{
	int len; //current length
	extern int detab_len;

	while ((len = getlines()) > 0){
		printf("%s", detab_line);
		printf("Ori len: %d, Mod len: %d\n", len, detab_len);
	}
	return 0;
}

/* getlines: rea line into s, return length with detabbing filter*/
int getlines(void)
{
	int c,i,j;

	extern int detab_len;
	extern char line[];
	extern char detab_line[];

	for (i = 0,j = 0; i < MAXLINE - 1 \
			&& j < MAXLINE - 1 \
			&& (c=getchar())!=EOF \
			&& c!='\n'; ++i, ++j){
		line[i] = c;
		if (c == '\t'){
			detab(j);
			j = j + TABWIDTH - 1;
		}
		else detab_line[j] = c;
	}
	if (c == '\n')
	{
		line[i] = c;
		detab_line[j] = c;
		++i;
		++j;
	}
	line[i] = '\0';
	detab_line[j] = '\0';

	detab_len = j;
	return i;
}

void detab(int pos){
	int i; 
	extern char detab_line[];

	for(i = 0; i < TABWIDTH; ++i)
		detab_line[pos + i] = ' ';
}
