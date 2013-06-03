#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef  struct Node{
    int data;
    struct Node *link;
}node;

node *head = NULL;

node *node1;
node *node2;    
node *node3;

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


void split_function(void){
    node1 = head;
    node2 = NULL;
    node3 = NULL;
    
    node *prev2 = NULL;
    node *prev3 = NULL;;

    int count  = 0;
    node *curnode = head;
    
    while(curnode != NULL){
        count++;
        if(count >  3){
            int mod = count % 3;
            if( mod == 1){
                prev2 = node2;
                node2 = node2->link;
                
                prev3 = node3;
                node3 = node3->link;
            } else if( mod == 2 ){
                prev3 = node3;
                node3 = node3->link;
            }
        } else if (count == 2){
            node2 = curnode ;
        } else if(count == 3){
                node3 = curnode;
        }
        curnode = curnode->link;
    }
    
    prev2->link  = NULL;
    prev2->link = NULL;
    
    return ;
}
int main(int argc, char * argv[])
{
   
    int i;
    srand(time(NULL));
    for(i = 0; i < 10; i++){
        int num = (rand()%10);
        add(num);   
    }
    display();
    split_function();
    display();

    return 0;
}

