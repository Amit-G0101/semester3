#include<stdio.h>
void main(){

FILE *fptr;

fptr=fopen("file.txt","r");

if(fptr==NULL){
    printf("hello");
    }
    
else
printf("hello2");
}