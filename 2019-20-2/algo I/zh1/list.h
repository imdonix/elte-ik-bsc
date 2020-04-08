#ifndef LIST_GUARD
#define LIST_GUARD

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
extern E1* parseLine(char* line);

#endif