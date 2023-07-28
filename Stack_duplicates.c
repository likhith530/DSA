//  Create a stack with list of integer elements.
// The stack elements given by the user should be in ascending
// order and might contain duplicate elements as given in the sample
// input. Write a generic program to remove all duplicate elements
// from this sorted stack. Given a stack of whole numbers. 
// Write a program to return a new stack which contains the values 
// without duplicate.
// Example:
// Input stack: 10 10 20 20 30 30 30 40 50 
// Output stack: 10 20 30 40 50

#include<stdio.h>
#include<stdlib.h>
#define stack_size 10
int top=-1;
int st[stack_size];
void push(int data)
{
    if(top==stack_size-1)
        printf("Stack overflow!\n");
    else
    st[++top]=data;
}
int pop()
{
    if(top==-1)
        printf("Stack underflow!\n");
    else
    return st[top--];
}
void display()
{
    if(top==-1)
    {
        printf("No elements to display\n");
    }
    else{
    for(int i=0;i<=top;i++)
    {
        printf("%d ",st[i]);
    }
    }
}
void remove_duplicates()
{
    int num;
    if(top==-1)
        printf("No numbers only..\n");
    
    for(int i=0;i<stack_size;i++)
    {
        for(int j=i+1;j<stack_size;j++)
        {
            if(st[i]==st[j])
            {
                st[j]=st[j+1];
            }
        }
    }
}
int main()
{
int ch,item;
while(1)
{
 printf("Enter 1 for push \nEnter 2 for pop \nEnter 3 for display\nEnter 4 to remove Duplicates\nEnter 5 to exit\n");
 scanf("%d",&ch);

 switch(ch)
 {
  case 1: 
          printf("Enter the number to be added ");
          scanf("%d",&item);
          push(item);
          break;
  case 2: printf("%d \n",pop());
          break;
  case 3: display();
          break;
  case 4:remove_duplicates();
         break;
  case 5: exit(0);
           break;
  default:printf("Wrong case entered!");
 }
}
 return 0;
}
