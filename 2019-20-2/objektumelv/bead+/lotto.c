#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define WEEKS 52
#define NUMS 5
#define INP_LENGTH 256
#define MAXIMUM 90


void readFile(char nums[WEEKS][NUMS])
{
    FILE* src; src = fopen("lottosz.dat", "r");
    char line[256];
    int i,j;
    i = 0;
    while (fgets(line, sizeof(line), src) != NULL)
    {
        for (char* ptr = strtok(line, " "), j = 0; ptr != NULL; ptr = strtok(NULL, " "), j++)
            nums[i][j] = atoi(ptr);
        i++;
    }
    fclose(src);
}

void writeFile(char nums[WEEKS][NUMS])
{
    FILE* src; src = fopen("lotto52ki.txt", "w");
    for(char i=0;i<WEEKS;i++)
    {
        for(char j=0;j<NUMS;j++)
            fprintf(src, "%i ", nums[i][j]);
        fprintf(src, "\n");
    }   
    fclose(src);
}

void print(char week[])
{
    for(char i=0;i<NUMS;i++)
        printf("%i ", week[i]);
    printf("\n");
}

void getnums(char dest[])
{
    for(char i=0;i<NUMS;i++)
        scanf("%i", dest + i);
}

void sort(char arr[])
{
    for(char i=0;i<NUMS;i++)
    {
        char min = i;
        for(char j=i+1;j<NUMS;j++)
            if(arr[min] > arr[j])
                min = j;
        
        char temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void heapSet(char heap[], char inp[])
{
    for(char i=0;i<NUMS;i++)
        heap[inp[i]-1]++;
}

char hasNull(char heap[])
{
    char l = 0;
    for(char i=0;i<MAXIMUM;i++)
        l = l || (!heap[i]); 
    return l;
}

int countNEven(char heap[])
{
    int c = 0;
    for(char i=0;i<MAXIMUM;i+=2)
        c+= heap[i];
    return c;
}

void copy(char src[], char dest[])
{
    for(char i=0;i<NUMS;i++)
        dest[i] = src[i];
}

void writeHeap(char heap[])
{
    for(char i=1;i<=MAXIMUM;i++)
    {
        printf("%i ", heap[i-1]);
        if(!(i%15)) printf("\n", heap[i]);
    }
}

void findPrimeNumbers(char heap[])
{
    for(char i=2;i<=MAXIMUM;i++)
    {
        char l=1;
        for(char j=2;j<i;j++)
            l = l && (i%j);
        
        if(l && !heap[i-1])
            printf("%i ", i);
    }
}

int main()
{    
    char inp[NUMS];
    char heap[MAXIMUM];
    char nums[WEEKS][NUMS];
    int req;

    readFile(nums);


    printf("Elso feladat: (Irj be 5 szamot)\n");
    getnums(inp);


    printf("Masodik feladat:\n");
    sort(inp);
    print(inp);


    printf("Harmadik feladat: (Irj be 1-51 kozott egy szamot)\n");
    scanf("%i", &req); 


    printf("Negyedik feladat: \n");
    print(nums[req-1]);


    //
    for(char i=0;i<MAXIMUM;i++) heap[i]=0;
    for(char i=0;i<WEEKS-1;i++)  heapSet(heap, nums[i]);
    //


    printf("Otodik feladat: \n");
    printf("Volt olyan amit nem huztak ki?: %s\n", hasNull(heap) ? "Igen" : "Nem");


    printf("Hatodik feladat: \n");
    printf("Paratlan szamok osszesen: %i\n", countNEven(heap));


    printf("Hetedik feladat: \n");
    copy(inp, nums[WEEKS-1]);
    writeFile(nums);
    printf("A fajl sikeresen letrehozva es a beirt adatokkal\n");

    printf("Nyolcadik feladat: \n");
    heapSet(heap, inp);
    writeHeap(heap);

    printf("Kilencedik feladat: \nNem kihuzott primszamok: ");
    findPrimeNumbers(heap);

    return 0;
}