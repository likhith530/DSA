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
    i=0;
    if(first==NULL)
    printf("Nothing to display!\n");
    else
    {
    struct Node *ptr=first;
    while(ptr)
    {
        printf("Element %d is %d\n",(i+1),(ptr->value));
        ptr=ptr->next;
        i++;
    }
}
}
struct Node *deleteAtFirst(struct Node *first)
{ 
    if(first==NULL)
    {
        printf("Nothing to be deleted!\n");
    }
    else
    {
    struct Node *temp; 
    temp = first;  
    int data = first->value;
    printf("The deleted item is %d \n",data);
    first=first->next;
    free(temp);
    return first;
    }  
}
struct Node *delete_specific_val(struct Node *first,int data)
{
    struct Node *p=first;
    struct Node *q=NULL;
    if(first==NULL)
    {
        printf("Cannot delete , Linked list is empty\n");
    }
    while(p)
    {
        if(p->value==data)
        {
            q->next=p->next;
            p->next=NULL;
            printf("The deleted item is %d \n",p->value);
            free(p);
        }
        else
        {
            printf("\nValue not found!Open eyes and enter next time!\n");
            break;
        }
        q=p;
        p=p->next;
    }
    return first;
}

struct Node *DeleteAtEnd(struct Node* first)
{
    if(first==NULL)
        return NULL;
    else
    {
        struct Node*p = first;
        struct Node*q = NULL;
        while(p->next!=NULL)
        {
            q=p;
            p=p->next;
        }
        q->next=NULL;
        printf("\nThe deleted value is %d\n",p->value);
        free(p);
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
    int ch,data,index;
    while(1)
    {
    printf("Enter 1 to delete at the beginning.\nEnter 2 to delete a specific value.\nEnter 3 to display.");
    printf("\nEnter 5 to delete at end.\nEnter 6 to insert at the end.\nEnter 7 to exit!\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                first=deleteAtFirst(first);
            break;

            case 2:
            printf("Enter the index where the value to be deleted:\n");
            scanf("%d",&data);
            first=delete_specific_val(first,data);
            break;

            case 3:
            display(first);
            break;

            case 5:
                first = DeleteAtEnd(first);
                break;

            case 6:
            printf("Enter the value to be inserted at the end:\n");
            scanf("%d",&data);
            first=insertAtEnd(first,data);
            break;

            case 7:
            exit(0);

            default:
            printf("Invalid choice!\n");
        }
    }
    return 0;
}