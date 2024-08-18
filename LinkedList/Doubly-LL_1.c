#include<stdio.h>
#include<stdlib.h>

struct Node 
{
    int value;
    struct Node *next;
    struct Node *prev;
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
 struct Node * insert_at_left(struct Node *first,int index,int data)
 {
    struct Node* new = (struct Node*)malloc(sizeof(struct Node));
    new->value=data;
    new->prev=NULL;
    new->next=NULL;
    if(first==NULL)
        return new;
    else
    {
        struct Node*p=first;
        int i=0;
        while(i<=index && p!=NULL)
        {
            p=p->next;
            i++;
        }
        new->prev=p->prev;
        p->prev->next=new;
        new->next=p;
        p->prev=new;
        return first;
    }
 }
struct Node *create(struct Node *first,int data)
{
   
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->value=data;
    ptr->next=NULL;
    ptr->prev=NULL;
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
    p->next=ptr;
    ptr->prev=p;
    return first;
    }
}
 struct Node * delete_spec_val(struct Node *first,int data)
 {
    if(first==NULL)
    {
        printf("Nothing to display\n");
        return NULL;
    }
    if(first->value==data)
    {
        printf("Node deleted\n");
        return NULL;
    }
    else{
        struct Node*p=first;
        while(p->value!=data)
        {
            p=p->next;
        }
        
        p->prev->next=p->next;
        p->next->prev=p->prev;
        free(p);
        return first;
        if(p==NULL)
            printf("Element not found");
    }
 }

 int main()
{
    struct Node *first =NULL;
    int ch,data,index;
    int a[]={12,10,8,6,4};
    for(int i=0;i<5;i++)
    {
        first=create(first,a[i]);
    }
    
    while(1)
    {
    printf("Enter 1 to insert to the left.\nEnter 2 to delete a specific value.\nEnter 3 to display.\nEnter 4 to exit!\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the value to be inserted\n");
                  scanf("%d",&data);
                  printf("Enter the index to be inserted");
                  scanf("%d",&index);
                  first=insert_at_left(first,index,data);
                  break;
            case 2:printf("Enter the value to be deleted\n");
                  scanf("%d",&data);
                    first=delete_spec_val(first,data);
                    break;
            case 3:display(first);
                break;
            case 4:exit(0);
            default:printf("Wrong case entered\n");
        }
    }
    return 0;
}