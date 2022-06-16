





#include <stdio.h>
int count_bit(unsigned x);
int count_bit_v2(unsigned x);

int main(){
	char i = 56;
	printf("%d\n",count_bit_v2(i));
	return 0;
}

int count_bit(unsigned x){
	int b;

	// Okay this is what's it's doing
	// shifting right them use the 
	// & operator to get 1, if it's still 1
	// increment b. Say at 7 x is 
	// 0111
	// 0001 Check to 1
	// 0001
	// Shift bits until it's 0 or zerobits.
	for(b = 0;x != 0;x >>= 1)
		if(x & 01)
			b++;
	return b;
}
int count_bit_v2(unsigned x){
	int b;
	
	//Note using this x &= (x - 1) Essentially
	//shaving 1 bit to the right sice say 8 
	//Remember x &= (x - 1)
	//is x = x & (x - 1)
	for(b = 0;x != 0;x &= (x - 1), ++b)
		;
	return b;
}
