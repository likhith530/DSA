// Sample Input: 5!4!3!2!1
// Sample output: 1!4!3!2!5
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *insert_at_end(struct Node *last, int data)
{
    struct Node *newnode= (struct Node *)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=newnode;
    if(last==NULL)
    {
       last=newnode;
       last->next=newnode;
       return last;
    }
    else{
        newnode->next=last->next;
        last->next=newnode;
        last=newnode;
        //last->next=last;
        return last; 
    }
}
struct Node* get(struct Node *last)
{
    struct Node*p=last->next;
     struct Node*q=last->next;
    struct Node*temp=(struct Node*)(malloc)(sizeof(struct Node));;
    temp->data=last->next->data;
    temp->next=NULL;
    while(p->next!=last)
    {
        p=p->next;
    }
    // temp->data=last->next->data;
    // p->next=temp;
    // temp->next=last;
    // temp=last;
    temp->next=last;
    p->next=temp;
    last->next=last->next->next;//as we are freeing last->next
    free(q);
    last=p->next;
    return last;
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
    last=get(last);
    display(last);
    return 0;
}

