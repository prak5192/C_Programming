/* Simple binary tree program */


# include<stdio.h>
# include<stdlib.h>
# include<string.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};
void insert(struct node **,int);
void inorder(struct node *);
void postorder(struct node *);
void preorder(struct node *);

void main()
{
    struct node *ptr;
    int will,i,num;
    ptr = NULL;
    printf("Enter the number of terms you want to add to the tree.\n");
    scanf("%d",&will);

/* Getting Input */
    for(i=0;i<will;i++)
    {
        printf("Enter the item\n");
        scanf("%d",&num);
        insert(&ptr,num);
    }

    printf("INORDER TRAVERSAL\n");
    inorder(ptr);
    printf("PREORDER TRAVERSAL\n");
    preorder(ptr);
    printf("POSTORDER TRAVERSAL\n");
    postorder(ptr);
}

void insert(struct node  **p,int num)
{
    if((*p)==NULL)
    {   
        printf("Leaf node created.\n");
        (*p)=malloc(sizeof(struct node));
        (*p)->left = NULL;
        (*p)->right = NULL;
        (*p)->data = num;
        return;
    }
    else
    {       
        if(num==(*p)->data)
        {
            printf("REPEATED ENTRY ERROR VALUE REJECTED\n");
            return;
        }
        if(num<(*p)->data)
        {
            printf("Directed to left link.\n");
            insert(&((*p)->left),num);
        }
        else
        {
        printf("Directed to right link.\n");
        insert(&((*p)->right),num);
        }
    }
    return;
}

void inorder(struct node *p)
{
    if(p!=NULL)
    {
        inorder(p->left);
        printf("Data :%d\n",p->data);
        inorder(p->right);
    }
    else
        return;
}


void preorder(struct node *p)
{
    if(p!=NULL)
    {
        printf("Data :%d\n",p->data);
        preorder(p->left);
        preorder(p->right);
    }
    else
        return;
}


void postorder(struct node *p)
{
    if(p!=NULL)
    {
        postorder(p->left);
        postorder(p->right);
        printf("Data :%d\n",p->data);
    }
    else
        return;
}

