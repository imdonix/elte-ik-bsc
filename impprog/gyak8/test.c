

#include <stdio.h>


int main()
{
    int i;
    int* pi = &i;
    unsigned long int u = 45;
    // point konstans pointer:
    // a pointer nem szerepelhet az értékadás bal oldalán
    unsigned long int* const point = &u;
}

