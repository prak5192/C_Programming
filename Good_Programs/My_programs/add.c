/*
  	File:
	Brief: This program is used to add two number using xor operation and recurssive 
		   method.
	Date: 5th Jan 2013
	Author: Prakash Ranjan
*/
#include<stdio.h>

int add(int,int);

void main()
{
    int a,b;
    printf("Enter the two Numbers:\n");

    scanf("%d%d",&a,&b);

    printf("Addition of two num. is : %d\n",add(a,b));
}

int add(int a, int b)
{
    if (!a) 
        return b;
    else
        return add((a & b) << 1, a ^ b);
} 

