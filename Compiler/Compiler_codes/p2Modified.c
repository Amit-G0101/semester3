#include <stdio.h>
#include <conio.h>
void isAccepted(int dfa, int final[],int n);
void main()
{
//----------states-------//
    int noST;
    printf("Enter no. of States Q:");
    scanf("%d", &noST);

    int Q[noST];

    
    printf("\nEnter States:");
    for (int i = 0; i < noST; i++)
    {

        scanf("%d", &Q[i]);
    }

    //---------Input Alphabets----//

    int noAlpha;
    printf("\nEnter Number of input alphabets:");
    scanf("%d", &noAlpha);
    fflush(stdin);

    int x=0;
    char INalpha[noAlpha];
    printf("\nEnter input alphabets:");
    for(int i=0;i<noAlpha;i++){
        scanf("%c",&INalpha[i]);
        fflush(stdin);
    }
    printf("%s",INalpha);

    //---------Initial state-------//

    int q0;
    printf("\nenter Initial State:");
    scanf("%d", &q0);

    //------final states-----//
    int noF;
    printf("\nEnter the no. of final states: ");
    scanf("%d", &noF);
    int final[noF];
    printf("\nEnter the %d final states : ", noF);
    for (int i = 0; i < noF; i++)
        scanf("%d", &final[i]);

    //---------transition Matrix------//
    printf("\nenter transition table:");
    int transition[3][2]={{1,2},{3,1},{2,2}};
 /*   for (int i = 0; i < noST; i++)
    {
        for (int j = 0; j < noAlpha; j++)
        {

            scanf("%d", &transition[i][j]);
        }
    }
 */
    //----input String-----//
    fflush(stdin);
    char str[100];
    printf("\nenter input string");
    

    //--------------logic-------------//
    int i = 0;
    int dfa = -1;
    while (str[i] != '\0')
    {

        if (dfa == -1)
        {
            dfa = q0;
        }
        for (int j = 0; j < noAlpha; j++)
        {

            if (str[i] == INalpha[j])
            {
                dfa = transition[dfa][j];
            }
        }
        i++;
    }
    isAccepted(dfa,final,noF);
}

void isAccepted(int dfa, int final[],int n){

for(int i=0;i<n;i++){
    if(dfa==final[i]){
        printf("Accepted");
        return;
    }
}
printf("\nNot accepted");
}

