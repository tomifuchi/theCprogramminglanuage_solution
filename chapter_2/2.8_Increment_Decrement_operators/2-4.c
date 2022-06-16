





#include <stdio.h>

//Delete c from string s
void squeeze(char s[], char t[]);

int main(){
	char line[200] = "This has c in it\n";
	squeeze(line, "th");
	printf("Removeing c from the string: %s", line);
	return 0;
}

//Delete c from string s
void squeeze(char s[],char t[]){

	int w;
	int i, j;
	for(w = 0;t[w] != '\0';++w){
		for(i = 0,j = 0;s[i] != '\0';i++)
			if(s[i] != t[w])
			  s[j++] = s[i];
	  s[j] = '\0';
	}
}
