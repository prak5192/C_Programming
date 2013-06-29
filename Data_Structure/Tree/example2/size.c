/* This problem demonstrates simple binary tree traversal. 
Given a binary tree, count the number of nodes in the tree.

int size(struct node* node) {
 
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};	

int count = 0;

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
        count ++;
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



int size(struct node* p) {
    if(p!=NULL)
    {   
        inorder(p->left);
       // printf("Data :%d\n",p->data);
        count ++;
        inorder(p->right);
    }   
    else {
    	return;
    }
    return count;
}


/* Main function starts here */
int main(void){
    struct node * node = NULL; /* Root pointer */
    int itr = 10; /* Number of nodes */
    int i;
        
    for( i = 1; i <= 10 ; i++){
        int data = rand()/100;
        node = insert(node,data);     
    }
    inorder(node);  
    printf("The size of the tree is %d\n", count);
    return 0;
}

