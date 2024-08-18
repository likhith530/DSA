#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int val;
    struct Node* next;
};

struct Node* insertAtEnd(struct Node* first,int data)
{
    struct Node* new = (struct Node*)(malloc)(sizeof(struct Node));
    new->val = data;
    new->next = NULL;
    if(first==NULL)
    {
        first = new;
        return first;
    }
    else
    {
        struct Node*p = first;
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next = new;
        return first;
    }
}

struct Node* merge(struct Node* first1, struct Node* first2)
{
    if(first1==NULL)    return first2;
    if(first2==NULL)    return first1;

    struct Node* mergeHead = NULL; //To find the first element to begin with
    if(first1->val <= first2->val) //first1 shuld be head
    {
        mergeHead = first1;
        first1 = first1->next; // move to next node
    }
    else{
        mergeHead = first2;
        first2 = first2->next;
    }

    struct Node* mergeTail = mergeHead; //MergeTail will be used to add others to it
    while(first1!=NULL && first2!=NULL)
    {
        struct Node* temp = NULL;
        if(first1->val <= first2->val)
        {
            temp = first1;
            first1 = first1->next;
        }
        else{
            temp = first2;
            first2 = first2->next;
        }

        mergeTail->next = temp;
        mergeTail = temp;
    }
    if(first1!=NULL)
    {
        mergeTail->next = first1;
    }
    else
        mergeTail->next = first2;

    return mergeHead;
}

void display(struct Node* first)
{
    if(first == NULL)
        printf("\nNothing to Display");
    else
    {
        int i=1;
        struct Node*p = first;
        while(p!=NULL)
        {
            printf("\nThe element %d is %d ", i,p->val);
            p=p->next;
            i++;
        }
    }
}

int main()
{
    struct Node* first1=NULL;
    struct Node* first2 = NULL;
    int ch,data;
    while(1)
    {
        printf("\nEnter 1 to Insert for LL1\nEnter 2 to Insert for LL2\nEnter 3 to Display\nEnter 4 to Merge\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("\nEnter the Value to be Inserted ");
                scanf("%d",&data);
                first1= insertAtEnd(first1,data);
                break;
            case 2:
                printf("\nEnter the Value to be Inserted ");
                scanf("%d",&data);
                first2= insertAtEnd(first2,data); 
                break;
            case 3:
                display(first1);
                break;
            case 4:
                first1 = merge(first1,first2);
                break;
            case 5:
                exit(0);
        }
    }




    return 0;
}