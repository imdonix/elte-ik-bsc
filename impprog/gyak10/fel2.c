

#include <stdio.h>
#include <stdlib.h>


typedef struct node
{
    int val;
    // önhivatkozó struktúra: önmagára mutató pointer
    struct node* next;
} node_t;


int main()
{
    node_t* head = malloc(sizeof(node_t));

    head->val = 17; // ugyanaz mint: (*head).val
    head->next = malloc(sizeof(node_t)); // láncolás létrehozása: next egy másik ilyen struct példányra mutat

    //(head->next)->val = 72;
    node_t* ptr = head->next;
    ptr->val = 72;

    printf("%i %i\n", head->val, (head->next)->val);

    // vigyázat, az történik amit írtunk: a head által mutatott struct másolódik le,
    // nem az egész láncolt lista
    // a másolat next pointer-e az eredeti a 2. alkalommal malloc()-olt struct-ra mutat
    // mert annak csak a pointer-e másolódott le
    node_t head_copied = *head;
}

