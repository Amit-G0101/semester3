#include<stdio.h>
int logic( char *str, char *inAlpha, int transTable[2][2]);

void main()
{

    printf("Enter total states: ");
    int Q[2];
    for( int i=0; i<2; i++)
        {
            scanf("%d",&Q[i]); // 0 1
        }
        int initialState;
        printf("\nEnter Initial state: ");
        scanf("%d",&initialState);//0

        int finalState;
        printf("\nEnter final state: ");
        scanf("%d",&finalState); //1

        char inAlpha[2+1];
        printf("\nEnter the input alphabets: ");
        scanf("%s",inAlpha); // 01

        char string[100];
        printf("\nenter the string that is to be checked: ");
        scanf("%s",string);

        int transTable[2][2]={{1,1},{1,1}};
         int dfa = logic(string, inAlpha, transTable);

         if(dfa==finalState)
         {
             if(string[0]=='1'){

             printf("\nThe String is starting from input Alphabet 1");
             }
             else
             {
                printf("\nThe String is starting from input Alphabet 0");
             }
         }



}
    int logic(char *str, char *inAlpha, int transTable[2][2]){
        int dfa= -1;
        int len= 2;
        while(*str!='\0')
        {
            if(dfa==-1)
            {

                dfa=0;
            }
            for(int j=0; j<=len; j++){
                    if(*str==inAlpha[j])
                    {

                        dfa=transTable[dfa][j];
                    }

            }
            str++;
        }
        return dfa;
    }