#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int val;
    struct Node* next;
};

int count(struct Node* first)
{
    if(first == NULL)   return 0;
    int c=0;
    struct Node* p = first;
    while(p!=NULL)
    {
        p=p->next;
        c++;
    }
    return c;
}

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

struct Node *insertAtEnd(struct Node *first,int data)
{
   
    struct Node *ptr=(struct Node *)malloc(sizeof(struct Node));
    ptr->val=data;
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

struct Node* reverseKgroup(struct Node* first , int k)
{
    int num_of_reverse = count(first) / k;
    struct Node*p = first;
    struct Node*q = NULL;
    struct Node*r = NULL;
    struct Node*dummyHead = first;
    // struct Node*nex = first->next;
    // struct Node*cur = first;
    // struct Node*pre = NULL;
    // for(int i=1 ; i<=num_of_reverse;i++)
    // {
        //I have to reverse k nodes i times
        int j=1;
        // 1 -> 2 -> 3 -> 4 -> 5
        while(j<=k) // This operation has to be done k - 1 times
        {
            r = q;
            q = p;
            p =p->next;
            q->next = r;
            j++;
        }
        first = q;
        dummyHead->next = p;
        return first;
    // }
    // 3 -> 2 -> 1 -> 4 -> 5

}

int main()
{
    struct Node*first = NULL;
    // struct Node*first;
    // first->val = 1;
    // first->next->val = 2;
    // first->next->next->val = 3;
    // first->next->next->next->val = 4;
    // first->next->next->next->next->val = 5;
    int k;
    printf("Enter k\n");
    scanf("%d",&k);
    while(1)
    {
    printf("Enter 1 to Insert to the Linked list\nEnter 2 to Reverse-k-group\nEnter 3 to display\n");
    int ch;
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("Enter value to be inserted\n");
            int data;
            scanf("%d",&data);
            first = insertAtEnd(first,data);
            break;
        case 2:
            first = reverseKgroup(first,&k);
            break;
        case 3: 
            display(first);
            break;
        case 4:
            exit(0);
        default:
            printf("Wrong Case Entered\n");

    }
    }
}
