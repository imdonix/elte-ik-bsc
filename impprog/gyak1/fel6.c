

#include <stdio.h>


int main()
{
    int n;
    printf("Írja be n-et: ");
    scanf("%i", &n);

    for (int idx = 1; idx <= n; idx = idx + 1)
    {
        for (int idx2 = 1; idx2 <= idx; idx2 = idx2 + 1)
        {
            printf("%i", idx);
        }
        printf("\n");
    }

    return 0;
}
