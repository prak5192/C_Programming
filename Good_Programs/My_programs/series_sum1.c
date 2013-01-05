/*
	File: series_sum1.c
	Brief:	Sum of 1^2 + 2^2 + …. + n^2 series in c programming language
	Date: 5th Jan 2013
	Author: Prakash Ranjan
*/

#include<stdio.h>

int main(void)
{
    int sum = 0;
	int n = 0;
	int i = 0;
	printf("Enter the number till you want to calculate the sum\n");
	scanf("%d",&n);
	for(i = 1;i <= n ; i++){
		sum = sum + i*i;
	}
	printf("The num of the series is %d\n",sum);  


	/* TODO:  Have to find the sum using recursion */
	sum = 0;
	i = 0;

	return 0;
}
