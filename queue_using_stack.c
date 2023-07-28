#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size,top;
    int *arr;
};
//To push values
void push(struct stack *sp, int data)
{
    if(sp->top==sp->size-1)
    printf("Stack overflow condition!\n");
    else
    {
        sp->top++;
        sp->arr[sp->top]=data;
    }
}
//To pop values
int pop(struct stack *sp)
{
    int n;
    if(sp->top==-1)
    printf("Stack under flow condition!\n");
    else
    {
        n=sp->arr[sp->top];
        sp->top--;
        return n;
    }
}
//To check if the stack is empty
int isEmpty(struct stack *sp)
{
   if(sp->top==-1)
   return 1;
   else 
   return 0;
}
//To check if the stack is full
int isFull(struct stack *sp) 
{
   if(sp->top==sp->size-1) 
   return 1;
   else
   return 0;
}
//To display values
void display(struct stack *sp)
{
    if(isEmpty(sp))
    printf("Nothing to display!\n");
    else
    {
        int i;
    for(i=0;i<=sp->top;i++)
        printf("Element %d is %d\n", (i+1), sp->arr[i]);
        
    }
}
void enqueue(struct stack *sp1, int data)
{
    if(isFull(sp1))
    printf("The queue is full1\n");
    else
    {
        push(sp1,data);
    }
}
int dequeue(struct stack *sp1,struct stack *sp2)
{
    int del_item=-1;
    if(isFull(sp2))
    printf("stack 2 is full!\n");
    else
    {
        while(!isEmpty(sp1))
        {
            push(sp2,pop(sp1));
        }
        del_item=pop(sp2);
    }
    while(!isEmpty(sp2))
    {
        push(sp1,pop(sp2));
    }
    return del_item;
}
void main()
{
    int c,data;
    struct stack * sp1=(struct stack*)malloc(sizeof(struct stack));
    struct stack * sp2=(struct stack*)malloc(sizeof(struct stack));
    sp1->size=100;
    sp1->top=-1;
    sp1->arr=(int *)malloc(sp1->size*sizeof(int));
    sp2->size=100;
    sp2->top=-1;
    sp2->arr=(int *)malloc(sp2->size*sizeof(int));
    while(1)
    {
        printf("Enter 1 to insert values.\nEnter 2 to delete values.\nEnter 3 to display values.\nEnter 4 to exit!\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            printf("Enter the value to be inserted:\n");
            scanf("%d",&data);
            enqueue(sp1,data);
            break;

            case 2:
            printf("The deleted element is %d.\n",dequeue(sp1,sp2));
            break;

            case 3:
            display(sp1);
            break;

            case 4:
            exit(0);

            default:
            printf("You have entered a wrong choice!\n");
        }
    }
}