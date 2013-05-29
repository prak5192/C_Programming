/* Program for atoi function */

#include<stdio.h>

int myatoi(const char *string);

int main(int argc, char* argv[])
{
    printf("\n%d\n", myatoi(argv[1]));
    return(0);
}

int myatoi(const char *string)
{
    int j = 0;
    int i;
    for(i=0; string[i] >= '0' && string[i] <='9'; i++)
    {
        j=(j<<3) + (j<<1) + (string[i] - '0');
    }
    return(j);
}
