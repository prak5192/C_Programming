/* Thsi peice of code will print the file contents on the terminal */



#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int main(int argc, char * argv[]){
    printf("This program is used to print the file content on the terminal\n");
    char c;
    FILE *fp;

    if(argc < 2 ){
        printf("Usage: ./execuatbale <filename>\n");
        return 0;
    }

    fp = fopen(argv[1], "r+");
    if(fp == NULL){
        printf("Error in opening the file => %s\n",argv[1]);
        exit(1);
    }

    while(( c = fgetc(fp)) != EOF){
        printf("%c",c);
    }
    return 0;
}

