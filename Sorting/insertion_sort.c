/* Program to sort one array using insertion sort */

#include<stdio.h>

void insertion(int a[],int n)
{
    int i,j,x,k;
    for(i=1;i<=n-1;i++)
    {
        j=i;
        x=a[i];
        while(a[j-1]>x && j>0)
        {
            a[j]=a[j-1];
            j=j-1;
        }
        a[j]=x;
        printf("\n\n The array after pass no.%d: ",i);
        for(k=0;k<=n-1;k++)
            printf("%4d",a[k]);
     }
}

void main()
{

    int a[1000],n,i;
    printf("\n\nEnter an integer value for total no.s of elements to be sorted: ");
    scanf("%3d",&n);

    for(i=0;i<=n-1;i++)
    {
        printf("\n\nEnter an integer value for element no.%d: ",i+1);
        scanf("%4d",&a[i]);
    }

    insertion(a,n);

    printf("\n\n\nFinally sorted array is : ");
    for(i=0;i<=n-1;i++)
        printf("%4d",a[i]);

    printf("\n\n");
}

