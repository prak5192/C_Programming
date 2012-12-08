/*
    Circular Doubly linked list
*/

#include<stdio.h>
#include<stdlib.h>

struct my_list{
    struct my_list *prev;
    int data;
    struct my_list *next;
}

typedef struct my_list list;

list *first = NULL;

int append_end(int data);
int append_beg(int data);
int append_mid(int data);
int display(void);
int delete_data(int data);
int delete_pos(int pos);
int length(void);


int main(void){
    int ret =  PASS;


    return ret;
}



    
