#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int value;
    struct Node *next;
};

void display(struct Node *first)
{
    int i;
    struct Node *ptr=first;
    i=0;
    if(first==NULL)
    printf("Nothing to display!\n");
    else
    {
    while(ptr!=NULL)
    {
        printf("Element %d is %d\n",(i+1),(ptr->value));
        ptr=ptr->next;
        i++;
    } 
    }
}

struct Node *deleteAtFirst(struct Node *first)
{
    struct Node *temp; 
    if(first==NULL)
    {
        printf("Nothing to be deleted!");
    }
    else
    {
    temp = first;  
    int data = first->value;
    printf("The deleted item is %d \n",data);
    first=first->next;
    free(temp);
    return first;
    }  
}

struct Node *insertAtEnd(struct Node *first,int data)
{
   
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->value=data;
    ptr->next=NULL;
    if(first==NULL)
    {
        first=ptr;
        return first;
    }
    else
    {
    struct Node *p=first;
    while(p->next!=NULL)
    {
        p=p->next;
    }
   
    ptr->next=NULL;
    p->next=ptr;
    return first;
    }
}

int main()
{
    struct Node *first =NULL;
    int ch,data;
    while(1)
    {
        printf("Enter 1.Enqueue \n2.Dequeue\n3.Display\n4.Exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the value to be inserted:\n");
            scanf("%d",&data);
            first=insertAtEnd(first,data);
            break;
            case 2:
            first=deleteAtFirst(first);
            break;
            case 3:
            display(first);
            break;
            case 4:exit(0);
            default:printf("Wrong case entered!\n");
        }
    }
    return 0;
}