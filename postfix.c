#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
double compute(char symbol, double op1, double op2)
{
switch(symbol)
{
case'+':return op1+op2;
case'-':return op1-op2;
case'*':return op1*op2;
case'/':return op1/op2;
case'$':
case'^':return pow(op1,op2);
default:return 0;
}
}
void main()
{
char postfix[20];
int i;
char symbol;
int top=-1;
double op1,op2,res;
double s[20];
printf("enter the postfix expression\n");
scanf("%s",postfix);
for(i=0;i<strlen(postfix);i++)
{
symbol=postfix[i];
if(is digit(symbol))
{
s[++top]=symbol-'0';
}
else
{
op2=s[top--];
op1=s[top--];
res=compute(symbol,op1,op2);
s[++top]=res;
}
}
res=s[top--];
printf("the result is %f",res);
getch();
