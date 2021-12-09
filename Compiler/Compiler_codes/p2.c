#include <stdio.h>
#include <conio.h>
 int nS;
 int nIA;
 
void information(char* str,char *inAlpha,int q0,int fstate,int transTable[nS][nIA],int Q[],int nIA,int nS);
int logic(char *str, char *inAlpha, int transT[nS][nIA],int nIA);
void main()
{
   
    printf("how many states: ");
    scanf("%d",&nS);
    
     int Q[nS];
    printf("\nEnter states: ");
    for(int i=0;i<nS;i++){
        scanf("%d",&Q[i]);
    }
    
    
    printf("\nhow many input Alphabets: ");
    scanf("%d",&nIA);

    char inputAlpha[nIA+1];
    printf("\nenter inputAlphabets:");
    scanf("%s",inputAlpha);

    
    int q0;
    printf("\nenter Initial state:");
    scanf("%d",&q0);
    
    int fstate;
    printf("\nenter final state:");
    scanf("%d",&fstate);
    
    int transTable[nS][nIA];
    printf("\nEnter values in transition table\n");
    for(int i=0;i<nS;i++){
        for(int j=0;j<nIA;j++){
            scanf("%d",&transTable[i][j]);
        }
    }
    
    char string[100];
    printf("enter the string:");
    scanf("%s", string);
    
    information(string,inputAlpha,q0,fstate,transTable,Q,nIA,nS);
    int dfa = logic(string, inputAlpha, transTable,nIA);

    if (dfa == fstate)
    {
        printf("String is Accepted");
    }
    else
    {
        printf("String is rejected");
    }
}
int logic(char *str, char *inAlpha, int transT[nS][nIA],int nIA)
{

    int i = 0;
    int dfa = -1;

    while (*str != '\0')
    {

        if (dfa == -1)
        {
            dfa = 0;
        }

        for (int j = 0; j < nIA; j++)
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
void information(char* str,char *inAlpha,int q0,int fstate,int transTable[nS][nIA],int Q[],int nIA,int nS){

    printf("\nInitial states:%d",q0);
    
    printf("\nfinal states:%d",fstate);
    
    printf("\nAll states:");
    for(int i=0;i<nS;i++)
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
    
    for(int i=0;i<nS;i++){
        for(int j=0;j<nIA;j++){
            printf("[%d]",transTable[i][j]);
        }
        printf("\n");
    }

}