#include<stdio.h>
#include<conio.h>

void main(){

    int character=0,lines=0,words=0;

    FILE *fptr=fopen("file.txt","r");
    char ch;
    while((ch=fgetc(fptr))!=EOF){

        if(ch==' ' || ch=='\n'){
            words++;
        }
        if(ch=='\n'){
            lines++;
        }
        character++;
    }
    if(character>0){
        words++;
        lines++;
    }
    fclose(fptr);
    printf("w=%d l=%d ch=%d",words,lines,character);
}