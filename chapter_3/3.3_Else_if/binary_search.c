




#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

#define NUMSIZE 2000000
#define ARGSIZE 1900000
int binary_search(int x, int v[], int n);
int main(){
	int num[NUMSIZE], i;
	for (i = 0; i < ARGSIZE;num[i++] = rand())
		;
	qsort(num, ARGSIZE, sizeof(int), cmpfunc);
	printf("%d is at %d\n",25,binary_search(25, num, ARGSIZE));
	return 0;
}

//Find element in a sorted array
//v[1] ... v[n-1] so
int binary_search(int x, int v[], int n){
	int low, high, mid;

	low = 0;
	high = n - 1;
	while (low <= high){
		mid = (low + high)/2;
		if(x < v[mid])
		  high = mid - 1;
		else if (x > v[mid])
		  low = mid + 1;
		else
		  return mid;
	}
	return -1;
}
