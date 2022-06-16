



#include <stdio.h>
//Specifically in this folder
// /usr/include/sys/limits.h
#include <sys/limits.h>

long power(int base,int n);

int main(){

	//Data types and their sizes
	// char short int long
	
	//According to sys/limits.h
	//Char 
	printf("Taken from sys/limits.h\n");
	printf("Number of bit in a char: %d\n", CHAR_BIT);
	printf("======Referenced======\n");
	printf("Signed char:\n");
	printf("Max: %d\n", SCHAR_MAX);	/* max value for a signed char */
	printf("Min; %d\n", SCHAR_MIN);	/* min value for a signed char */
	printf("Unsigned char:\n");
	printf("Min; 0\n");	/* min value for a signed char */
	printf("Max: %d\n", UCHAR_MAX);	/* max value for an unsigned char */
	printf("======Calculated======\n");
	printf("Signed char:\n");
	printf("Max: %d\n", (power(2,CHAR_BIT) - 1)/2);	/* max value for a signed char */
	printf("Min; %d\n", (-1)*(power(2,CHAR_BIT) - 1)/2 - 1);/* min value for a signed char */
	printf("Unsigned char:\n");
	printf("Min; 0\n");	/* min value for a signed char */
	printf("Max: %d\n", power(2,CHAR_BIT) - 1);	/* max value for an unsigned char */

	//Bit of short is log(65536)/log(2) = 16
	int SHRT_BIT = 16;
	printf("Number of bit in a short: %d\n", SHRT_BIT);
	printf("======Referenced======\n");
	printf("Signed short:\n");
	printf("Max: %d\n", SHRT_MAX);	/* max value for a signed short */
	printf("Min; %d\n", SHRT_MIN);	/* min value for a signed short */
	printf("Unsigned short:\n");
	printf("Min; 0\n");	/* min value for a signed short */
	printf("Max: %d\n", USHRT_MAX);	/* max value for an unsigned short */
	printf("======Calculated======\n");
	printf("Signed short:\n");
	printf("Max: %d\n", (power(2,SHRT_BIT) - 1)/2);	/* max value for a signed short */
	printf("Min; %d\n", (-1)*(power(2,SHRT_BIT) - 1)/2 - 1);/* min value for a signed short */
	printf("Unsigned short:\n");
	printf("Min; 0\n");	/* min value for a signed short */
	printf("Max: %d\n", power(2,SHRT_BIT) - 1);	/* max value for an unsigned short */

	//Bit for int is log(4294967296)/log(2) = 32
	int INT_BIT = 32;
	printf("Number of bit in a int: %d\n", INT_BIT);
	printf("======Referenced======\n");
	printf("Signed int:\n");
	printf("Max: %d\n", INT_MAX);	/* max value for a signed int */
	printf("Min; %d\n", INT_MIN);	/* min value for a signed int */
	printf("Unsigned int:\n");
	printf("Min; 0\n");	/* min value for a signed int */
	printf("Max: %llu\n", UINT_MAX);	/* max value for an unsigned int */
	printf("======Calculated======\n");
	printf("Signed int:\n");
	printf("Max: %d\n", (power(2,INT_BIT) - 1)/2);	/* max value for a signed int */
	printf("Min; %d\n", (-1)*(power(2,INT_BIT) - 1)/2 - 1);/* min value for a signed int */
	printf("Unsigned int:\n");
	printf("Min; 0\n");	/* min value for a signed int */
	printf("Max: %lld\n", power(2,INT_BIT) - 1);	/* max value for an unsigned int */

	////Bit for long is log(18446744073709551615)/log(2) = 64
	printf("Number of bit in a long: %d\n", LONG_BIT);
	printf("======Referenced======\n");
	printf("Signed long:\n");
	printf("Max: %ld\n", LONG_MAX);	/* max value for a signed long */
	printf("Min; %ld\n", LONG_MIN);	/* min value for a signed long */
	printf("Unsigned long:\n");
	printf("Min; 0\n");	/* min value for a signed long */
	printf("Max: %lu\n", ULONG_MAX);	/* max value for an unsigned long */
	printf("======Calculated======\n");
	printf("Signed long:\n");
	printf("Max: %ld\n", (power(2,LONG_BIT) - 1)/2);	/* max value for a signed long */
	printf("Min; %ld\n", (-1)*(power(2,LONG_BIT) - 1)/2 - 1);/* min value for a signed long */
	printf("Unsigned long:\n");
	printf("Min; 0\n");	/* min value for a signed long */
	printf("Max: %lu\n", power(2,LONG_BIT) - 1);	/* max value for an unsigned long */


	return 0;
}

long power(int base,int n){
	long p = 1;

	int i;
	for(i = 0; i < n; ++i, p = p * base)
		;
	return p;
}
