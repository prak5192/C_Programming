#include<stdio.h>
#include<stdlib.h>

int main(void){
    FILE *fp ;
    int size = 2*1024*1024 - 2;
    
    fp = fopen("./2_MB_file", "w+");
    if(fp == NULL){
        perror("File open problem\n");
        exit(0);
    }

    fseek(fp,size,SEEK_SET);
    
    fwrite("Hello",1,sizeof(char),fp);
    
    return 0;
}
