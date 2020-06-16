#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_TICKETS 200
#define SEATS 48

int readFile(int tickets[MAX_TICKETS][3])
{
    FILE* src; src = fopen("eladott.txt", "r");
    int i,j;
    char inp[256];
    i = 0;
    while (fgets(inp, sizeof(inp), src) != NULL)
    {
        for (char* ptr = strtok(inp, " "), j = 0; ptr != NULL; ptr = strtok(NULL, " "))
            tickets[i][j++] = atoi(ptr);
        i++;
    }
    fclose(src);
    return i;
}

int roundToFive(int price)
{
    int r = price % 5;
    return (r > 2) ? price - r : price + r; 
}

int distance(int ticket[3])
{
    return ticket[2]-ticket[1];
}

void printFullDistance(int tickets[MAX_TICKETS][3], int length)
{
    int dis = tickets[0][1];
    int i = 1;
    for(;i<length;i++)
        if(distance(tickets[i]) == dis)
            printf("%i ", i+1);
    printf("\n");
}

int allIncome(int tickets[MAX_TICKETS][3], int length)
{
    int val = tickets[0][2];

    int s = 0;
    int i = 1;
    for(;i<length;i++)
        s+=roundToFive((distance(tickets[i])/10)*val);
    return s;
}

int countLastStation(int tickets[MAX_TICKETS][3], int length)
{
    int end = tickets[0][2];
    int max = tickets[1][2];
    int i = 2;
    for(;i<length;i++)
        if(tickets[i][2] != end && tickets[i][2] > max)
            max = tickets[i][2];
    
    int c = 0;
    i = 1;
    for(;i<length;i++)
        if(tickets[i][1] == max || tickets[i][2] == max)
            c++;
    return c;
}

int countStations(int tickets[MAX_TICKETS][3], int length)
{
    int heap[tickets[0][1]];

    int i=0;
    for(;i<tickets[0][1];i++)
        heap[i]=0;

    i=1;
    for(;i<length;i++)
    {
        heap[tickets[i][1]]++;
        heap[tickets[i][2]]++;
    }

    i=0;
    int c = 0;
    for(;i<tickets[0][1];i++)
        if(heap[i])
            c++;
    return c;
}

void getPassenger(int tickets[MAX_TICKETS][3], int length, int moment, int seats[SEATS])
{    
    int i = 0;
    for(;i<SEATS;i++)
        seats[i]=0;
    
    i=1;
    for(;i<length;i++)
        if(tickets[i][1] <= moment && tickets[i][2] > moment)
            seats[tickets[i][0]-1] = i;
}

void writePassengerToFile(int passenger[])
{
    FILE* src; src = fopen("kihol.txt", "w");
    int i;
    i = 0;
    for(;i<SEATS;i++)
        if(passenger[i])
            fprintf(src, "%i. ules: %i. utas\n", i+1, passenger[i]);
        else
            fprintf(src, "%i. ules: ures\n", i+1);
    fclose(src);    
}


int main()
{
    int tickets[MAX_TICKETS][3];
    int length;

    printf("1. feladat: Beolvasva\n");
    length = readFile(tickets);

    printf("2. feladat:\n");
    printf("Ules sorszama: %i, beutazott tavolsag:%i\n", tickets[length-1][0], distance(tickets[length-1]));

    printf("3. feladat:\n");
    printFullDistance(tickets, length);

    printf("4. feladat:\n");
    printf("Teljes bevetel: %i\n", allIncome(tickets, length));


    printf("5. feladat:\n");
    printf("Vegallomas elotti alomason le-fel szallasok: %i\n", countLastStation(tickets, length));

    printf("6. feladat:\n");
    printf("Oszzes allomas szama: %i\n", countStations(tickets, length));
    
    printf("7. feladat:\n");
    int point;
    int seats[SEATS];
    scanf("%d", &point);
    getPassenger(tickets, length, point,seats);
    writePassengerToFile(seats);

    return 0;
}
