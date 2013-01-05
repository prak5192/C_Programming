/*
  	File: 2nd_largest_number.c
	Brief: This program is used to find the 2ns largest number in a array of 
		   integers with using only one loop.
	Date: 5th Jan 2013
	Author: Prakash Ranjan
*/

#include <stdio.h>
int main(void)
{
	int a[10];	
	int temp, temp1, temp2, second=0;
	int count =0;
	int j,i;
	
    printf("Enter the 8 number to array\n");
    for(i = 0 ; i< 8;  i++)
    {
        scanf("%d",&a[i]);
    }
	second = 0;
    
    if(a[0] > a[1]){
        second = a[1];
    }else{
        second = a[0];
        temp = a[0];
        a[0] = a[1];
        a[1] = temp;
    }
	
    for(j = 2; j<8;j++)
	{
		if(a[j] > a[0])
		{
            second = a[0];
            a[0] = a[j]; 
        }else{
            if(a[j] > second){
                second = a[j];
            }
        }
	}
    printf("2nd largest number is %d\n",second);
    return 0;
}	
		
