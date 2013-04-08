#include<stdio.h>
#include<string.h>


void my_memmove(char const *array1, char *array2, int size);


int main(void){
    
    char array1[10];
    char array2[10];

    strcpy(array1,"prakash");
    memset(array2, 0, sizeof(array2));

    my_memmove(array1, array2, sizeof(array1));

    printf("Array 1 = %s\n", array1);
    printf("Array 2 = %s\n", array2);


    return 0;
} 

void my_memmove(char const *array1, char *array2, int size)
{
    int i;
    if (array1 == array2){
        return ;
    } else if(array1 > array2){
        for( i = 0; i < size-1; i ++){
            array2[i] = array1[i];
        }
    } else if( array1 < array2){
        for ( i = size -1 ; i>= 0; i--){
            array2[i]  = array1[i];
        }
    }
    return ;
} 

