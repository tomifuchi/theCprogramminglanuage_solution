



#include <stdio.h>
int lowercase(char c);

int main(){
	printf("%c\n",lowercase('Z'));
	return 0;
}

int lowercase(char c){
	return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A':c;
}
