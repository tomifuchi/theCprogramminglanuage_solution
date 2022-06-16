#include <stdio.h>

/* print Fahrenheit-Celcius talbe
 * for fahr = 0, 20,..., 300; floating-point version*/


double fahr_cel(double fahr)
{
	double cel;
	cel = (fahr - 32.0)*(5.0/9.0);
	return cel;
}

double cel_fahr(double cel)
{
	double fahr;
	fahr =  cel * (9.0/5.0) + 32;
	return fahr;
}


main()
{
	double lower, upper, step;

	lower = 0;	//Lower limit 
	upper = 300; 	//Upper limit
	step = 20;	//Step size

	//cel to fahr
	printf("Cel Fahr\n");
	for (lower = 0; lower < upper; lower+=step)
		printf("%.2f %.2f\n", lower, cel_fahr(lower)); 
	//fahr to cel
	printf("Fahr Cel\n");
	for (lower = 0; lower < upper; lower+=step)
		printf("%.2f %.2f\n", lower, fahr_cel(lower)); 

}
