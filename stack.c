#include<stdio.h>
#include<stdlib.h>
#define stack_size 10
int st[10],item;
int top=-1;

void push()
{
 if(top==stack_size-1)
 printf("STACK OVERFLOW \n ");
 else
{
 top++;
 st[top]=item;
}
}

int pop()
{
 if(top==-1)
 printf("STACK UNDERFLOW \n");
 else
 {
 int del_item;
 del_item=st[top];
 top--;
 printf("The element deleted is %d",del_item);
 return del_item;
 }
}
 
void display()
{
 int i;
 if(top==-1)
 printf("Stack is empty \n");
 for(i=0;i<=top;i++)
 printf("%d \n",st[i]);
}

int main()
{
 int ch,i;
while(1)
{
 printf(" Enter 1 for push \n Enter 2 for pop \n Enter 3 for display\n");
 scanf("%d",&ch);

 switch(ch)
 {
  case 1: 
          printf("Enter the number to be added ");
          scanf("%d",&item);
          push();
          break;
  case 2: pop();
          break;
  case 3: display();
          break;
  default: exit(0);
           break;
 }
}
 return 0;
}