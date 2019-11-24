

#include <string.h> // strlen() miatt


void reverse(char str[])
{
    for (int i = 0, j = strlen(str) - 1; i < j; ++i, --j)
    {
        // két változó értékének felcserélése egy harmadik, segédváltozó bevezetésével
        // az a = b; b = a; értékadás helytelen, mert a értéke elvész az első értékadásban
        // ezért először a értékét kimentjük egy külön helyre
        // c = a; a = b; b = c; már helyes
        // itt is ez történik, csak char típusú adatokkal
        char c;
        c = str[i];
        str[i] = str[j];
        str[j] = c;
    }
}


void squeeze(char str[], char ch)
{
    int i = 0;
    int j = 0;
    while (str[i] != '\0')
    {
        // a ch karaktereket nem másoljuk
        // a j változó tartja számon az "eredmény" utolsó karakterének indexét
        // az i-vel pedig az str[]-en megyünk végig
        // a ciklus az str[] j-edik elemébe másolja str[] i-edik elemét
        // az alapötlet az, hogy ha ch-t találunk, akkor j-t nem, de i-t mindig növeljük
        if (str[i] != ch)
        {
            str[j++] = str[i];
            // ez a ciklusmag ugyanaz mint:
            //str[j] = str[i];
            //j++;
            // a j++ posfix növelés a növelés előtti értékkel tér vissza (azaz j-vel),
            // ezért bevihető a tömbindexelésbe
            // tömörebb, rövidebb megoldás
        }
        i++;
    }
    // a sztring végét a '\0'-al kell zárni
    str[j] = '\0';
}
