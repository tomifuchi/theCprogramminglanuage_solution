#include <stdio.h>


/*1-6: Verify that the expression getchar() != EOF is
 *either 0 or 1*/

main()
{
	int c,i;

	//If i = 0 loop ends
	while (i = ((c = getchar()) != EOF))
	{
		putchar(c);
		printf("\ni = %i\n",i);
	}
	printf("i = %i\n",i);
}
