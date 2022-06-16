





#include <stdio.h>

//Delete c from string s
int match_any(char s[], char t[]);

int main(){
	char line[200] = "This string has c c c c cc cc c c cccc c ccccccc in it\n";
	printf("First occurence is: %d\n",match_any(line,"zoe"));
	return 0;
}

//Delete c from string s
int match_any(char s[], char t[]){
	int i, w;

	for (w = 0;t[w] != '\0';++w){
	for(i = 0;s[i] != '\0';++i)
		if(s[i] == t[w])
			return i;
	}
	return -1;
}
