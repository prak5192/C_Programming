/*
  Double linked list
*/


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct dnode
{
  struct dnode *pre;
	int data;
	struct dnode *next;
};

struct dnode *P = NULL;


struct dnode * creat_new(int );
void insert_front(int );
void insert_end(int);
void insert_mid(int, int);
void delet_pos(int);
void delet_data(int);
void display();


int main(void)
{
	int ch,item,pos;	
	while(1)
	{
		printf("enter ur choice;\n");
		printf("\n1:insert the number in the front\n2:insert the element in the end\n3:append in the mid\n4:display the elements\n");
		printf("5:delet the node w.r.t pos\n6:delet the node with respect to data\n7:exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("enter the number\n");
			scanf("%d",&item);
			insert_front(item);
			break;
		case 2:
			printf("enter the number:\n");
			scanf("%d",&item);
			insert_end(item);
			break;
		case 3:
			printf("enter the number and the postision: \n");
			scanf("%d %d",&item, &pos);
			insert_mid(item, pos);
			break;

		case 4:
			display();
			break;
		case 5:
			printf("enter the pos:\n");
			scanf("%d",&pos);
			delet_pos(pos);
			break;
		case 6:
			printf("enter the data\n");
			scanf("%d",&item);
			delet_data(item);
			break;
		case 7:
			exit(0);
		}
	}
	return 0;
}


struct dnode* creat_new(int item)
{
	struct dnode *temp;
	temp = (struct dnode*)malloc(sizeof(struct dnode));
	if(temp == NULL)
	{
		printf("no memory to allocate\n");
		exit(1);
	}
	temp->data = item;
	temp->next = NULL;
	temp->pre = NULL;
	return temp;
}



void insert_front(int item)
{
	struct dnode *temp;
	temp = creat_new(item);
	if(P == NULL)
	{
		P = temp;
	}
	else
	{
		temp->next = P;
		P->pre = temp;
		P = temp;
		return;
	}
}

void insert_end(int item)
{
	struct dnode *temp,*q;
	q =P;
	temp = creat_new(item);
	if(P == NULL)
	{
		P = temp;
	}
	else
	{
		while(q->next!=NULL)
		{
			q = q->next;
		}
		q ->next =  temp;
		temp->pre = q;
	}
	return;
}

void insert_mid(int item, int pos)
{
	struct dnode *temp,*q;
	q = P;
	temp = creat_new(item);
	if(pos == 0)
	{
		temp ->next = P;
		P->pre = temp;
		P = temp;
	}
	else
	{
		while(pos!=0 && q!=NULL)
		{
			q = q->next;
			pos--;
		}
		if(q== NULL)
		{
			printf("the is the last node use append_end to insert in the end\n");
			return;
		}
		q->pre->next = temp;
		temp->pre = q->pre;
		temp->next = q;
		q->pre = temp;
	}
	return;
}



	

void display()
{
	struct dnode *q;
	q =P;
	if(q == NULL)
	{
		printf("no elements to disply\n");
			return ;
	}
	else
	{
		while(q != NULL)
		{
			printf("%d->",q->data);
			q = q->next;
		}
		return;
	}
}

void delet_pos(int pos)
{
	struct dnode *q;
	q =P;
	if(q == NULL)
	{
		printf(" list is already empty\n");
		return;
	}

	if(pos==0)
	{
		P = P->next;
		P->pre = NULL;
		free(q);
		return;
	}
	while((pos-1)!= 0&& q->next!=NULL)
	{
		q = q->next;
		pos--;
	}
	if(q->next== NULL)
	{
		printf("this is the last node  \n");
		q->pre->next = NULL;
		free(q);
		return ;
	}
	else
	{
	q->next->pre = q->pre;
	q->pre->next = q->next;
	free(q);

	}
}
		
		
void delet_data(int item)
{
	struct dnode *q;
	q = P;
	if(q == NULL)
	{
		printf("no element to display\n");
		return;
	}
	if(item == q->data)
	{
		P = P->next;
		P->pre = NULL;
		free(q);
		return;
	}
	while(item!= q->data && q->next != NULL)
	{
		q = q->next;
		
	}
	if(q->next== NULL)
	{
		printf("this is the last node  \n");
		q->pre->next = NULL;
		free(q);
		return ;
	}
	else
	{
	q->next->pre = q->pre;
	q->pre->next = q->next;
	free(q);
	}
}
