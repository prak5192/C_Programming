/*
Given a binary tree, return true if a node with the target data is found 
in the tree. Recurs down the tree, chooses the left or right branch by 
comparing the target to each node.
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define TRUE 0
#define FALSE -1
struct node {
	int data;
	struct node * left;
	struct node * right;
};

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

struct node* NewNode(int data) {
	struct node* node1;
	node1  = (struct node*) malloc(sizeof(struct node ));
	// "new" is like "malloc"
	node1->data = data;
	node1->left = NULL;
	node1->right = NULL;
	return(node1);
}

static int lookup(struct node* node, int target) {
	// 1. Base case == empty tree
	// in that case, the target is not found so return false
	if (node == NULL) {
		return(FALSE);
	} else {
		// 2. see if found here
		if (target == node->data){
			return(TRUE);
		} else {
			// 3. otherwise recur down the correct subtree
			if (target < node->data) {
				return(lookup(node->left, target));
		        } else { 
				return(lookup(node->right, target));
			}	
		}
	}
}

struct node* insert(struct node* node, int data) {
	// 1. If the tree is empty, return a new, single node
	if (node == NULL) {
		return(NewNode(data));
	} else {
		// 2. Otherwise, recur down the tree
		if (data <= node->data) 
			node->left = insert(node->left, data);
		else 
			node->right = insert(node->right, data);

		return(node); // return the (unchanged) node pointer
	}	
}

int main(void) {
	struct node *node = NULL;
	int count=0;
	printf("Enter the number of elemnts you wnat to enter in the bree\n");
	scanf("%d",&count);
	int data;
	int i = 0;
	for(i = 0; i < count ; i++){
		scanf("%d",&data);
		node =	insert(node,data);
	}

	inorder(node);
}

