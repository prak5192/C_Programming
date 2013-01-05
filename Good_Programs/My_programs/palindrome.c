/* 
	File: palindrome.c
	brief: Gives the output as the entered string is palindrome or not.
	Date: 5th Jan 2013
	Author: Prakash
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void rec_func(char str[10], int i, int j );
int check = 0;
int main(void)
{
    char str[100];
    printf("Enter the string\n");
    scanf("%[^\n]s",str);
    printf("The string u entered is %s\n",str);
    int str_len = strlen(str);
    int i = 0;
    int j = str_len -1;
    
     
    rec_func(str,i , j);
    if(check == 0){
        printf("String is palindrome\n");
    } else {
        printf("String is not palindrome\n");
    }
    return 0;        
}

void rec_func(char str[10], int i, int j )
{
    if((i == j)|| (i > j)){
        return;
    } else {
        if(str[i] == str[j]){
            i++;
            j--;
            rec_func(str,i,j);
        }else{
            check = 1;
            return;
        }
    }
}
