





#include <stdio.h>
#include <stdlib.h>

int main(){
	//Example of conditional printf
	char item1[10] = "apple";
	int n_item1 = 1;

	printf("You have %d Item%s.\n", n_item1, (n_item1 > 1) ? "s":"");

	int num[100], i;
	for(i = 0;i < 100;num[i++]=rand()%10)
		;
	//Printf using conditional expression
	for(i = 0;i < 100;++i){
		printf("%6d%c", num[i], (i%10==9||i==99) ? '\n':' ');
	}

	return 0;
}
