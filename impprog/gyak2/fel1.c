

#include <stdio.h>


int main()
{
    // 5 elemû tömb, 5 db float adatot tárolhatunk a tömbben
    // a tömb elemeire indexeléssel [] hivatkozhatunk
    // valid indexek: 0, 1, ..., méret-1
    float a[5];
    for (int idx = 0; idx < 5; idx++) // for (int idx = 0; idx <= 4; idx++)
    {
        printf("Írjon be egy számot: ");
        scanf("%f", &a[idx]);
    }
    printf("Átlag = %f\n", (a[0] + a[1] + a[2] + a[3] + a[4]) / 5.0);
    return 0;
}
