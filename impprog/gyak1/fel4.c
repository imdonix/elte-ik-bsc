

#include <stdio.h>


int main()
{
    float a, b;
    printf("Írjon be egy számot: ");
    scanf("%f", &a);
    printf("Írjon be egy számot: ");
    scanf("%f", &b);
    printf("Írjon be egy műveleti jelet: ");
    char ch;
    fflush(stdin); // törli a billentyűzet átmeneti bufferét
    scanf(" %c", &ch);
    if (ch == '+')
    {
        printf("összegük: %f\n", a + b);
    }
    else if (ch == '-')
    {
        printf("különbségük: %f\n", a - b);
    }
    else if (ch == '*')
    {
        printf("szorzatuk: %f\n", a * b);
    }
    else
    {
        if (b == 0)
        {
            printf("Nullával nem lehet osztani\n");
        }
        else
        {
            printf("A hányadosuk: %f\n", a / b);
        }
    }

    return 0;
}

