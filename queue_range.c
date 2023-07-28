//Consider the range to be from 1 to 10 (both inclusive).
// Input Queue: 13983, 10080, 7113, 2520, 2500 (front - rear)
//  Output Queue: 10080, 2520 (front-rear)
#include <stdio.h>
#include<stdlib.h>
#define qsize 10 
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


void display(int q[] , int *r , int *f,int m,int n)
{
    int flag=1,j;
    if(*f>*r)
        printf("Queue underflow\n");
    else
    {
        for(int i= *f; i<=*r ;i++)
        {
         for(j=m;j<=n ;j++)
        {
            if(q[i]%j!=0)
                flag=0;
        }
        if(flag=1)
            printf("%d\n",q[i]);
    }
}
}

int main()
{
    int q[qsize];
    int choice , *r=-1 , *f=0;
    int data;
    int m,n;
     printf("Enter the range\n");
    scanf("%d%d",&m,&n);
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
        case 3: display(q,&r,&f,m,n);
                break;
        case 4: exit(0);
        default: printf("Wrong case entered!");        
    }
    }
    return 0;
}