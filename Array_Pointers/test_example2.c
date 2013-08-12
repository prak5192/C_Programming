#include<stdio.h>



int main(void){
    int a[3][4] = {
                    1,2,3,4,
                    5,6,7,8,
                    9,0,6,7
                  };
    int *ptr;
    ptr = (int *)a;
    
    printf("%p\n",a[2]);
    printf("%d\n",ptr[2]);
    printf("%d\n",*(ptr + 2));
	ptr++;
	ptr++;
	ptr++;
	ptr++;
	ptr++;
    printf("%d\n",*ptr);
    
    
    return 0;
}


/*
    output 

    2272332
    3
    3

*/

