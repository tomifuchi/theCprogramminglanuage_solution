#include <stdio.h>

/* print Fahrenheit-Celcius talbe
 * for fahr = 0, 20,..., 300; floating-point version*/
/*Modify this program to print a heading
 *above the table*/

int main(int argc, char *argv[])
{
	float fahr, celcius;
	int lower, upper, step;

	lower = 0;	//Lower limit 
	upper = 300; 	//Upper limit
	step = 20;	//Step size

	fahr = lower;

	printf("Fahr Cel\n");
	while (fahr <= upper)
	{
		celcius = 
		(5.0/9.0) * (fahr-32.0);

		printf("%3.0f %6.1f\n", fahr, celcius);
		fahr = fahr + step;
	}

	return 0;
}
