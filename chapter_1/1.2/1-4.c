#include <stdio.h>

/* print Celcius-Fahrenheittalbe
 * for cel = 0, 10,..., 300; floating-point version*/

int main(int argc, char *argv[])
{
	float fahr, celcius;
	int lower, upper, step;

	lower = 0;	//Lower limit 
	upper = 300; 	//Upper limit
	step = 10;	//Step size

	celcius = lower;

	printf("Cel  Fahr\n");
	while (celcius <= upper){
		fahr = 
		(celcius/(5.0/9.0)) + 32.0;

		printf("%3.0f %6.1f\n", celcius, fahr);
		celcius = celcius + step;
	}

	return 0;
}
