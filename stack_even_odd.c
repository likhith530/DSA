#include<stdio.h>
#include<stdlib.h>
#define stack_size 10
int top=-1;
int j=0,k=0;
int st[stack_size];
int odd_st[stack_size];
int even_st[stack_size];
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
    // for(int i=0;i<=top;i++)
    // {
    //     printf("%d \n",st[i]);
    // }
    for(int i=0;i<j;i++)
    {
        printf("%d \n",even_st[i]);
    }
    for(int i=0;i<k;i++)
    {
        printf("%d \n",odd_st[i]);
    }

    }
}
void segregate()
{
    for(int i=0;i<=top;i++)
    {
        if(st[i]%2==0){
            even_st[j]=st[i]; 
            j++;}
        else{
            odd_st[k]=st[i];
            k++;}
    }
}
void combine()
{
    int stk[j+k];
    int l=0;
    for(int i=0;i<j;i++)//j-top
    {
        stk[l++]=odd_st[i];
    }
    for(int i=0;i<k;i++)//k-top
    {
        stk[l++]=even_st[i];
    }
    for(int i=0;i<l;i++)
    {
        printf("%d \n",stk[i]);
    }

}
int main()
{
int ch,item;
while(1)
{
 printf("Enter 1 for push \nEnter 2 for pop \nEnter 3 for display\nEnter 4 to segregate\nEnter 5 to exit\n");
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
  case 4:segregate();
         break;
  case 5: exit(0);
           break;
    case 6: combine();break;
  default:printf("Wrong case entered!");
 }
}
 return 0;
}