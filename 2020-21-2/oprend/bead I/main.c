#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <sys/types.h>
#include <sys/stat.h>

#define LINE 256
#define MAX 128
#define FILENAME "data"

#define CLOSE "close"
#define LIST "list"
#define ADD "add"
#define REMOVE "remove"
#define UPDATE "update"


void clear(char data[MAX][LINE])
{
    int i,j;
    for(i = 0; i < MAX; i++)
        for(j = 0; j < LINE; j++)
            data[i][j] = '\0';
}

int dread(char data[MAX][LINE])
{
    FILE* file = fopen(FILENAME, "r"); 
    if (file<0){ perror("Error at opening the file\n"); return 0; }

    int c = 0;
    while (fgets(data[c++], sizeof(char) * LINE, file));

    fclose(file);

    return c-1;
}

int dwrite(char data[MAX][LINE], int len)
{
    FILE* file = fopen(FILENAME, "w"); 
    if (file<0){ perror("Error at opening the file\n"); return 0; }

    int i = 0;
    while(i<len)
        fprintf(file, "%s", data[i++]);

    fclose(file);

    return i;
}


void list(char data[MAX][LINE], int len)
{
    int i;
    for(i = 0; i < len; i++)
        printf("|%i| - %s", i , data[i]);
}

void add(char data[MAX][LINE], int* len, char* fname, char* lname, char* year, char* phone, char* extra)
{
    sprintf(data[(*len)++], "%s %s, %s, %s, %s\n", fname, lname, year, phone, extra);
}

void update(char data[MAX][LINE], int index, char* fname, char* lname, char* year, char* phone, char* extra)
{
    sprintf(data[index], "%s %s, %s, %s, %s\n", fname, lname, year, phone, extra);
}

void dremove(char data[MAX][LINE], int* len, int index)
{
    if(index < 0 || index >= *len) return;

    if(*len-1 == index) (*len)--;
    else sprintf(data[index], "%s", data[((*len)--)-1]);
}


void loop(char data[MAX][LINE], int* len)
{
    printf("Enter your next command:\n[close - list - add <rec> - remove <id> - update <id> <rec>]\n[<rec> = <fname> <lname> <year> <phone> <extra(Y/N)>]\n");

    char cmd[LINE] = "";
    char tmp[5][LINE/5];
    int index;
    while(strcmp(cmd, CLOSE))
    {
        printf("-> ");
        scanf("%s", cmd);

        if(!strcmp(cmd, LIST))
        {
            list(data, *len);
        }
        else if(!strcmp(cmd, ADD)) 
        {
            scanf("%s %s %s %s %s", tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
            add(data, len, tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
        }
        else if(!strcmp(cmd, REMOVE))
        {
            scanf("%i", &index);
            dremove(data, len, index);
        }
        else if(!strcmp(cmd, UPDATE))
        {
            scanf("%i", &index);
            scanf("%s %s %s %s %s", tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
            update(data, index, tmp[0], tmp[1], tmp[2], tmp[3], tmp[4]);
        }
    }
}

int main()
{
    printf("|Vakcin-acio| recorder started\n");

    char data[MAX][LINE];
    clear(data);

    int lr = dread(data);
    printf("Number of records read from datafile: %i\n", lr);

    loop(data, lr);

    int lw = dwrite(data, lr);
    printf("%i records saved to the datafile\n", lw);

    return 0;    
}