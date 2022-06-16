




#include <stdio.h>
unsigned getbits(unsigned x, int p, int n);

int main(){

	//Let's say 7 then by get 2-bit position 0 it's 0011 or 3
	//Right justified, 0 index on the right
	//Say 7 then its 0111
	//By using get bits its
	//Get 2 bits, starts at position 1 or this portion
	//  here to here
	//  v	     v
	//0111	  0111
	//So it should be 0011 or 3
	printf("%d\n", getbits(8,4,4));
	
	//For 87 its
	// 0101 0111
	// Get starts at 4, get 3 bits, or it should be 0101 or 5
	printf("%d", getbits(87,0,1));
	return 0;
}


/* Get n-bits from p position of x*/
unsigned getbits(unsigned x, int p, int n){
	return (x >> (p + 1 - n)) & ~(~0 << n);
}
