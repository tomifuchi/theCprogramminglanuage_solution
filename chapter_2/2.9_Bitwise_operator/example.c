



#include <stdio.h>

int main(){
	//Exmaple 1
	//The & operator.
	//Operand is int op int
	//   0000 1000
	// & 0000 0100 
	// -----------
	//   0000 0000
	// In decimal it's 0
	printf("%d",8&4);

	//Example 2
	//If operand is int op octal
	//   0100 1000 in dec is 72
	//  &0001 1000 in dec is 30
	//  ----------
	//   0000 1000
	printf("%d",72&030);

	//Example 3
	//Or hexa
	//If operand is int op hexa
	//   0010 0011 in dec is 35
	//  &0001 0001 in dec is 21
	//  ----------
	//   0000 0001
	printf("%d\n",35&0x11);

	//The | operator is similar to the & operator
	//but and
	//   0000 1000
	// ^ 0000 0010
	//   ---------
	//   0000 1010
	printf("%d",8|2);

	//Left shifting
	// 0000 0010
	// Shifed to the left by 2
	// 0000 1000 which turns 2 into 8
	printf("%d\n",2 << 2);

	//Right shifting
	// 1000 1001 in dec is 137
	// Shifted to the right by 3 then
	// 0001 0001 in dec is 17
	// But....It's important to understand bit shifting a
	// negative signed number is implementation behavior
	// by shifting bits, if not careful sometimes causes
	// undefined behaviors.
	printf("%d\n",137 >> 3);

	//Unary operator or ~
	//Turns 0s into 1s and 1s into 0s
	//Let
	//  0111 7
	//Then its
	//  1000 8
	char b = 0b0111;
	printf("%d",~b);
	return 0;
}
