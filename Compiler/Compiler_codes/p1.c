#include <stdio.h>
void main()
{

    FILE *fptr;
    int words,lines,characters;
    words=characters=0;
    lines=0;
    char path[100];
    printf("enter path/filename:");
    scanf("%s",path);
    fptr = fopen(path, "r");

    if (fptr!=NULL)
    {
        int ch;
        while( (ch=fgetc(fptr)) !=EOF)
        {
             characters++;

            if(ch==' '|| ch=='\n')
            {
                words++;
                characters--;
                
            }
            if(ch=='\n')
            {
                lines++; 
                
            }
           
        }
        

        if(characters>0)
        {
            lines++;
            words++;

        }
      
    }

    else
        printf("\nFile Doesnot exist");
    
    fclose(fptr);
    printf("\nNumber of characters:%d\n",characters);
    printf("Number of words:%d\n",words);
    printf("Number of lines:%d\n",lines);
    
    
}
