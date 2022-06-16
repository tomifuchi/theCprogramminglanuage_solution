#include <stdio.h>

/* print Celcius-Fahrenheittalbe
 * for cel = 0, 10,..., 300; floating-point version*/

int main(int argc, char *argv[]){
	float celcius;

	printf("Cel   Fahr\n");
	for (celcius = 20;celcius >= -18; celcius = celcius - .1)
		printf("%6.1f %3.0f\n", celcius, (celcius/(5.0/9.0)) + 32.0);

	return 0;
}
