/*
  	File: number_conversion.c
	Brief: This program is used to convert 
	       1. Decimal into binary number
	       2. Decimal into hexadecimal number
	Date: 1st March 2013
	Author: Prakash Ranjan
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void dec_2_bin (void);

int main(void){
    int choice;
    
    printf("Enter the choice\n");
    printf("1. Decimal to binary\n");
    
    scanf("%d",&choice);
    
    switch(choice) {
        case 1:
            dec_2_bin();
            printf("\n");
            break;
        default:
            printf("Please enter the corrent choice\n");
            break;
    }          
    return 0;
}


void dec_2_bin(void){
    int bin;
    int dec;
    int n;
    int r;
    int k;
    printf("Enter a Decimal number \t");
    scanf("%d",&dec);
    n=dec; 
    bin=0;
    k=1;
    while (n > 0) {
        r=n%2;
        n=n/2;
        bin=bin+r*k;
        k=k*10;
    }
    printf("\nDecimal = %d\nBinary = %d",dec , bin);
}
