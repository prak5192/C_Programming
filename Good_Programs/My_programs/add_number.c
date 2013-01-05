/*
  	File: add_number.c
	Brief: This program is used to add digits of number using single statement.
	Date: 5th Jan 2013
	Author: Prakash Ranjan
*/

#include<stdio.h>
void main()
{
    int number=12354;
    int sum=0;
    for(;number > 0;sum+=number%10,number/=10); 
        printf("\nSum of the Digits : %d\n",sum);
}

