/*
    Compute the "maxDepth" of a tree -- the number of nodes along
    the longest path from the root node down to the farthest leaf node.
    http://stackoverflow.com/questions/6343668/finding-maxdepth-in-binary-search-tree
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};	


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

int maxDepth(struct node* node) {
    if (node == NULL) {
        return(0);
    } else {
        // compute the depth of each subtree
        int lDepth = maxDepth(node->left);
        int rDepth = maxDepth(node->right);
        // use the larger one
        if (lDepth > rDepth) 
            return (lDepth+1);
        else 
            return (rDepth+1);
    }
}



/* Main function starts here */
int main(void){
    struct node * node = NULL; /* Root pointer */
    int i;
    int data;
        
    for( i = 1; i <= 13 ; i++){
        scanf("%d",&data);
        node = insert(node,data);     
    }

    inorder(node);  
    printf("Max depth is %d\n",maxDepth(node));
    return 0;
}

