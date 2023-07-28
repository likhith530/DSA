// Given the head of a singly linked list, return true if it is a palindrome
//  or false otherwise.
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int val;
    struct Node*next;
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
        printf("Element %d is %d\n",(i+1),(ptr->val));
        ptr=ptr->next;
        i++;
    } 
    }
}
struct Node *reverse(struct Node *head)
{
    struct Node *p=head;
    struct Node *q=NULL;
    struct Node *r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    head=q;
    printf("\n\n");
    display(head);
    return head;
}

int isPalindrome(struct Node* head)
{
    struct Node *p=head;
    struct Node *q;
    struct Node* head2=(struct Node*)malloc(sizeof(struct Node));
    head2=reverse(head);
    q=head2;
    printf("\n\n");
    while(p!=NULL && q!=NULL)
    {
        if(p->val!=q->val)
            return 0;
        else{
        printf("%d \n",p->val);
        printf("%d \n",q->val);
        p=p->next;
        q=q->next;
        }
    }
    return 1;
}

struct Node* insert(struct Node*head,int data)
{
    struct Node*ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->val=data;
    if(head==NULL)
    {
        head=ptr;
        return head;
    }
    else
    {
    struct Node *p=head;
    while(p->next!=NULL)
    {
        p=p->next;
    }
   
    ptr->next=NULL;
    p->next=ptr;
    return head;
    }
}

int main()
{
    struct node*head=NULL;
    int data;
    for(int i=0;i<4;i++)
    {
        scanf("%d",&data);
        head=insert(head,data);
    }
    display(head);
    printf("%d",isPalindrome(head));
    return 0;
}