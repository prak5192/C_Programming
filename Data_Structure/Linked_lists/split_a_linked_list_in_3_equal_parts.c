#if 0

This program is used to split the given number into three parts 
eg:
Orignal Linked list: 1 2 3 4 5 6 7 8 9
Splited Linked list:
List1 = 1 4 7
List2 = 2 5 8
List3 = 3 6 9

#endif

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef  struct Node{
    int data;
    struct Node *link;
}node;

node *head = NULL;

node *head1;
node *head2;    
node *head3;

void add(int num)
{
    node *temp;
    node *first;
    temp = (node *) malloc(sizeof(node));
    if(temp == NULL){
       perror("Malloc error\n");
        exit(-1);
    }
    temp->data = num;
    temp->link = NULL;
    first = head;
    if(first == NULL){
        head = temp;
    }else {
        while(first->link != NULL){
            first = first->link;
        }
        first->link = temp;
    }
    return ;
}
    
void display(node *thead){
    node *first = thead;
    while(first != NULL){
        printf("%d  \t",first->data);
        first = first->link;
    }
    printf("\n");
    return ;
}    


void split_function(void){
	head1 = head;
    node *node1 = head;
    node *node2 = NULL;
    node *node3 = NULL;
	if(node1->link != NULL){
    	head2 = node1->link;
		node2 = head2;
	}
	if(node1->link->link != NULL){
    	head3 = node1->link->link;
		node3 = head3;
   	}
 

    int count  = 0;
    node *curnode = node1->link->link->link;
    
    while(curnode != NULL){
        int mod = count % 3;
        if(mod == 0){
			node1->link = curnode;
			node1 = curnode;
        } else if (mod == 1){
			node2->link = curnode;
			node2 = curnode;
		} else if( mod == 2){
			node3->link = curnode;
			node3 = curnode;
    	}	
		curnode = curnode->link;
        count++;
	}
	node3->link = NULL;
	node2->link = NULL;
	node1->link = NULL;
    return ;
}

int main(int argc, char * argv[])
{
   
    int i;
    srand(time(NULL));
    for(i = 0; i < 10; i++){
        int num = (rand()%10);
        add(num);   
    }
    display(head);
    split_function();
	printf("================Splited List1===========\n");
    display(head1);
	printf("================Splited List2===========\n");
    display(head2);
	printf("================Splited List3===========\n");
    display(head3);

    return 0;
}

