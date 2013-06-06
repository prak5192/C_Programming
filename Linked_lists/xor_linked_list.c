#if 0
Link:
===========
Implement a double linked list using a single linked list. 
You have given only data and one pointer in struct node 
{ int data, struct node *ptr}. 
You should be able to traverse in both directions.
http://en.wikipedia.org/wiki/XOR_linked_list

#endif

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
 
    if ( !(*head))
    {
        *head = temp;
        return ;
    }
    node * pre = NULL;
    node * cur = * head;
    node * nxt = NULL;
    
    while( cur->next != pre)
    {
        nxt = (node*)((unsigned int)cur->next ^(unsigned int)pre);
        pre = cur;
        cur = nxt;
    }
 
    cur->next = (node*)((unsigned int)cur->next^(unsigned int)temp);
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
        nxt = (node*)((unsigned int)cur->next ^(unsigned int)pre);
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
    insert(&head,3,&tail);
    insert(&head,5,&tail);
    insert(&head,7,&tail);
    insert(&head,11,&tail);
    insert(&head,13,&tail);
    print( head );
    print( tail );
    return 0;
}


