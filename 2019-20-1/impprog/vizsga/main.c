#include <stdio.h>
#include <stdlib.h>
#include "func.h"

#define LENGTH 10

int main()
{
	int arr1[LENGTH] = {4,16,88,3,6,7,10,90,5,12};
	int arr2[12] = {6,7,11,8,1,100,300,32,5,12,99,98};
	
	set s = {LENGTH, arr1};
	set s2 = {12, arr2};

	int *dest;
	int count = 0;
	
	dest = metszet(s, s2, &count);
	
	for(int i=0;i<count;printf("%i\n", dest[i++]));
	
	free(dest);
	return 0;
}
