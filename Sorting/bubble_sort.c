/* Sorting an array using bubble sort */

#include<stdio.h>

void bubble(int a[],int n)
{
    int i,j,t;
    for(i=n-2;i>=0;i--)
    {
        for(j=0;j<=i;j++)
        {
            if(a[j]>a[j+1])
            {
                t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }
}


void main()
{
    int a[100],n,i;
    printf("\n\n Enter integer value for total no.s of elements to be sorted: ");
    scanf("%d",&n);

    for( i=0;i<=n-1;i++)
          { printf("\n\n Enter integer value for element no.%d : ",i+1);
            scanf("%d",&a[i]);
          }

     bubble(a,n);

     printf("\n\n Finally sorted array is:\n ");
     for( i=0;i<=n-1;i++)
        printf("%3d",a[i]);

     printf("\n\n");
} 

