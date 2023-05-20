#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define SIZE 50
void infix();
void prefix();
void postfix();
int top=-1,stack[SIZE],num_stack[50],ope_stack[50],ntop=-1,ope_top=-1;
int evalexp(char exp[]);
void calculate();
int presidence(char ch);
void push(int b)
{
   if (top==SIZE-1)
   {
      printf("\nOverflow\n\n");
   }
   else
   {
      stack[++top]=b;
   }
}
void main()
{
    int choice;
    printf("Enter the respective key \n");
    printf("1. Evaluate Infix\n");
    printf("2. Evaluate Prefix\n");
    printf("3. Evaluate Postfix\n");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1:
            infix();
            break;
        case 2:
            prefix();
            break;
        case 3:
            postfix();
            break;
        default :
            printf("Invalid choice !");
    }
}
void infix()
{
    char exp[50];
    int result=0;
    printf("Enter the Infix expression : ");
    scanf("%s",exp);
    result= evalexp(exp);
    printf("Result is %d",result);
}
int evalexp(char exp[])
{
    int i;
    char ch;
    for(i=0;i<(strlen(exp));i++)
    {
        ch=exp[i];
        if(isdigit(ch))
        {
            int num=0;
            while(isdigit(ch))
            {
                num=num*10+(ch-'0');
                i++;
                if(i<strlen(exp))
                {
                    ch=exp[i];
                }
                else
                {
                    break;
                }
            }
            i--;
            ntop++;
            num_stack[ntop]=num;
        }
        else if(ch=='(')
        {
            ope_top++;
            ope_stack[ope_top]=ch;
        }
        else if(ch==')')
        {
            while(ope_stack[ope_top]!='(')
            {
                calculate();
            }
            ope_top--;
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/')
        {
            while(!(ope_top==-1)&&(presidence(ch)<=presidence(ope_stack[ope_top])))
            calculate();
            ope_top++;
            ope_stack[ope_top]=ch;
        }
    }
    while(!(ope_top==-1))
    {
        calculate();
    }
    return (num_stack[ntop]);
}
void calculate()
{
    int k,x,y,z;
    char op;
    x=num_stack[ntop];
    ntop--;
    y=num_stack[ntop];
    ntop--;
    op=ope_stack[ope_top];
    ope_top--;
    switch (op)
    {
        case '+':
        z=x+y;
        break;
        case '-':
        z=y-x;
        break;
        case '*':
        z=x*y;
        break;
        case '/':
        if(x==0)
        {
            printf("Can't divide by zero");
            exit(1);
        }
        z=y/x;
        break;
        default :
        z=0;
    }
    ntop++;
    num_stack[ntop]=z;

}
int presidence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case ')':
    case '(':
        return 3;
    }
    return 0;
}
void prefix()
{
    char exp[50];
    int i,e,len,op1,op2,result;
    printf("Enter the prefix expression : ");
    scanf("%s",exp);
    len=strlen(exp);
    for(i=(len-1);i>=0;i--)
   {
        if((exp[i]>='0')&&(exp[i]<='9'))
       {
            e=(exp[i]-'0');
            push(e);
       }
        else
       {
            op1=stack[top];
            top=top-1;
            op2=stack[top];
            top=top-1;
            switch(exp[i])
           {
                case '+':
                    result=op1+op2;
                    break;
                case '-':
                    result=op1-op2;
                    break;
                case '*':
                    result=op1*op2;
                    break;
                case '/':
                    result=op1/op2;
                    break;
                default :
                    break;
           }
            push(result);
       }
   }
   printf("Answer of %s = %d",exp,result);
}
void postfix()
{
    char exp[50];
    int i,e,len,op1,op2,result;
    printf("Enter the postfix expression : ");
    scanf("%s",exp);
    for(i=0;i<strlen(exp);i++)
   {
        if((exp[i]>='0')&&(exp[i]<='9'))
       {
            e=(exp[i]-'0');
            push(e);
       }
        else
       {
            op2=stack[top];
            top=top-1;
            op1=stack[top];
            top=top-1;
            switch(exp[i])
           {
                case '+':
                    result=op1+op2;
                    break;
                case '-':
                    result=op1-op2;
                    break;
                case '*':
                    result=op1*op2;
                    break;
                case '/':
                    result=op1/op2;
                    break;
                default :
                    break;
           }
            push(result);
       }
}
