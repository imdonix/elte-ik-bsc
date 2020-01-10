

#include <stdio.h>


int main()
{
    const int i = 27;
    // típuseltérés: int-re mutató pointerrel const int változóra mutatunk
    // C-ben lefordul, az i változó értéke megváltozik (C++-ban nem fordul)
    int* ptr = &i;
    *ptr = 80;
    printf("%i\n", i);
}

