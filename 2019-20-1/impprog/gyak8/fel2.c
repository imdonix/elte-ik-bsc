

#include <stdio.h>
#include <stdlib.h>


int main()
{
    int num;
    printf("Db = ");
    scanf("%i", &num);

    double* ptr = (double*)malloc(num * sizeof(double));
    for (int idx = 0; idx < num; ++idx)
    {
        printf("Enter double: ");
        scanf("%lf", ptr + idx);
    }

    double sum = 0;
    for (int idx = 0; idx < num; ++idx)
    {
        sum += *(ptr + idx);
    }
    free(ptr);

    printf("Avg = %lf\n", sum / num);
}

