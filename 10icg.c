#include<stdio.h>
#include<string.h>
char expr[20];
char temp='Z';

void replace(int pos)
{
    expr[pos-1]=temp;
    temp--;
    for(int i=pos;expr[i]!='\0';i++)//shift left
        expr[i]=expr[i+2];
}
void main()
{
    char operator1='*',operator2='/';
    int flag=0;
    printf("enter the exprerssion = ");
    scanf("%s",expr);
    while(strlen(expr)>3)//till the expression RHS is reduced to a single character
    {
        flag=0;
        for(int i=0;expr[i]!='\0';i++)
        {
            if(expr[i]==operator1||expr[i]==operator2)
            {
                printf("%c=%c%c%c\n", temp, expr[i - 1], expr[i], expr[i + 1]);
                replace(i);
                flag=1;
                break;
            }
        }
        if(flag!=1)
        {
            operator1='+';
            operator2='-';
        }
        else
        {
            operator1='*';
            operator2='/';
        }
    }
    printf("%s\n",expr);
}