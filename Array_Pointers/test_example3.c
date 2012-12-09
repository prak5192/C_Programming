#include<stdio.h>



int main(void){
    int a[] = {1,2,3,4,5};

    int *ptr;
    ptr = &a;
    printf("%u\t%u\n", a, &a);
    printf("%u\t%u\t%u\n", a + 1 , &a + 1, ptr + 1 );
   
    
    return 0;
}


/*
    output 

    2272328 2272328
    2272332 2272348 2272332    

*/

