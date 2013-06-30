/* A simple program for queue program */

#include<stdio.h>
int main(void){
	int q[10]={0},i,front=-1,rear=-1,max=10,n,item;
	printf("\n\tMENU\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
	do{
		printf("\nEnter your choice\n");
		scanf("%d",&n);
		switch(n){
			case 1:
			if(rear<max-1){
				printf("Enter the element\n");
				scanf("%d",&item);
				if(rear==-1){
					front=0;
					rear=0;
					q[rear]=item;
				} else {
					q[++rear]=item;
				}
		    } else {
				printf("Overflow\n");
			}
			break;

			case 2:
				if(front>=0){
					printf("The deleted item =%d",q[front]);
					if(front==rear){
						front=-1;
						rear=-1;
					} else {
						front++;
					}
				} else {
					printf("Underflow\n");
				}
				break;

			case 3:
				if((front==-1)&&(rear==-1)){
					printf("The queue is empty\n");
			    } else {
					printf("The elements of the queue are :");
					for(i=front;i<=rear;i++){
						printf("%d\t",q[i]);
					}
				}
				break;

			case 4:
				break;

			default:
				printf("Invalid choice\n");
				break;
		}
	}while(n!=4);
	return 0;
}


