/*
	File :	largest_sum_contiguous_subarray.c
	Brief: 	Gives the largest sum of subarray in a one diemntional array
			Also it return the start and end index of the sub array.
			Note:  The program fails if all the number is negative.
	Date: 	5th Jan 2013
	Author : Prakash Ranjan 
	HelpLink: http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

*/

#include<stdio.h>

int start_index = 0;
int stop_index = 0;

int sub_array_sum(int a[], int size)
{
	printf("The size of array is %d\n",size);
	int sum_prev = 0, sum_next= 0;
  	int i;
   	for(i = 0; i < size; i++){
     	sum_next = sum_next + a[i];
     	if(sum_next < 0){
        	sum_next = 0;
			start_index = i + 1;
		}
     	if( sum_prev < sum_next){
        	sum_prev = sum_next;
			stop_index = i;
    	}
	}
    return sum_prev;
}

/* Main function starts here */
 
int main(void)
{
	int array[] = {-2, -3, 3, 4, 6, -10, 25, 4, -1, -2};
   	int max_sum = sub_array_sum(array, sizeof(array)/sizeof(int));
   	printf("Max contiguous sum %d\n", max_sum);
   	printf("Start index %d\n", start_index);
   	printf("Stop  index %d\n", stop_index);
  	return 0;
}
