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


struct node * NewNode(struct node *node; int data);
{
    struct node * node;
    node = (struct node *) malloc(sizeof(struct node ));
    node->data = data;
    node->left = NULL;
    node->left = NULL;
    return node;
}



int main(void){


    return 0;
}
