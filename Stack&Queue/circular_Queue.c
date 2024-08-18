#include <stdio.h>
#include<stdlib.h>
#define qsize 3 
void insert_rear(int q[], int *r , int item , int *count)
{
    if(*count==qsize)
        printf("Queue Overflow\n");
    else
    {
        *r = (*r +1);
        *r=*r%qsize;
        q[*r]=item;
        *count +=1;
    }
}

int delete_front(int q[] , int *r , int *f , int *count)
{
    if(*count == 0)
        printf("Queue underflow\n");
    else
    {
        int del_item = q[*f];
        *f= (*f +1);
        *f=*f%qsize;
        *count -=1;
        return del_item;
    }
}

void display(int q[] , int *f,int *r , int *count)
{
    int temp=*f;
    if(*count == 0)
        printf("Queue underflow\n");
    else
    {
        for(int i= 0 ; i<*count ; i++)
        {
            printf("%d\n ",q[temp]);
            temp =temp+1;
            temp = temp%qsize;
        }
    }
}

int main()
{
    int q[qsize];
    int choice , *r=-1 , *f=0;
    int data,count=0;
    while(1)
    {
    printf("Enter 1 for inserting into the Queue \nEnter 2 for deleting from the Queue \nEnter 3 Displaying the Queue\nEnter 4 for exit\n");
    printf("Enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: 
                printf("Enter the value to be inserted\n");
                scanf("%d",&data);
                insert_rear(q,&r,data,&count);
                break;
                
        case 2: printf("The deleted value is %d \n" ,delete_front(q,&r,&f,&count));
                break;
        case 3: display(q,&f,&r,&count);
                break;
        case 4: exit(0);
        default: printf("Wrong case entered!");
                break;
                
    }
    }
    return 0;
}