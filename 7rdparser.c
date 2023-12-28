#include<stdio.h>
#include<string.h>

/*
S->aBcD
B->d|e 
D->f|$

accepted:
adcf
aec$

rejected:
afbc


*/
char str[20];
int cursor=0;
int valid=1;
void B()
{
	if(str[cursor]=='d')
		cursor++;
	else if(str[cursor]=='e')
		cursor++;
	else 
		valid=0;
}
void D()
{
	if(str[cursor]=='f')
		cursor++;
	else if(str[cursor]=='$')
		cursor++;
	else
		valid=0;
}
void S()
{
	if(str[cursor]=='a')
	{
		cursor++;
		B();
		if(str[cursor]=='c')
		{
			cursor++;
			D();
		}
		else
			valid=0;
	}
	else
		valid=0;
}

void main()
{
	printf("enter the input string = ");
	scanf("%s",str);
	S();
	if(valid==1&&strlen(str)==cursor)
		printf("String accepted!");
	else
		printf("Not accepted");
	printf("\nProgram done by Ashwin Saji\nUid:U2003220\nRno:45\n");
}
