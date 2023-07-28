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

struct Node *sort(struct Node *first)
{
    struct Node *p=first;
    struct Node *q;
    int temp;
    if(first==NULL)
    {
        printf("Nothing to display!\n");
        return NULL;
    }
    while(p->next!=NULL)
    {
        q=p->next;
        while(q!=NULL)
        {
        if(p->value>q->value)//ascending order sorting
        {
            temp=p->value;
            p->value=q->value;
            q->value=temp;
        }
        q=q->next;
        }
        p=p->next;
    }
    return first;
}

struct Node *reverse(struct Node *first)
{
    struct Node *p=first;
    struct Node *q=NULL;
    struct Node *r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
    return first;
}

int main()
{
    struct Node *first =NULL;
    int ch,data,index;
    while(1)
    {
    printf("Enter 1 to insert at the end. \nEnter 2 to display.\nEnter 3 to sort\nEnter 4 to reverse\nEnter 5 to exit!\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the value to be inserted at the end:\n");
            scanf("%d",&data);
            first=insertAtEnd(first,data);
            break;

            case 2:
            display(first);
            break;

            case 3:
            first=sort(first);
            break;

            case 4:
            first = reverse(first);
            break;

            case 5:
            exit(0);
            break;

            default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}