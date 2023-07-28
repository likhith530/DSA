#include <stdio.h>
#include<stdlib.h>
struct Node 
{
    int coeff,power;
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
struct Node *insert_at_end(struct Node *head, int coeff, int power)
{
    struct Node *ptr=getNode();
    ptr->coeff=coeff;
    ptr->power=power;
   
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

void display(struct Node *head)
{
    int i=0;
    if(head==NULL)
    {
        printf("The polynomial is: 0\n");
    }
    else
    {
        struct Node *p=head;
        while(p->next!=NULL)
        {
            printf("%dx^%d+",p->coeff, p->power);
            p=p->next;
            i++;
        }
        
        if(p->next==NULL)
        printf("%dx^%d",p->coeff, p->power);
        printf("\n");
        
    }
}
struct Node *addPoly(struct Node *head1, struct Node *head2, struct Node *head3)
{
    struct Node *p=head1;
    struct Node *q=head2;
    while(p!=NULL && q!=NULL)
    {
        if(p->power==q->power)
        {
            head3=insert_at_end(head3, p->coeff+q->coeff, p->power);
            p=p->next;
            q=q->next;
        }
        else if(p->power>q->power)
        {
            head3=insert_at_end(head3,p->coeff, p->power);
            p=p->next;
        }
        else if(p->power<q->power)
        {
            head3=insert_at_end(head3, q->coeff,q->power);
            q=q->next;
        }
    }
    while(p!=NULL)
    {
        head3=insert_at_end(head3, p->coeff, p->power);
        p=p->next;
    }
    while(q!=NULL)
    {
        head3=insert_at_end(head3, q->coeff, q->power);
        q=q->next;
    }
    return head3;
}
void main()
{
    struct Node *head1=NULL;
    struct Node *head2=NULL;
    struct Node *head3=NULL;
    int n,m,i,coeff,power;
    printf("Enter the first polynomial:\n");
    printf("Enter the number of terms:\n");
    scanf("%d", &n);
    for(i=1;i<=n;i++)
    {
        printf("Enter the coeff of term %d\n",i);
        scanf("%d",&coeff);
        printf("Enter the power of term %d\n",i);
        scanf("%d",&power);
        head1=insert_at_end(head1, coeff, power);
    }
    printf("Enter the second polynomial:\n");
    printf("Enter the number of terms:\n");
    scanf("%d", &m);
    for(i=1;i<=m;i++)
    {
        printf("Enter the coeff of term %d\n",i);
        scanf("%d",&coeff);
        printf("Enter the power of term %d\n",i);
        scanf("%d",&power);
        head2=insert_at_end(head2, coeff, power);
    }
    printf("The first polynomial is:\n");
    display(head1);
    printf("The second polynomial is:\n");
    display(head2);
    printf("The resultant polynomial is:\n");
    head3=addPoly(head1, head2, head3);
    display(head3); 
    
    
    
}