/* 
    Author: Prakash Ranjan 
    Date: 24th August  2012
    File: Explains the usage of variable length argument in functions. 
 
*/

/* ========== Header files Included ================ */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<stdarg.h>


/* ========== Local Maros defiend here  */

//#define debug_log(...) fprintf(stdout, __VA_ARGS__)  // new method ... Supported in C99

#define debug_log(format, args...) \
    fprintf (stdout,"%s : %s = %d : ", __FILE__,"Line num", __LINE__);\
    fprintf (stdout, format, ##args) 

/* ========== Local Functions =============*/

int average(int first, ...);


/* ========== main Function starts Here ======*/
int main(void)
{
    printf("\n=============Variable length arguments Example============\n\n");
    
    printf("The average of 10 numbers = %d\n", average(10,1,2,3,4,5,6,7,8,9,10)); 
    
    
    debug_log ("===========Testing debug log==============\n");
    return 0;
}


int average ( int first, ... )
{
    va_list ap;
    int sum = 0;
    int i = 0;
    int temp = 0; 
    va_start(ap,first);
    printf("First = %d\n", first); 
    for(i=0; i < first; i++){
        temp = va_arg(ap,int);
        printf("%d\t", temp);  
        sum = sum + temp;
    }

    va_end(ap);
    printf(" Sum = %d\n", sum);
    return (sum/first);
}

