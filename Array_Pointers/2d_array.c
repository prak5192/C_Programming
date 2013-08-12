/* 
	A example of 2D array
*/


#include <stdio.h>
#include <stdlib.h>
#define PASS    0
#define FAIL    1
#define ROW     5
#define COL     5



int autofill(int a[ROW][COL])
{
    int i,j;
    int number = 0;
    srand(time(NULL));
    for (i =0; i < ROW ; i++){
        for (j = 0; j<COL ; j++){
            number = (rand()%100);
            a[i][j] = number;
        }
    }
}


void display(int *a, int i, int j){
    printf("\nPrinting in different style\n\n");
    for(i =0; i< ROW ; i++){
        for (j = 0 ; j<COL ; j++){
            printf("Array [%d][%d] => %d\n", i, j, *(a + i*COL + j)); 
        }
    }
}

int main(void)
{
    int a[ROW][COL];
    int i, j;
    int ret = PASS;

    ret =  autofill(a);

    printf("The array list is \n\n");
    for (i = 0 ; i < ROW ; i++){
        for (j = 0 ; j<COL ; j++){
            printf("Array [%d][%d] => %d\n",i,j,a[i][j]); 
        }
    }
    
    printf("\nPrinting the address of the arrays\n\n");
    for(i = 0; i < ROW; i++){
        printf("A[%d] 's address  => %p\n",i , a[i]);
    } 

    printf("\nPrinting in different style\n\n");
    for (i = 0 ; i < ROW ; i++){
        for (j = 0 ; j<COL ; j++){
            printf("Array [%d][%d] => %d\n",i,j,*((*(a +i)) + j)); 
        }
    }

    return ret;
}
