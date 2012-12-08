/*
    Reading a linked list from a file and writting a linked list to a file
*/


#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>


struct node 
{
    int data;
	struct node *link;
};

struct node *new = NULL;
struct node *p=NULL;
void delet_pos(int);
void delet_data(int);
void append_mid(int ,int);
void append_begg(int);
void append_end(int );
void revers();
void display();
void save_to_file();    
void read_from_file();    
int main(void)
{
	int ch,item,pos;
	while(1)
	{

		printf("\nenter ur option:\n");
		printf("\n1:insert the number in the front\n2:insert the element in the end\n3:append in the mid\n4:display the elements\n");
		printf("5:delet the node w.r.t pos\n6:delet the node with respect to data\n7:reverse the linke list\n");
		printf("8:Save to file\n9:Read from file\n");
		scanf("%d",&ch);
		switch(ch)
		{
		case 1:
			printf("enter the number\n");
//			scanf("%d",&item);
            for(pos = 0; pos<10; pos++){
			    append_begg(pos);
            }
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
            printf("Writting the linked list on the file :\n");
            save_to_file();    
            break;
        case 9:
            printf("Read from the file :\n");
            read_from_file();    
            break;
        default:
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
    printf("Displaying from temperory database\n");
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
	}

    printf("\nDisplaying from file database\n");
	q = new;
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
void save_to_file(void)
{
    FILE *fp;
    int ret = 0;
    fp = fopen("./linked_list_DB.txt","w+");
    if(fp == NULL){
        printf("File opening gets failed\n");
        exit(0);
    }
    int i = 0;
    struct node * temp = NULL;
    temp = p;
    while( temp != NULL){
        printf("i    ==========> %d\n", i);
        ret = fwrite(temp,sizeof(struct node),1,fp);
        if(ret == 0){
            break;
        }
        temp = temp->link;
    }
    fclose(fp);
}

void read_from_file(void)
{
    printf("reading from file\n");
    struct node *temp = NULL;
    FILE *fp = NULL;
    int ret = 0;
    int i =0;
    fp = fopen("./linked_list_DB.txt","r+");
    if(fp == NULL){
        printf("Error in opening the file\n");
        exit(0);
    }
    temp = new;
    struct node *f = NULL;
    while(!feof(fp)){
        f = calloc(1,sizeof(struct node));  
        if(f == NULL){
            printf("Calloc_fails\n");
            exit(0);
        }
        ret = fread(f,sizeof(struct node), 1, fp);
        if(ret == 0){
            break;
        }
        f->link = NULL;
        printf("The value from file is %d\n",f->data); 
        if(temp == NULL){
            new = f;
            temp = new;
            printf("i = %d, value %d\n",i, temp->data);
            i++;
        }else{
            while(temp->link != NULL){
                printf("i = %d, value %d\n",i, temp->data);
                i++;
                temp = temp->link;
            }
            temp->link = f;
        }
    }
     
} 
