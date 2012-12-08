/*
    Given some text lines in one string, each line is separated by ‘\n’ character.
    Print the last ten lines. If number of lines is less than 10, then print all lines.
    For help 
        http://www.geeksforgeeks.org/archives/28199
*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define PASS    0
#define FAIL    -1

int main(void){
    FILE *fd = NULL;
    int number = 10;
    int ret = PASS;
    char c ;

    fd = fopen("text.txt","r");
    if(fd == NULL){
        printf("Error in opening the file\n");
        exit(0);
    } else {
        printf("Successfully opened the file\n");
    }

    ret = fseek(fd,0,SEEK_END);
    if(ret == PASS){
        printf("File Discriptor reached to the end of the file\n");
    } else {
        printf("Problem in fseek operation\n");
    } 
    while (( number != 0 ) || ((ret = ftell(fd)) == 0)){
        fseek(fd,-2,SEEK_CUR);
        c = fgetc(fd);
        printf("%c",c);
        if(c == '\n'){
            number--;
        }
    }
    while(c != EOF){
        c = fgetc(fd);
        printf("%c",c);
    }
         
    return 0;
}


    
