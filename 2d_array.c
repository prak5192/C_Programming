/* 
 * A example of 2D array
 */


#include<stdio.h>
#include<stdlib.h>
#define PASS    0
#define FAIL    1
#define ROW     5
#define COL     5



int autofill(int a[ROW][COL])
{
    int i,j;
    int number = 0;
    for (i =0; i < ROW ; i++){
        for (j = 0; j<COL ; j++){
            a[i][j] = number;
            number++; 
        }
    }
}

int main(void)
{
    int a[ROW][COL];
    int i, j;
    int ret = PASS;

    ret =  autofill(a);
    printf("The array list is \n");
    for (i = 0 ; i < ROW ; i++){
        for (j = 0 ; j<COL ; j++){
            printf("Array [%d][%d] => %d\n",i,j,a[i][j]); 
        }
    }

    return ret;
}