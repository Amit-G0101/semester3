//lab problem 3
#include<stdio.h>

void logic(char *str,int transT[4][3]);
int isAlphabet(char ch);
int isNumber(char ch);
void information(char* str,int q0,int fstate,int transTable[4][3],int Q[]);

void main()
{

    printf("Enter total states: ");
    int Q[4];
    for( int i=0; i<4; i++)
        {
            scanf("%d",&Q[i]); 
        }
        int q0;
        printf("\nEnter Initial state: ");
        scanf("%d",&q0);

        int finalState; // for identifier
        printf("\nEnter final state: ");
        scanf("%d",&finalState);
        fflush(stdin);

        char string[100];
        printf("\nenter the string that is to be checked: ");
        fgets(string,100,stdin);
        
        int transTable[4][3]={{1,2,3},{1,1,3},{3,2,3},{3,3,3}};
        information(string,q0,finalState,transTable,Q);

        logic(string,transTable);

    }

    // 0->alpha  1->[0-9]   2->[others]
    void logic(char *str,int transT[4][3]){
    
    char *start=str;
    int i=0;
    int inputAlpha;
    int dfa=0;
    while(str[i]!='\0'){
       
        char ch= str[i];
       
        if(isAlphabet(ch)){
         
          inputAlpha=0;
          dfa=transT[dfa][inputAlpha];
         
        }
        else if(isNumber(ch)){
          inputAlpha=1;
          dfa=transT[dfa][inputAlpha];
        }
        else
        {
           inputAlpha=2;
           dfa=transT[dfa][inputAlpha];
        }
       i++;

       // when a substring has been completely processed
       if(str[i]==' ' || str[i]=='\n'){
           printf("\n");
            while(*start!=' '&& *start!='\0' && *start!='\n' ){
             printf("%c",*start);
             start++;
            }
            if(dfa==1) // q1
             printf("\tIdentifier");
            else if(dfa==2) //q2
              printf("\tNumber");
            else //q3
              printf("\tOthers");

           dfa=0; // initialize back to first state for next substring
           start=&str[i+1];// first character of next substring;
           i++;
       }
    }
        
    }
  

    int isAlphabet(char ch){
         
         if((ch>='a' && ch<='z') || (ch>='A' && ch<='Z'))
         return 1;
         else
         return 0;
     
    }
    int isNumber(char ch){
       if(ch>='0' && ch<='9')
       return 1;
       else
       return 0;
    }
  
  void information(char* str,int q0,int fstate,int transTable[4][3],int Q[]){

    printf("\nInitial states:%d",q0);
    
    printf("\nfinal states:%d",fstate);
    
    printf("\nAll states:");
    for(int i=0;i<4;i++)
    {
      
    printf("%d ",Q[i]);
    }

    printf("\nInput Alphabets:[A-Z,a-z],[0-9],[other symbols]");
    
    printf("\nInput String s:");
    while(*str!='\0')
    {
        printf("%c",*str);
        str++;
    }
    printf("\ntransition table:\n");
    
    for(int i=0;i<4;i++){
        for(int j=0;j<3;j++){
            printf("[%d]",transTable[i][j]);
        }
        printf("\n");
    }

}