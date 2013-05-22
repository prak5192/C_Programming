#include<stdio.h>
#include<stdlib.h>

int main(void){
    int x = 10, y = 22;
    char *p = NULL;
    unsigned int z = (unsigned int) & ( ( &(p[x]) )[y] );
    printf("%u\n", z);
    return 0;
}
