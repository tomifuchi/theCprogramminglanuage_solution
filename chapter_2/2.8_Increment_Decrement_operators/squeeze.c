





#include <stdio.h>

//Delete c from string s
void squeeze(char s[], int c);

int main(){
	char line[200] = "This string has c c c c cc cc c c cccc c ccccccc in it\n";
	squeeze(line, 'c');
	printf("Removeing c from the string: %s", line);
	return 0;
}

//Delete c from string s
void squeeze(char s[], int c){
	int i, j;

	for(i = 0,j = 0;s[i] != '\0';i++)
		if(s[i] != c)
			s[j++] = s[i];
	s[j] = '\0';
}
