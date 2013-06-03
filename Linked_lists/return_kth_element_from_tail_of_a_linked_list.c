#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef  struct Node{
    int data;
    struct Node *link;
}node;

node *head = NULL;


void add(int num)
{
    node *temp;
    node *first;
    temp = (node *) malloc(sizeof(node));
    if(temp == NULL){
       perror("Malloc error\n");
        exit(-1);
    }
    temp->data = num;
    temp->link = NULL;
    first = head;
    if(first == NULL){
        head = temp;
    }else {
        while(first->link != NULL){
            first = first->link;
        }
        first->link = temp;
    }
    return ;
}
    
void display(void){
    node *first = head;
    while(first != NULL){
        printf("%d -> \t",first->data);
        first = first->link;
    }
    printf("\n");
    return ;
}    
     
int return_kth_element(int pos){
    node * fisrt =head;
    node *ref1= head;
    node *ref2 = head;
    
    int i = 0;
    for(i = 0; i< pos; i++){
        ref2 = ref2->link;
    }
    
    while(ref2 != NULL){
        ref1 = ref1->link;
        ref2 = ref2->link;
    }

    return ref1->data;
} 
        
int main(int argc, char * argv[])
{
   
    int i;
    for(i = 0; i < 10; i++){
        add(i);
    }
    display();

    int ret = return_kth_element(atoi(argv[1]));
    printf("%d\n", ret);
    return 0;
}   
