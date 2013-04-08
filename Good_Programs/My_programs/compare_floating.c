#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0
int compare (float a, float b){
    float precison = 0.000001;
    
    if(((a-precison)<b) &&
       ((a+precison)>b))
        return TRUE;
    else 
        return FALSE;

}

int main(void)
{
    float a = 123.234;
    float b = 673.2343;

    int ret;
    ret  = compare(a,b);
    if(ret == TRUE){
        printf("Equal\n");
    } else {
        printf("Not Equal\n");
    }
        
    return 0;
}
