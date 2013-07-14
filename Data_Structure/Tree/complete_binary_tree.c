#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
 
struct bst
{
    int info;
    struct bst *left;
    struct bst *right;
};
 
 
void delete(struct bst *root, int key);
struct bst *find_min(struct bst *node);
struct bst *find_max(struct bst *node);
struct bst *insert(struct bst *node, int key);
void print_postorder(struct bst *root);
void print_preorder(struct bst *root);
void print_inorder(struct bst *root);
int height(struct bst *root);
 
//deleting the element which handles three cases
//1. deleting node has no leaf nodes
//2. deleting node has one child(left or right)
//3. deleting node has two childs
void delete(struct bst *root, int key)
{
    struct bst *current;
    struct bst *prev;
    int found = 0;
    if(root == NULL){
        printf("The BST is empty\n");
        return;
    }
    current = root;
    while(current!=NULL){
        if(current->info == key){
            found = 1;
            break;
        } else {
            prev = current;
            if(current->info >= key)
                current = current->left;
            else
                current = current->right;
        }
    }
    if(!found){
        printf("given key element is not in the BST\n");
        return;
    }
 
 //leaf node , no left n right childs
    if((current->left == NULL) && (current->right == NULL)){
        if(prev->left == current)
            prev->left = NULL;
        else
            prev->right = NULL;
        free(current);
    }
 
 //single child node (either left or right child)
    if(current->left == NULL && current->right != NULL){
        if(prev->left == current)
            prev->left = current->right;
        else
            prev->right = current->right;
        free (current);
    }
 
    if(current->right == NULL && current->left!=NULL){
        if(prev->left = current)
            prev->left = current->left;
        else
            prev->right = current->left;
        free(current);
    }
 
 // need to handle the very complex case(node with both left n right childs)
    if(current->left != NULL && current->right != NULL){
        struct bst *tmp = current->right;
        if(tmp->left == NULL && tmp->right == NULL){
            current->info = tmp->info;
            free(tmp);
            current->right = NULL;
        } else if(current->right->left != NULL) {
            struct bst *left_current = current->right;
            struct bst *left_current_prev = current->right->left;
            while(left_current->left != NULL) {
                left_current_prev = left_current;
                left_current = left_current->left;
            }
            current->info = left_current->info;
            free(left_current);
            left_current_prev->left = NULL;
        } else {
            struct bst *temp;
            temp = current->right;
            current->info = temp->info;
            current->right = temp->right;
            free(temp);
        }
    }
}
 
//finding the min value
struct bst *find_min(struct bst *node)
{
    if(node == NULL)
        return NULL;
    if(node->left == NULL)
        return node;
    else
        return find_min(node->left);
}
 
 
//finding the max value
struct bst *find_max(struct bst *node)
{
    if(node!=NULL){
        while(node->right!=NULL){
            node = node->right;
        }
    }
    return node;
}
 
//adding the new element to the BST
struct bst *insert(struct bst *node, int key)
{
    if(node == NULL){
    //creating the new node with the key and left n right sub nodes empty
        node = (struct bst *)malloc(sizeof(struct bst));
        node->info = key;
        node->left = node->right = NULL;
    } else if(node->info >= key){
        node->left = insert(node->left, key);
    } else{
        node->right= insert(node->right, key);
    }
    return node;
}
 
//printing post order (LRP)
void print_postorder(struct bst *root)
{
    struct bst *temp = root;
    if(temp!=NULL){
        print_postorder(temp->left);
        print_postorder(temp->right);
        printf("%d ",temp->info);
    }
}
 
//printing preorder(PLR)
void print_preorder(struct bst *root)
{
    struct bst *temp = root;
    if(temp!=NULL){
        printf("%d ",temp->info);
        print_preorder(temp->left);
        print_preorder(temp->right);
    }
}
 
//printing inorder (LPR)
void print_inorder(struct bst *root)
{
    struct bst *temp = root;
    if(temp!=NULL){
        print_inorder(temp->left);
        printf("%d ",temp->info);
        print_inorder(temp->right);
    }
}
// to find the height of the tree
int height(struct bst *root)
{
    struct bst *temp = root;
    int leftH = 0;
    int rightH = 0;
    if(temp == NULL)
        return 0;
    if(temp->left)
        leftH = height(temp->left);
    if(temp->right)
        rightH = height(temp->right);
    return leftH >rightH ? leftH+1 : rightH+1;
}
 
 
int main(void)
{
    struct bst *root=NULL;
    struct bst *tmp=NULL;
    int i,n,key,option;
    printf("Enter the no. elements in the BST\n");
    printf("===========================================================\n");
    scanf("%d",&n);
    printf("Enter the list of elements in the BST\n");
    printf("===========================================================\n");
    for(i=0;i<n;i++){
        scanf("%d",&key);
        root = insert(root,key);
    }
    printf("===========================================================\n");
    while(1){
        printf("Below are the possible opetaions you can performe in the above created BST\n");
        printf("1. Insert\n2. Delete\n3. In-Order\n4. Pre-Order\n5. Post-Order\n6. Find Minimum\n7. Find Max\n8. height\n9. Exit");
        printf("===========================================================\n");
        scanf("%d",&option);
        switch(option){
            case 1:
                printf("===========================================================\n");
                printf("Enter the value to insert into the BST\n");
                scanf("%d",&key);
                root = insert(root,key);
                printf("===========================================================\n");
                break;
            case 2:
                printf("===========================================================\n");
                printf("Enter the value to delete from the BST\n");
                scanf("%d",&key);
                delete(root,key);
                printf("===========================================================\n");
                break;
            case 3:
                printf("===========================================================\n");
                print_inorder(root);
                printf("\n===========================================================\n");
                break;
            case 4:
                printf("===========================================================\n");
                print_preorder(root);
                printf("\n===========================================================\n");
                break;
            case 5:
                printf("===========================================================\n");
                print_postorder(root);
                printf("\n===========================================================\n");
                break;
            case 6:
                printf("===========================================================\n");
                tmp = find_min(root);
                if(tmp)
                    printf("Min value in BST is %d\n",tmp->info);
                printf("===========================================================\n");
                break;
            case 7:
                printf("===========================================================\n");
                tmp = find_max(root);
                if(tmp)
                    printf("Max value in BST is %d\n",tmp->info);
                printf("===========================================================\n");
                break;
            case 8:
                printf("===========================================================\n");
                printf("height of the BST is %d\n",height(root));
                printf("===========================================================\n");
                break;
            case 9:
                printf("Exit the program\n");  
                exit(0);
            default:
                printf("Enter a valid case number\n");
                break;
        }
    }
}
