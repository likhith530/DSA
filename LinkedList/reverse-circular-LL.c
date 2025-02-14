#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *getNode()
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    if(temp==NULL)
    {
        printf("Memory full!\n");
        return NULL;
    }
    else
    return temp;
}
void display(struct Node *last)
{
    int i=0;
    if(last==NULL)
    {
        printf("Nothing to display!\n");
    }
    else
    {
        while(last->next!=last)
        {
            printf("Element %d is %d\n",(i+1),last->data);
            last=last->next;
            i++;
            printf("%d",i);
        }
        printf("Element %d is %d\n",(i+1),last->data);
    }
}
struct Node *insert_at_end(struct Node *last, int data)
{
    struct Node *newnode=getNode();
    newnode->data=data;
    newnode->next=newnode;
    if(last==NULL)
    {
       last=newnode;
       last->next=newnode;
       return last;
    }
    else
    {
        newnode->next=last->next;
        last->next=newnode;
        //newnode->next=last->next->next;
        last=newnode;
        return last; 
    }
}
struct Node *reverse(struct Node *last)
{
    struct Node *prev=last;
    struct Node *current=last->next;
    struct Node *nextNode=current->next;
    if(last==NULL)
    {
        printf("LL empty!\n");
        return NULL;
    }
    else
    {
        while(current!=last)
        {
            prev=current;
            current=nextNode;
            nextNode=current->next;
            current->next=prev;
            
        }
        nextNode->next=last;
        last=nextNode;
        return last;

    }
}
int main()
{
    struct Node *last=NULL;
    int data,i,n;
    printf("Enter the no of elements in the linked list:\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter element %d\n",i);
        scanf("%d",&data);
        last=insert_at_end(last,data);
    }
    printf("Before reversing!\n");
    display(last);
    printf("After reversing!\n");
    last=reverse(last);
    display(last);
    return 0;
}