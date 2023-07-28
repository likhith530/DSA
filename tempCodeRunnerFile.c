#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int value;
    struct Node *next;
};

void display(struct Node *first1)
{
    int i;
    struct Node *ptr=first1;
    i=0;
    if(first1==NULL)
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

struct Node *concatanate(struct Node *first1,struct Node *first2)
{
    if(first1==NULL)
        return first2;
    if(first2==NULL)
        return first1;
    if(first1==NULL && first2==NULL)
        return NULL;
    else
    {
        struct Node*p=first1;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=first2;
        return first1;
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

int main()
{
    struct Node *first1=NULL;
    struct Node *first2=NULL;
    int ch,data,index;
    while(1)
    {
    printf("Linked LIST 1: \n");
    printf("\nEnter 1 to insert at the end.\nEnter 2 to exit\n");
    scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the value to be inserted at the end:\n");
            scanf("%d",&data);
            first1=insertAtEnd(first1,data);
            break;

            case 2:
            goto label2;
            break;

            default:
            printf("Invalid choice!\n");
        }
    }
    while(1){
        label2:{
    printf("Linked LIST 2: \n");
    printf("Enter 1 to insert at the end.\nEnter 2 to exit\n");
    scanf("%d",&ch);
        switch(ch)
        {

            case 1:
            printf("Enter the value to be inserted at the end:\n");
            scanf("%d",&data);
            first2=insertAtEnd(first2,data);
            break;

            case 2:
            goto label1;
            break;
        
            default:
            printf("Invalid choice!\n");
        }
    }
    }//end of while
   label1:{ printf("The Concatenation of two Linked Lists. is\n");
     first1=concatanate(first1,first2);
     display(first1);
    }

    return 0;
}