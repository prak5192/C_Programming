/* A simple C code for binary tree */

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

void pre_order(Node *ptr){
    if(ptr !=  NULL){
        printf("%d\n", ptr->data);
        in_order(ptr->left);
        in_order(ptr->right);
    } else {
        return ;
    }
}

void in_order(Node *ptr){
    if(ptr !=  NULL){
        in_order(ptr->left);
        printf("%d\n", ptr->data);
        in_order(ptr->right);
    } else {
        return ;
    }
}

void post_order(Node *ptr){
    if(ptr !=  NULL){
        printf("%d\n", ptr->data);
        in_order(ptr->left);
        in_order(ptr->right);
    } else {
        return ;
    }
}

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


int main(int argc, char *argv[]){
    int ret;
    Node *node = NULL;
    int choice = 1; 
    int i;

    do {
        printf("Enter the choice for the Binary Tree\n");
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
                exit(0);

            case 6: 
                printf("==============================================\n");
                printf("The entered choice is not valid\n");
                printf("==============================================\n");
                break;
        }
    }while(1);
    return 0;
 }
