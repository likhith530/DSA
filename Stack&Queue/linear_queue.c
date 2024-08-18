#include <stdio.h>
#include<stdlib.h>
#define qsize 2 
void insert_rear(int q[], int *r , int item)
{
    if(*r==qsize - 1)
        printf("Queue Overflow\n");
    else
    {
        *r = *r +1;
        q[*r]=item;
    }
}

int delete_front(int q[] , int *r , int *f)
{
    if(*f>*r)
        printf("Queue underflow\n");
    else
    {
        int del_item = q[*f];
        *f= *f +1;
        return del_item;
    }
}

void display(int q[] , int *r , int *f)
{
    if(*f>*r)
        printf("Queue underflow\n");
    else
    {
        for(int i= *f ; i<=*r ; i++)
        {
            printf("%d\n ",q[i]);
        }
    }
}

int main()
{
    int q[qsize];
    int choice , *r=-1 , *f=0;
    int data;
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
                insert_rear(q,&r,data);
                break;
                
        case 2: printf("The deleted value is %d \n" ,delete_front(q,&r,&f));
                break;
        case 3: display(q,&r,&f);
                break;
        case 4: exit(0);
        default: printf("Wrong case entered!");
                break;
                
    }
    }
    return 0;
}