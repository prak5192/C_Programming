/* A simple C code for binary tree */

/* Have to learn this binary tree by  this week */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct node{
    struct node *left;
    int data;
    struct node *right;
} Node;

void pre_order(Node *ptr);     
void in_order(Node *ptr);
void post_order(Node *ptr);
int insert_in_order(Node ** ptr, int data);
void delete(Node **ptr, int data);

/*
    Displaying the Binary tree in pre-order
eg. 1,2,3,4,5,6,7,8,9,10
*/
void pre_order(Node *ptr){
    if(ptr !=  NULL){
        printf("%d\n", ptr->data);
        in_order(ptr->left);
        in_order(ptr->right);
    } else {
        return ;
    }
}

/*
    Displaying the Binary tree in in-order
Print the root value first.
Then print the left link in tree. 
Then print the right link in tree.
*/
void in_order(Node *ptr){
    if(ptr !=  NULL){
        in_order(ptr->left);
        printf("%d\n", ptr->data);
        in_order(ptr->right);
    } else {
        return ;
    }
}
/*
    Displaying the Binary tree in post order
eg. 10,9,8,7,6,5,4,3,2,1
*/

void post_order(Node *ptr){
    if(ptr !=  NULL){
        printf("%d\n", ptr->data);
        in_order(ptr->left);
        in_order(ptr->right);
    } else {
        return ;
    }
}

/* 
    Inserting data into the Binary tree in sorted order 
*/

int insert_in_order(Node **ptr, int data){
    Node *temp_ptr = NULL;
    if( *ptr == NULL){
         Node *temp_ptr = calloc(1,sizeof(Node));
        if(temp_ptr == NULL){
            printf("Error on malloc\n");
        } 
        temp_ptr->data = data;
        temp_ptr->left = NULL;
        temp_ptr->right = NULL;
        *ptr = temp_ptr;
        return 0;
    } else {
        if( (*ptr)->data < data){
            insert_in_order(&((*ptr)->right), data);
        } else {
            insert_in_order(&((*ptr)->left), data);
        }
    } 
}    

void delete(Node **ptr, int data){
    Node *current;
    Node *prev;
    int found =0;
    if (*ptr == NULL){
        printf("Tree is empty\n");
        return; 
    }
    current = *ptr;
    while(current != NULL){
        if(current->data == data){
            found = 1;
            break;
        } else {
            prev = current;
            if(current->data >= data){
                current = current->left;
            } else {
                current = current->right;
            }
        }
    }
    if(found == 0){
        printf("Given data is not found in the tree\n");
        return;
    }

/*
    Delete node has no left , no  right wings 
*/
    
    if((current->left == NULL) && (current->right == NULL)){
        if(prev->left == current){
            prev->left == NULL;
        } else {
            prev->right == NULL;
        }
        free(current);
    }

/*
    Delete node (either left or right child )
*/

    if((current->left == NULL) && (current->right != NULL)){
        if(prev->left = current){
            prev->left = current->left;
        } else {
            prev->right = current->right;
        }
        free(current);
    }

    if((current->right == NULL) && (current->left != NULL)){
        if(prev->left = current){
            prev->left = current->left;
        } else {
            prev->right = current->right;
        }
        free(current);
    }
   
/*
   Delete the node with both left and right child 
*/
    if((current->left != NULL) && (current->right != NULL)){
        Node *tmp = current->right;
        if((tmp->left == NULL) && (tmp->right == NULL)){
            current->data = tmp->data;
            free(tmp);
            current->right = NULL;
        } else if(current->right->left != NULL) {
            Node *left_current = current->right;
            Node *left_current_prev = current->right->left;
            while(left_current->left != NULL){
                left_current_prev = left_current;
                left_current = left_current->left;
            }
            current->data = left_current->data;
            free(left_current);
        } else {
            Node *temp;
            temp = current->right;
            current->data = temp->data;
            current->right = temp->right;
            free(temp);
        }
    }
    return;
}

int main(int argc, char *argv[]){
    int ret;
    Node *node = NULL;
    int choice = 1; 
    int i;

    do {
        printf("Enter the choice for the Binary Tree\n");
        printf("1.display in pre_order\n");
        printf("2.display in in_order\n");
        printf("3.display in post_order\n");
        printf("4.Insert data in order\n");
        printf("5.Delete a node from the tree\n");
        printf("6.Exit\n");
        scanf("%d", &choice);
        switch (choice){
            case 1:
                printf("==============================================\n");
                pre_order(node);
                printf("==============================================\n");
                break;
            
            case 2:
                printf("==============================================\n");
                in_order(node);
                printf("==============================================\n");
                break;
            
            case 3:
                printf("==============================================\n");
                post_order(node);
                printf("==============================================\n");
                break;
            case 4: 
                printf("==============================================\n");
                for (i =0; i < 10; i++ ){
                    int data = rand()%100;
                    ret = insert_in_order(&node, data);
                    if(ret != 0){
                        printf("Something goes wrong in post-order\n");
                    }
                }
                break;
            case 5:
                printf("==============================================\n");
                printf("Enter the data you want to delete from the binary tree\n");
                int data;
                scanf("%d", &data);
                delete(&node, data);
                break; 
            
            case 6: 
                exit(0);

            case 7: 
                printf("==============================================\n");
                printf("The entered choice is not valid\n");
                printf("==============================================\n");
                break;
        }
    }while(1);
    return 0;
 }
