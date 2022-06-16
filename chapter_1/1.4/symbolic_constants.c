#include <stdio.h>

#define	LOWER	0	/* Lower limit of table*/
#define	UPPER	300	/* Upper limit of table*/
#define	STEP	20	/* Step size*/
#define STR "random string" /* Random constant string */

/* print Celcius-Fahrenheittalbe
 * for cel = 0, 10,..., 300; floating-point version
 * One different is this include a symbolic constants
 * */


int main(int argc, char *argv[])
{
	int fahr;

	printf("%s\n",STR);

	for(fahr=LOWER; fahr <= UPPER; fahr+=STEP)
		printf("%3d %6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	return 0;
}
