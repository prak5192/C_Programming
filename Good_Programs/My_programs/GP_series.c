/*
	File: GP_series.c
	Brief: A program for sum of the series.
	Date: 29th Dec 2012
		
	Sum of 1 + 2 + 3 + 4 + 5 + ... + infinity  series in c programming language
	if a< 1
		sum = a/(1-r)
	else 
		sum = a/(1+r)
*/


#include<stdio.h>


int main(void)
{
	float a,r;
    float sum = 0;

    printf("Enter the first number of the G.P. series: ");
    scanf("%f",&a);

    printf("Enter the common ratio of G.P. series: ");
    scanf("%f",&r);

    if(1 > r)
         sum = a/(1-r);
    else
         sum = a/(r-1);

    printf("\nSum of the infinite G.P. series: %f",sum);

	
	return 0;
}
