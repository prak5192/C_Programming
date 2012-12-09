#include<stdio.h>



int main(void){
    static int a[] = {0,1,2,3,4};
    static int *p[] = {a, a+1, a+2, a+3, a+4};

    int **ptr;

    ptr = p;

    **ptr++ ; // * has more precedence than ++ operator
    printf("%d\t%d\t%d\n", ptr - p, *ptr - a, **ptr);

    *++*ptr;
    printf("%d\t%d\t%d\n", ptr - p, *ptr - a, **ptr);

    ++**ptr;
    printf("%d\t%d\t%d\n", ptr - p, *ptr - a, **ptr);

    return 0;
}


/*
    output 

    1   1   1
    1   2   2
    1   2   3
*/

