/* Write code that builds the following little 1-2-3 binary search tree... 

          1
         / \
        2   3

Write the code in three different ways...
a: by calling newNode() three times, and using three pointer variables
b: by calling newNode() three times, and using only one pointer variable
c: by calling insert() three times passing it the root pointer to build up the tree

*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};	


struct node * NewNode(int data){
    struct node * node;
    node = (struct node *) malloc(sizeof(struct node ));
    node->data = data;
    node->left = NULL;
    node->left = NULL;
    return node;
}

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


int main(void){
    struct node * node = NULL;
    int count = 3;
    int i;
    int data;
    
    for( i = 1; i <= count ; i++){
        node = insert(node,i);     
    }

    inorder(node);    
    return 0;
}
