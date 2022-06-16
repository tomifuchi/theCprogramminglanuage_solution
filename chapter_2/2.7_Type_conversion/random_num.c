



#include <stdio.h>

int randomi(void);
void seed_random(unsigned int seed);

int main(){

	while(1)
	  printf("%d\n", randomi());
	return 0;
}

unsigned long int next = 1;

/* rand: return pseudo-integer from 0 to 32767 */
int randomi(void)
{
	next = next * 1103515245 + 12345;
	return (unsigned int) (next/65536) % 32768;
}

void seed_random(unsigned int seed){
	next = seed;
}
