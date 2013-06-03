#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_SIZE 5
#define DELETE 2
#define INSERT 1
#define DISPLAY 3
#define EXIT 4
#define PASS 0
#define FAIL 1

int rear = -1;
int front = -1;
int array[MAX_SIZE];

int insert()
{
    int item ;
    printf("Enter the item to be inserted\n");
    scanf("%d",&item);
   
    if(rear == MAX_SIZE - 1){
        printf("QUEUE is FULL\n");
        return FAIL;
    } else {
        array[rear + 1] = item;
        rear++;
    }
    return PASS;
}

int delete()
{
    if((rear == -1) || (front == rear)){
        printf("QUEUE is empty\n");
        return FAIL;
    } else {
        front++;
        array[front] = 0;
    }
    return PASS;
}

void display()
{
    int i =0 ;
    for(i = 0; i< MAX_SIZE ; i++){
        printf("a[%d] => %d\n",i,array[i]);
    }
}
int main(void)
{
    printf("\n====== Simple queue Program using Array ======\n\n");
    int switch_option = 0;
    int true = 1;
    int ret = 1;
    do{
        printf("Enter the choice:-\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        scanf("%d",&switch_option);
        switch(switch_option){
            case INSERT:
                ret = insert();
                if(ret == PASS){
                    printf("Success in insertion process\n");
                } else {
                    printf("Error in insertion process\n");
                }
                break;   
            case DELETE:
                ret = delete();
                if(ret == PASS){
                    printf("Success in deletion process\n");
                } else {
                    printf("Error in deletion process\n");
                }
                break;   
            case DISPLAY:
                display();
                break;
            case EXIT:
                return 0;
                break;
            default:
                printf("The entered swicth option is out of range\n");
                break;
        }
        printf("Enter 1 if you want to continue\n");
        scanf("%d",&true);
   }while(true == 1); 
}
