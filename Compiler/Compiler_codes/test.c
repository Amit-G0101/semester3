#include <stdio.h>
#include <conio.h>
#include<string.h>
void information(char* str,char *inAlpha,int q0,int fstate,int transTable[5][2],int Q[]);
int logic(char *str, char *inAlpha, int transT[5][2]);
void main()
{
    
    int Q[5] = {0,1,2,3,4}; // states

    char inputAlpha[2+1]; // input alphabets
    printf("\nenter inputAlphabets:");
    scanf("%s",inputAlpha);

    
    int q0; // intial states;
    printf("\nenter Initial state:");
    scanf("%d",&q0);
    
    int fstate; // finalstates
    printf("\nenter final state:");
    scanf("%d",&fstate);

    int transTable[5][2] = {{4, 1}, {4, 2}, {3, 2}, {3, 2}, {4,4}};

    char string[100];

    printf("enter the string:");
    scanf("%s", string);
    
    information(string,inputAlpha,q0,fstate,transTable,Q);
    int dfa = logic(string, inputAlpha, transTable);

    if (dfa == fstate)
    {
        printf("Accepted");
    }
    else
    {
        printf("rejected");
    }
}
int logic(char *str, char *inAlpha, int transT[5][2])
{

    int i = 0;
    int dfa = -1;
    int len = 2; // length of input alphabets

    while (*str != '\0')
    {

        if (dfa == -1)
        {
            dfa = 0;
        }

        for (int j = 0; j < len; j++)
        {
            if (*str == inAlpha[j])

            {
                dfa = transT[dfa][j];  
            }
        }
    
        str++;
    }

    return dfa;
}
void information(char* str,char *inAlpha,int q0,int fstate,int transTable[5][2],int Q[]){

    printf("\nInitial states:%d",q0);
    
    printf("\nfinal states:%d",fstate);
    
    printf("\nAll states:");
    for(int i=0;i<5;i++)
    {
      
    printf("%d ",Q[i]);
    }

    printf("\nInput Alphabets:");
    while(*inAlpha!='\0')
    {
        printf("%c",*inAlpha);
        inAlpha++;
    }
    printf("\nInput String s:");
    while(*str!='\0')
    {
        printf("%c",*str);
        str++;
    }
    printf("\ntransition table:\n");

    for(int i=0;i<5;i++){
        for(int j=0;j<2;j++){
            printf("%d ",transTable[i][j]);
        }
        printf("\n");
    }

}