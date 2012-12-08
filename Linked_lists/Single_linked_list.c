/* 
  Single linked list
*/


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


struct node 
{
  int data;
	struct node *link;
};

struct node *p=NULL;
void delet_pos(int);
void delet_data(int);
void append_mid(int ,int);
void append_begg(int);
void append_end(int );
void revers();
void display();

int main(void)
{
	int ch,item,pos;
	while(1)
	{

		printf("\nenter ur option:\n");
		printf("\n1:insert the number in the front\n2:insert the element in the end\n3:append in the mid\n4:display the elements\n");
		printf("5:delet the node w.r.t pos\n6:delet the node with respect to data\n7:reverse the linke list\n8:exit\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("enter the number\n");
			scanf("%d",&item);
			append_begg(item);
			break;
		case 2:
			printf("enter the number:\n");
			scanf("%d",&item);
			append_end(item);
			break;
		case 3:
			printf("enter the number and the postision: \n");
			scanf("%d %d",&item, &pos);
			append_mid(item, pos);
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
			revers();
			break;
		case 8:
			exit(0);
		}
	}
	return 0;
}

void append_begg(int item)
{
	struct node *temp;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->data= item;
	temp->link= NULL;
	if(p==NULL)
	{
		p = temp;
	}
	else
	{
		temp->link = p;
		p = temp;
	}
}

void append_end(int item)
{
	 struct node *temp,*q;
	 q = p;
	 temp = (struct node*)malloc(sizeof (struct node));
	 temp->data = item;
	 temp->link = NULL;
	 if(p==NULL)
	 {
		p = temp;
	 }
	 else
	 {
		 while(q->link != NULL)
		 {
			 q = q->link;
		 }
		 q->link = temp;
	 }
	 return;
}

void append_mid(int item, int pos)
{
	struct node *temp, *next,*pre;
	next = p;
	pre = p;
	temp = (struct node *)malloc(sizeof(struct node));
	temp->data = item;
	temp->link = NULL;
	if(pos == 0)
	{
		temp->link= p;
		p = temp;
		return;
	}
	else
	{
		while(pos!=0 && next != NULL)
		{
			pre = next;
			next = next->link;
			pos--;
		}
		pre->link = temp;
		temp->link = next;
	}
	return;
}

void delet_pos(int pos)
{
	struct node * next, *pre;
	next = p;
	if(pos == 0)
	{
		p = p->link;;
		free(next);
		return;
	}
	else
	{
		while(pos!=0 && next != NULL)
		{
			pre = next;
			next = next->link;
			pos--;
		}
		pre->link = next->link;
		free (next);
	}
	return;
}

void delet_data(int data)
{
	struct node * next,*pre;
	next = p;
	if(next->data == data)
	{
		p = p->link;;
		free(next);
		return;
	}
	else
	{
	while(next != NULL && next->data != data)
		{
			pre = next;
			next = next->link;
		}
	if(next == NULL)
	{
		printf("no data found\n");
		return;
	}

	pre->link = next->link;
	free (next);
	}
	return;
}


void display()
{
	struct node* q;
	q = p;
	if(q==NULL)
	{
		printf("no node to display\n");
		return ;
	}
	else
	{
		while(q!=NULL)
		{
			printf("%d->",q->data);
			q= q->link;
		}
	
		return;
	}
}



void revers()
{
	struct node *q,*r,*s;
	q = p;
	r = NULL;
	while(q!= NULL)
	{
		s = r;
		r = q;
		q= q->link;
		r->link= s;
	}
	p =r;
}