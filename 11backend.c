#include <stdio.h>
#include <stdio.h>
#include <string.h>
void main() 
{
    char str[20], opr[10];
    char icode[10][20];
    int n;
    printf("enter the no of lines of intermediate code\n");
    scanf("%d",&n);
    printf("Enter the set of intermediate code\n");
    for(int i=0;i<n;i++)
        scanf("%s", icode[i]);
    printf("Assembly code generation");
    for(int i=0;i<n;i++)
    {
        strcpy(str, icode[i]);
        switch (str[3])//check the operator
        {
            case '+':
                strcpy(opr,"ADD");
                break;
            case '-':
                strcpy(opr,"SUB");
                break;
            case '*':
                strcpy(opr,"MUL");
                break;
            case '/':
                strcpy(opr,"DIV");
                break;
        }
        printf("\nMOV %c,R%d",str[2],i);
        printf("\n%s %c,R%d",opr,str[4],i);
        printf("\nMOV R%d,%c",i,str[0]);
    }
}