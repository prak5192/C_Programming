#include<stdio.h>
#include<stdlib.h>
 
#define MAX_SIZE 5
 
int stack[MAX_SIZE];
void push();
int pop();
void traverse();
int is_empty();
int top_element();
void display(void);
int top = -1;
 
main()
{
    int element, choice;
 
    while(1){
        printf("Stack Operations.\n");
        printf("1. Insert into stack (Push operation).\n");
        printf("2. Delete from stack (Pop operation).\n");
        printf("3. Print top element of stack.\n");
        printf("4. Check if stack is empty.\n");
        printf("5. Traverse stack.\n");
        printf("6. Print the elements of stack.\n");
        printf("7. Exit.\n");
        printf("Enter your choice.\n");
        scanf("%d",&choice);
 
        switch ( choice ){
            case 1:
                if ( top == MAX_SIZE - 1 ){
                    printf("Error: Overflow\n\n");
                } else {
                    printf("Enter the value to insert.\n");
                    scanf("%d",&element);
                    push(element);
                }
                break;
 
         case 2:
                if ( top == -1 ){
                    printf("Error: Underflow.\n\n");
                } else {
                    element = pop();
                    printf("Element removed from stack is %d.\n", element);
                }
                break;
 
         case 3:
                if(!is_empty()) {
                    element = top_element();
                    printf("Element at the top of stack is %d\n\n", element); 
                } else {
                    printf("Stack is empty.\n\n");   
                }
                break;
 
         case 4:
                if(is_empty()){
                    printf("Stack is empty.\n\n");
                } else {
                    printf("Stack is not empty.\n\n");
                }
                break;
 
         case 5:
                traverse();
                break;
         case 6:
                display();
                break;
 
         case 7:
                exit(0);
      }
   }
}
 
void push(int value)
{   
    top++;
    stack[top] = value;
}
 
int pop()
{
    int element;
 
    if ( top == -1 ){
        return top;
    }
 
    element = stack[top];
    top--;
 
    return element;
}   
 
void traverse()
{
    int d;
 
    if ( top == - 1 ){
        printf("Stack is empty.\n\n");
        return;
    }   
 
    printf("There are %d elements in stack.\n", top+1);
 
    for ( d = top ; d >= 0 ; d-- ){
        printf("%d\n", stack[d]);
    }
    printf("\n");
}  
 
int is_empty()
{
    if ( top == - 1 )
        return 1;
    else
        return 0;
}

void display(void){
    int i;
    for(i = 0; i< MAX_SIZE ; i++){
        printf("Stack[%d] = %d\n", i, stack[i]);
    }
}
 
int top_element()
{
    return stack[top];
}
