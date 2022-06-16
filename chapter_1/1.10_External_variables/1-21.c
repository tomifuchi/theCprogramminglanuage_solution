



#include <stdio.h>
#define MAXLINE		1000 /*maximum input line size*/
#define TABWIDTH	4

int getlines(void);

int  entab_len;
char line[MAXLINE]; //current input line
char entab_line[MAXLINE]; 

//Writing with external variables looks fun, but it's not clearn.
int main()
{
	int len; //current length
	extern int entab_len;
	extern char entab_line[];

	while ((len = getlines()) > 0){
		printf("%s", entab_line);
		printf("Ori len: %d, Mod len: %d\n", len, entab_len);
	}
	return 0;
}

/* getlines: rea line into s, return length with detabbing filter*/
int getlines(void)
{
	int c,i,j;
	int nspace = 0;

	extern int entab_len;
	extern char line[];
	extern char entab_line[];

	for (i = 0,j = 0; i < MAXLINE - 1 \
			&& j < MAXLINE - 1 \
			&& (c=getchar())!=EOF \
			&& c!='\n'; ++i, ++j){
		line[i] = c;
	        entab_line[j] = c;
		if (c == ' '){
			++nspace;
			if (nspace == TABWIDTH){
			   j = j - (TABWIDTH - 1);
			   entab_line[j] = '\t';
			   nspace = 0;
			}
		} else nspace = 0;
	}
	if (c == '\n')
	{
		line[i] = c;
		entab_line[j] = c;
		++i;
		++j;
	}
	line[i] = '\0';
	entab_line[j] = '\0';

	entab_len = j;
	return i;
}
