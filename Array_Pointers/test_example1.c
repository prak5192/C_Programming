#include<stdio.h>

void fun(int **p){

    printf("%d\n",**p);

}

int main(void){
    int a[3][4] = {
                    1,2,3,4,
                    5,6,7,8,
                    9,0,6,7
                  };
    int *ptr;
    ptr = &a[0][0];
    fun(&ptr);
    
    return 0;
}


/*
    output = 1
*/

