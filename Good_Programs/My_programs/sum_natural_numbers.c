/* 
	a c program to find out the sum of series 1 + 2 + …. + n 
*/

#include<stdio.h>

int main(void){
	int i = 0;
	int n = 0;
	int sum = 0;
	printf("Enter the number till you want to calculate sum\n");
	scanf("%d",&n);
	for(i = 1; i<=n ; i++){
		sum = sum + i;
	}
	printf("The sum calculated using simple for loop is %d\n",sum);

	/* TODO: Calculate using recusrion */
	sum = 0;
	i = 0;

	return 0;
}
