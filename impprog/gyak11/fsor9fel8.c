

#include <stdio.h>


/*
int arr[3][5];
3x5-ös méretû kétdimenziós tömb
szokásos indexeléssel lehet elérni az elemeit: arr[i][j]

konvertálódása pointer-ré: szintén elsõ elemre mutató pointer-ré konvertálódik
de arr valójában egy egydimenziós tömb, aminek minden eleme int-ek 5 elemû tömbje
tehát pl paraméterként átadva arr egy 5-elemû int-ek tömbjére mutató pointer-ré konvertálódik
(azaz int (*)[5] típusú

az arr[3][5] ugyanazt jelenti, mint a *(*(arr + 3) + 5)

paraméterként deklarálva az elsõ dimenziós kivételével minden dimenzió méretét rögzíteni kell
*/



// többdimenziós tömb típus használata helyett vegyük át a tömb elsõ
// elemének címét, és a tömb méreteit, majd számoljuk ki a megfelelõ indexet
// elõnye: tetszõleges méretû tömböt el tudunk érni a függvényen belül
void print(int* arr, int row, int col)
{
    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            printf("%i ", arr[i * col + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void foo(int* arr, int row, int col, double res[])
{
    for (int i = 0; i < row; ++i)
    {
        double avg = 0;
        for (int j = 0; j < col; ++j)
        {
            avg += arr[i * col + j];
        }
        avg /= col;
        res[i] = avg;
        //printf("%lf\n", avg);
    }
}


int main()
{
    int arr[5] = {45, -234, 52, 235, 1};
    int arr_d2[2][3] = {
        {1, 2, 3},
        {-1, 0, 1}
    };

    int arr_d3[2][4] = {
        {1, 3, 5, 7},
        {4, 5, 6, 8}
    };

    double a[2];

    //printf("%i\n", arr_d2[1][2]);
    foo(&arr_d2[0][0], 2, 3, a);
    printf("%lf %lf\n", a[0], a[1]);
    foo(&arr_d3[0][0], 2, 4, a);
    printf("%lf %lf\n", a[0], a[1]);
}

