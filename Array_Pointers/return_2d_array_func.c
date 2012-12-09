/* 
 * A example of 2D array
 */


#include<stdio.h>
#include<stdlib.h>
#define PASS    0
#define FAIL    1
#define ROW     3
#define COL     4


int * fun1(void){
    static int a[ROW][COL] = {
                                1,2,3,4,
                                5,6,7,8,
                                9,0,1,6
                             };
    return (int*) a;
}


int (*fun2())[COL]{
    static int b[ROW][COL] = {
                                2,3,4,5,
                                9,2,3,4,
                                3,4,5,6
                             };


    return b;
}

int (*fun3())[ROW][COL]{
    static int c[ROW][COL] = {
                                6,3,4,5,
                                7,2,3,4,
                                8,4,5,6
                             };

    return (int(*)[ROW][COL])c;
}

int main(void)
{
    int *a;
    int i,j;

    int ( *b )[COL];
    int *p;

    int ( *c )[ROW][COL];

    a =fun1();

    printf("Printing the Array 1\n");
    for(i = 0; i<ROW ; i++ ){
        for(j =0; j<COL ;j++){
            printf("%d",*(a + i*COL + j));
        }
        printf("\n");
    }
    
    printf("\n");
   
    
    b = fun2();
    printf("Printing the Array 2\n");
    for(i = 0; i<ROW ; i++ ){
        p = b + i;
        for(j =0; j<COL; j++){ 

            printf("%d",*(p));
            p++;
        }
        printf("\n");
    }
    
    printf("\n");
   

    c = fun3();
    
    printf("Printing the Array 3\n");

    for(i = 0; i<ROW ; i++ ){
        for(j =0; j<COL ;j++){

            printf("%d",(*c)[i][j]);
        }
        printf("\n");
    }
    
    printf("\n");
   
    return 0;
}


