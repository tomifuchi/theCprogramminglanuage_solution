



#include <stdio.h>
#define MAXLINE		1000/*maximum input line size*/
#define IN 2
#define SEMI 1
#define OUT 0

int getlines(char s[], int lim);
void htoi(char c);
int lower(int c);

int num = 0;
int hexa = OUT;

//Convert any hexadeciaml in a line into decimal.
int main()
{
	int len; //current length
	char line[MAXLINE]; //current input line

	while ((len = getlines(line, MAXLINE)) > 0)
		printf("In decimal: %d\n", num);
	return 0;
}

/* getlines: read line into s, return length */
int getlines(char s[], int lim) {
	int c,i;

	for (i = 0; i < lim - 1 && (c=getchar())!=EOF && c!='\n'; ++i){
		s[i] = c;
		htoi(c);
	}
	if (c == '\n')
	{
		s[i] = c;
		htoi(c);
		++i;
	}
	return i;
}

//COnverting positive hexadecimal only
void htoi(char c){
	if(c == '0' && hexa == OUT)
		hexa = SEMI;
	else if ((c == 'x' || c == 'X') && hexa == SEMI){
		num = 0;
		hexa = IN;
	}
	else if (hexa == IN){
		if ((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')){
			c = lower(c);
			num = 16 * num + (c - 'a') + 10;
		}
		else if (c >= '0' && c <= '9')
			num = 16 * num + (c - '0');
		else 
			hexa = OUT;
		
	}
	else
	hexa = OUT;
}

int lower(int c){
	if (c >= 'A' && c <= 'F')
		return c + 'a' - 'A';
	else
		return c;
}
