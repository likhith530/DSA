#include <stdio.h>
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
struct Node *insert_at_end(struct Node *head, int data)
{
    struct Node *ptr=getNode();
    ptr->data=data;
   
    if(head==NULL)
    {
        return ptr;
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
struct Node *insert_at_beg(struct Node *head, int data)
{
    struct Node *ptr=getNode();
    ptr->data=data;
    
    if(head==NULL)
    {
        return ptr;
    }
    else
    {
        ptr->next=head;
        head=ptr;
        return head;
    }
}
void display(struct Node *head1,struct Node *head2,struct Node *head3)
{
    int i=0;
    if(head1==NULL && head2==NULL)
    {
        printf("The sum is: 0\n");
        
    }
    else
    {
        printf("The sum is:\n");
        struct Node *p=head3;
        while(p!=NULL)
        {
            printf("%d",p->data);
            p=p->next;
            i++;
        }
        printf("\n");
    }
}
struct Node *add(struct Node *head1, struct Node *head2, struct Node *head3)
{
    int sum=0, carry=0;
    struct Node *temp1=head1;
    struct Node *temp2=head2;
    while(temp1!=NULL || temp2!=NULL)
    {
        if(temp1!=NULL)
        sum+=temp1->data;
        if(temp2!=NULL)
        sum=sum+temp2->data;
        sum=(sum+carry)%10;
        carry=sum/10;
        head3=insert_at_beg(head3, sum);
        if(temp1!=NULL)
        temp1=temp1->next;
        if(temp2!=NULL)
        temp2=temp2->next;
        //sum=0;
    }
    if(carry)
    head3=insert_at_beg(head3, carry);
    return head3;
}

void main()
{
    int rem1, rem2;
    struct Node *head1=NULL;
    struct Node *head2=NULL;
    struct Node *head3=NULL;
    int num1, num2;
    printf("Enter the first number:\n");
    scanf("%d",&num1);
    printf("Enter the second number:\n");
    scanf("%d",&num2);
    while(num1>0)//543
    {
        rem1=num1%10;
        head1=insert_at_end(head1, rem1);//3-4-5
        num1=num1/10;
    
    }
    while(num2>0)
    {
        rem2=num2%10;
        head2=insert_at_end(head2,rem2);
        num2=num2/10;
        
    }
    head3=add(head1, head2, head3);
    
    display(head1,head2,head3);
    
    
    
}