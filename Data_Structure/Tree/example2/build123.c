/* Write code that builds the following little 1-2-3 binary search tree... 

          1
         / \
        2   3

Write the code in three different ways...
1: by calling newNode() three times, and using only one pointer variable
2: by calling insert() three times passing it the root pointer to build up the tree

*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};	


void method1(void);
void method2(void);
/* Wrapper function to create a new node */

struct node * NewNode(int data){
    struct node * node;
    node = (struct node *) malloc(sizeof(struct node ));
    node->data = data;
    node->left = NULL;
    node->left = NULL;
    return node;
}


/* To print the tree in order way */
void inorder(struct node *p) 
{
    if(p!=NULL)
    {   
        inorder(p->left);
        printf("Data :%d\n",p->data);
        inorder(p->right);
    }   
    else {
    	return;
    }
}

/* Inser function to insert a node into tree */
struct node * insert(struct node * node, int data){
    if(node == NULL){
        return (NewNode(data));
    } else {
        if( data <= node->data){
            node->left = insert(node->left,data);
        } else {
            node->right = insert(node->right,data);
        }
        return node;
    }
}


/* Main function starts here */
int main(void){
    int option;
    printf("Enter the method you want\n");
    scanf("%d",&option);
    switch(option){
        case 1:
                method1(); 
                break;
        case 2:
                method2(); 
                break;
        default:
                printf("Entered option is wrong\n");
                exit(0);
    }
    return 0;
}


void method1(void){
    struct node * node = NULL; /* Root pointer */
    node = NewNode(1);
    node->left = NewNode(2);
    node->right = NewNode(3);
    inorder(node);  
}

void method2(void){
    struct node * node = NULL; /* Root pointer */
    int count = 3; /* Number of nodes */
    int i;
        
    for( i = 1; i <= count ; i++){
        node = insert(node,i);     
    }
    inorder(node);  
}
