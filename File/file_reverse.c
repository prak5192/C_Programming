/* Thsi peice of code will print the file contents on the terminal */

/* Showing usage of the folowoing commands 
1. fopen()
2. fclose()
3. fgetc()
4. putchar()
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char * argv[]){
    printf("This program is used to reverse a content of one file and wite to other file.\n");
    char c;
    FILE *fp1;
    FILE *fp2;

    if(argc < 3 ){
        printf("Usage: ./execuatbale <Filename1> <Filename2>\n");
		printf("Filename1: The source file\nFilename2: The destination file\n");
        return 0;
    }

    fp1 = fopen(argv[1], "r+b");
    if(fp1 == NULL){
        printf("Error in opening the file => %s\n",argv[1]);
        exit(1);
    }
	fp2 = fopen(argv[2], "w+");
    if(fp2 == NULL){
        printf("Error in opening the file => %s\n",argv[2]);
        exit(1);
    }

	fseek(fp1,0,SEEK_END);
	long int pos = ftell(fp1);
	printf("%ld\n", pos);
/*
    while(1){
		//fseek(fp1,-2,SEEK_CUR);
		c = fgetc(fp1);
		if( c == EOF){
			break;
		} 
		printf("| %c\t",c);
		sleep(1);
		fputc(c,fp2);
		if( ftell(fp1) == 0){
			printf("Reverse of the file is Over\n");
			break;
		}
    }
*/
    fclose(fp1);
    fclose(fp2);
    return 0;
}
