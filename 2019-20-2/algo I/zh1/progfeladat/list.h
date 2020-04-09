// Algo ZH1 
// Feladat: Két L1 lista metszete, az első listába képezve.
// Készítette: Magyar Tamás
// Dátum: 2020.04.09.
// Fordító: gcc 7.2.0 Target: x86_64-w64-mingw32

#ifndef LIST_GUARD
#define LIST_GUARD

#define INP_LENGTH 256

typedef struct E1 
{
    int key;
    struct E1* next;
} E1;

//List Methods
extern E1* new(int key);
extern void delete(E1* p);
extern E1* createHead();
extern void follow(E1* p, E1* q);
extern E1* out_next(E1* p);
extern void interselect(E1* L, E1* M);
extern int eqv(E1* L, E1* M);

//List IO
extern void printList(E1* L);
extern int readListsFromFile(char* src, E1** dest, int* length);
extern E1* parse(char* line);

#endif