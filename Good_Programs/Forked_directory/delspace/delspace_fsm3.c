/* 
 * this is a program to delete space in a string
 * you can input a string, then get a clean string
 *
 */

#include <stdio.h>

int main(void)
{
	char buf[100];
	int i = 0;
	int state = 0;

	printf("hello, del space demo\n");
	printf("please input: \n");
	gets(buf);

	printf("S: <%s>\n", buf);
	printf("O: <");

	/* main loop */
	state = 0;
	while (buf[i])
	{
		if (state != 2 && buf[i] != ' ')
		{
			state = 1;
			printf("%c", buf[i]);
			goto next;
		}

		if (state == 1 && buf[i] == ' ')
		{
			state = 2;
			goto next;
		}			

		if (state == 2 && buf[i] != ' ')
		{
			state = 1;
			printf(" ");
			printf("%c", buf[i]);
			goto next;
		}			
next:
		i++;
	}
	
	printf(">\n");
	return 0;
}
