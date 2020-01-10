

#include <stdio.h>
#include <math.h>


/* saját függvény készítése

visszatérési_típus függvény_neve(paraméterlista)
{
    utasítások
}

*/


/*
1 2 3 4 5 6 7
i n n n n n i

1 2 3 4 5 6 7 8
i i n i n n n i

ha x|8 akkor y=x/8-ra is y|8
pl x=2, 2|8 ekkor 8/2=4 is 4|8
felesleges 4-re ellenõrizni
hol van a határ, amely szám után felesleges ellenõrizni?
azaz: melyik az a szám 1..8-ban, amire igaz, h 8/x = x
8/x = x
8 = x^2
sqrt(8) = x
*/


// is_prime() eldönti a paraméterként kapott számról
// h prímszám-e (elég esetlen megoldás, de mûködik, késõbb írunk egy jobbat)
// visszatérési érték: 0: nem prímszám, 1: prímszám
int is_prime(int num)
{
    if (num == 0 || num == 1)
    {
        return 0; // a fv viszaatérési értékét határozza meg
    }
    if (num == 2)
    {
        return 1;
    }

    // megválaszolatlan kérdés: miért kell sqrt(a)-nél + 1?
    // típuskonverzióknál visszatérünk erre a kérdésre
    for (int idx = 2; idx < sqrt(num) + 1; idx++)
    {
        if (num % idx == 0)
        {
            return 0;
        }
    }
    return 1;
}


int main()
{
    printf("%i\n", is_prime(22)); // 0
    printf("%i\n", is_prime(23)); // 1
    return 0;
}

