#include <stdlib.h>
#include "func.h"

int* metszet(set s1, set s2, int* count)
{
	int* dest = malloc(sizeof(int) * (s1.count > s2.count ? s1.count : s2.count));
	for(int x=0;x<s1.count;++x)
		for(int y=0;y<s2.count;++y)
			if(s1.arr[x] == s2.arr[y])
				dest[(*count)++] = s1.arr[x]; 
	return dest;
}
