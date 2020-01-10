

#include <stdio.h>


int foo(int arr[], int size)
{
    // a paraméterek (arr, size) valójában lokális változók,
    // szerepelhetnek az értékadás bal oldalán
    // a fv azonban az argumentumok másolatával dolgozik, így a
    // fv-en belül értékadások nincsenek hatással a fvhíváskor
    // átadott változókra
    // az elmondottak nem vonatkoznak tömbökre (ld. késõbb pointer-ek)
    arr[0] = 1;
    size = 11;
    return 0; // ld. késõbb, void fv
}


int double_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = 2 * arr[i];
    }
    return 0; // ld. késõbb, void fv
}


int main()
{
    int x[4] = {-1, -2, -3, -4};
    int size = 4;
    printf("size = %i\n", size);
    printf("x[0] = %i\n", x[0]);
    foo(x, size);
    printf("size = %i\n", size);
    printf("x[0] = %i\n", x[0]);
}

