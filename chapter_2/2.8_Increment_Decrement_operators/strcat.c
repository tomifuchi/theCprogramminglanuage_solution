




#include <stdio.h>

void string_cat(char s[], char t[]);
int main()
{
	char s[20] = "line1";
	char t[20] = "line2";
	string_cat(s,t);
	printf("%s\n",s);
	return 0;
}

void string_cat(char s[], char t[]){
	int i, j;

	i = j = 0;

	//Traversing the s string to the end.
	while(s[i] != '\0')
		++i;
	//Concatnating t ino s
	while((s[i++] = t[j++]) != '\0')
		;
}
