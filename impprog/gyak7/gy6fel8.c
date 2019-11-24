

#include <stdio.h>


// tömbös megoldás
int length(char str[]) // a fv fejlécében tömb van
{
    int idx = 0;
    for (; str[idx] != '\0'; ++idx); // tömbindexelés
    return idx;
}


// pointer-es megoldás
int length2(char* str) // a fv fejlécében pointer van
{
    int idx = 0;
    for (; *(str + idx) != '\0'; ++idx); // pointer aritmetika
    return idx;
}


int main()
{
    char str[] = "vmi";
    char* ptr = "vmi2";
    printf("%i\n", length2(str)); // str egy tömb, első elemre mutató pointer-ré (char*) konvertálódik
    printf("%i\n", length2(ptr));
}

// a fordító a length() esetében ugyanazt teszi, mint amit a length2()-ben csináltunk
// a paraméterlistán a char str[] paraméterdeklarációt kicseréli char* str -re
// a függvényen belüli tömbhivatkozásokat, pl str[idx] -t kicseréli *(str + idx) -re
// (közönséges search-and-replace fordítási időben)
