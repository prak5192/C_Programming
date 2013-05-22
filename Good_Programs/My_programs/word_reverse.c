#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
	char str[1000];
	char rev_str[1000] = {0};
	char *ptr1 = str;
	char *ptr2 = rev_str;
	int length = 0;
	int count = 0;
	printf("Enter the sentence not contain more than 1000 characters\n");
	scanf("%[^\n]s",str);
	printf("Entered sentence is:\n%s\n",str);
	
	length = strlen(str);
	while(*ptr1 != '\0'){
		ptr1++;
	}
    
	while(length != 0){
		ptr1--;
		while(*ptr1 != ' '){
			ptr1--;
			length--;
			count++;
			if(length == 0){
				break;
			}
		}
		memcpy(ptr2,(ptr1 + 1),count);
		ptr2 = ptr2 + count;
		count = 0;
		if( length == 0){
			*ptr2 = '\0';
			break;
		}
		length--;
		*ptr2 = ' ';
		ptr2++;
	}
	printf("Reversed sentence is:\n%s\n",rev_str);
	
	return 0;
}
