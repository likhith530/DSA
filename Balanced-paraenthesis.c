#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#define stack_size 5

void push(char item, int st[],int *top)
{
    if(*top == stack_size - 1)
        printf("Overflow\n");
    else
    {
        *top = *top + 1;
        st[*top] = item;
    }
}
char pop(int st[],int *top)
{
    if(*top == -1)
        printf("Underflow\n");
    else
    {
        char temp = st[*top];
        *top = *top -1 ;
        return temp;
    }
    return 'a';
}
int match(char a , char b)
{
    if(a == '(' && b == ')')
        return 1;
    else if(a == '[' && b == ']')
        return 1;
    else if(a == '{' && b == '}')
        return 1;
    return 0;  
}
void isbalanced(char st[], int *top , char exp[])
{
    int n = strlen(exp);
    for(int i=0;i<n;i++)
    {
        if(exp[i]=='(' || exp[i] == '{' || exp[i] == '[')
            push(exp[i],st,&top);
        else //It is closing bracket
        {
            if(*top == -1)
                printf("Invalid expression , with more closing parenthesis\n");
            else // there is some bracket in top
            {
                char temp = pop(st,&top);
                if(!match(temp,exp[i]))
                    printf("Invalid expression");
            }
        }   
    }
    if(*top == -1)
        printf("Balanced parenthesis\n");
    else
        printf("Invalid expression , with more opening parenthesis\n");
}
int main()
{
    char st[stack_size];
    int *top = -1;
    char exp[10];
    printf("Enter the expression\n");
    scanf("%s", exp);
    isbalanced(st,&top,exp);
    return 0;
}