



#include <stdio.h>
#define MAXLINE		50 /*maximum input line size*/

int getlines(char line[], int maxline);
int rem_blank(char line[], char mod_line[]);

//Removes trails blanks and tabs, and blank lines
int main()
{
	int len, mlen; //current length
	int max; //maximum line length seen so far
	char line[MAXLINE]; //current input line
	char mod_line[MAXLINE]; //modify line

	max = 0;
	while ((len = getlines(line, MAXLINE)) > 0)
	{
		mlen = rem_blank(line,mod_line);
		printf("%s",mod_line);
		printf("len %d, mlen %d\n", len, mlen);
	}
	return 0;
}

/* getlines: rea line into s, return length */
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
	return i;
}

/* rem_blank: removes trailing blanks */
int rem_blank(char line[], char mod_line[]) 
{
	int i, j, t, nl; 
	
	i = j = 0;
	nl = '\0';
	while ((mod_line[i] = line[i]) != '\0'){
		if(mod_line[i] != ' ' && mod_line[i] != '\t'){
			if(mod_line[i] == '\n')
				nl = '\n';
			else j = i;
		}
		++i;
	}
	if(j == 0) //Remove blank lines.
		mod_line[j]='\0';
	else if (j > 0){
		++j;
		mod_line[j] = nl;
		if(nl == '\n'){
			++j;
			mod_line[j]='\0';
		}
	}
	return j;
}
