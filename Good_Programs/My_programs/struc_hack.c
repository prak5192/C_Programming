/* Struct hack technique */

/*
    http://www.geeksforgeeks.org/archives/22677
    
*/

#include<stdio.h>

struct employee
{
    int     emp_id;
    int     name_len;
    char    name[0];
};

int main(void){
    printf("Sizeof struct employee is %d\n", sizeof(struct employee));
    return 0;
}
