#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define size 20
char st[size];
int top = -1;
void push(int item){
    if(top == size - 1)
        printf("Overflow\n");
    else
        st[++top] = item;
}

int pop()
{
    if(top == -1)
        printf("Underflow\n");
    else
        return st[top--];
}

int main()
{
    char exp[20];
    printf("Enter The expression: \n");
    scanf("%s",exp);
    int n1,n2; //To get pop val
    int n3; // to store soln
    int num; // to push
    char *e;
    e = exp;
    while(*e != '\0')
    {
        if(isdigit(*e))
        {
            num = *e - 48;
            push(num);
        }
        else //It is symbol
        {
            n1 = pop();
            n2 = pop();
            switch(*e)
            {
                case '+':   n3 = n1 + n2;
                        break;
                case '-': n3 = n1 - n2;
                        break;
                case '*': n3 = n1 * n2;
                        break;
                case '/': n3 = n1/n2;
                        break;

            }
            push(n3);
        }
        e++;
    }
    printf("%d",pop());

    return 0;
}