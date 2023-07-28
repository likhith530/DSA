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
struct Node *insertAtFirst(struct Node *first,int data)
{
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->value=data;
    if(first==NULL)
    {
        first=ptr;
       return first;
    }
    else
    {
    ptr->next=first;
    first=ptr;
    return first;
    }
   
}
struct Node *insertInBet(struct Node *first,int data,int index)
{
    int i=0;
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->value=data;
    if(first==NULL)
    {
        first=ptr;
        return first;
    }
    else
    {
    struct Node *p=first;
   
    while(i!=index-1)
    {
        p=p->next;
        i++;
    }
   
    ptr->value=data;
    ptr->next=p->next;
    p->next=ptr;
    return first;
   }
}
struct Node *insertAtEnd(struct Node *first,int data)
{
   
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->value=data;
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
    printf("Enter 1 to insert at the beginning.\nEnter 2 to insert in between.\nEnter 3 to insert at the end. \nEnter 4 to display.\nEnter 5 to sort\nEnter 6 to reverse\nEnter 7 to exit!\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the value to be inserted at the beginning:\n");
            scanf("%d",&data);
            first=insertAtFirst(first,data);
            break;

            case 2:
            printf("Enter the value to be inserted:\n");
            scanf("%d",&data);
            printf("Enter the index where the value has to be inserted:\n");
            scanf("%d",&index);
            first=insertInBet(first,data,index);
            break;

            case 3:
            printf("Enter the value to be inserted at the end:\n");
            scanf("%d",&data);
            first=insertAtEnd(first,data);
            break;

            case 4:
            display(first);
            break;

            case 5:
            first=sort(first);
            break;

            case 6:
            first = reverse(first);
            break;

            case 7:
            exit(0);
            break;

            default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}