




#include <stdio.h>
#define MAXLINE		20 /*maximum input line size*/

int getlines(char line[], int maxline);
void reverse(char t[], char s[], int len);

int main()
{
	int len; //current length
	char line[MAXLINE]; //current input line
	char reversed_line[MAXLINE];

	while ((len = getlines(line, MAXLINE)) > 0){
		reverse(reversed_line, line, len);
		printf("%s", reversed_line);
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

//Reverse: the name said it all, reverse string s, stored in t
//Counted \n as a character also, so let's say
//abc\n
//and \nabc is the same so
void reverse(char t[], char s[], int len)
{
	int i = 0;
	t[len] = s[len];
	while(i < len){
	  t[i] = s[len - i - 1];
	  ++i;
	}
	//Reverse with abc\n and cba\n
	//int nl = 0;
	//if (s[len - 1] == '\n')
	//	nl = 1;
	//t[len] = s[len];
	//t[len - nl] = s[len - nl];


	//while(i < len - nl){
	//  t[i] = s[len - i - 1 - nl];
	//  ++i;
	//}
}
