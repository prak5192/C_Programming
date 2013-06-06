#if 0
Link:
===========
Implement a double linked list using a single linked list. 
You have given only data and one pointer in struct node 
{ int data, struct node *ptr}. 
You should be able to traverse in both directions.
http://en.wikipedia.org/wiki/XOR_linked_list

#endif

/* Asuuming the size of pointer and size of unsigned int
is same. So for doing Xor operation, we need to typecast the address
into unsigned int. For this reason, the below gcc compiler options are
dissabled */

#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
#pragma GCC diagnostic ignored "-Wpointer-to-int-cast"

#include<stdio.h>
#include<stdlib.h>

typedef struct nod
{
    int data;
    struct nod * next;
}node;
 
 
void insert( node ** head , int data , node ** tail)
{
    node * temp = (node*)malloc( sizeof(node) );
    temp->data = data;
    temp->next = NULL;
 
    if (*head == NULL) // List is empty
    {
        *head = temp;  // First node in the list
        return ;
    }
    node * pre = NULL;
    node * cur = * head;
    node * nxt = NULL;
    
    while( cur->next != pre)
    {
        nxt = (node*)((unsigned int)cur->next ^ (unsigned int)pre);
        pre = cur;
        cur = nxt;
    }
 
    cur->next = (node*)((unsigned int)cur->next ^ (unsigned int)temp);
    temp->next = cur ;
    *tail = temp ;
    return;
}
 
void print( node * head )
{
    node * pre = NULL;
    node * cur = head;
    node * nxt = NULL;
    while( cur )
    {
        printf(" %d ",cur->data);
        nxt = (node*)((unsigned int)cur->next ^ (unsigned int)pre);
        pre = cur;
        cur = nxt;
    }
    printf("NULL\n");
    return;
}
 
int main()
{
    node * head = NULL;
    node * tail = NULL;
    srand(time(NULL));
    int i;
    for( i = 0; i < 10; i++){
        int num = rand()% 100;
        insert(&head, num, &tail);
    } 
    print( head );
    print( tail );
    return 0;
}

/* Enabling the compiler warning option */
#pragma GCC diagnostic pop
