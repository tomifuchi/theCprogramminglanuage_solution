



#include <stdio.h>
#define MAXLINE		1000 /*maximum input line size*/
#define COLWIDTH	20

int getlines(void);
void detab(int pos);

char line[MAXLINE]; //current input line
char fold_line[MAXLINE]; 

//Writing with external variables looks fun, but it's not clearn.
int main()
{
	int len; //current length
	extern char fold_line[];

	while ((len = getlines()) > 0){
		printf("%s", fold_line);
	}
	return 0;
}

int ncol = 0;
int getlines(void)
{
	int c,i,j;
	int pos = -1;

	extern int ncol;
	extern char line[];
	extern char fold_line[];

	for (i = 0,j = 0; i < MAXLINE - 1 \
			&& j < MAXLINE - 1 \
			&& (c=getchar())!=EOF \
			&& c!='\n'; ++i, ++j){
		++ncol;
		line[i] = c;
		fold_line[j] = c;
		if (c == ' ')
		  pos = j;

		if (ncol == COLWIDTH){
			  if (pos != -1){
			    fold_line[pos] = '\n';
			    ncol = j - pos;
			    pos = -1;
			  }
			  else {
			    ncol = 0;
			    fold_line[j] = '\n';
			  }
		}
	}
	if (c == '\n')
	{
		line[i] = c;
		fold_line[j] = c;
		ncol = 0;
		++i;
		++j;
	}
	line[i] = '\0';
	fold_line[j] = '\0';

	return i;
}
