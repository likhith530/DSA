#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
}*first=NULL;

void create(int arr[],int n)
{
 int i;
 struct node *temp,*last;
 first = (struct node *) malloc (sizeof(struct node));
 first->data = arr[0];
 first->next = NULL;
 last = first;

 for(i=1;i<n;i++)
 {
     temp = (struct node *) malloc (sizeof(struct node));
     temp->data = arr[i];
     temp->next=NULL;
     last->next = temp;
     last = temp;
 }
}

int count(struct node *p)
 { 
    int ctr=0;
     while(p!=NULL)
     {
        ctr++;
         p=p->next;
     }
     return printf("\nNumber of lists : %d \n",ctr);
 }

void Insert(struct node *p,int index,int x)
{
 struct node *t;
 int i;
 if(index < 0 || index > count(p))
    return;
  t=(struct node *)malloc(sizeof(struct node));
  t->data=x;
 if(index == 0)
 { 
    t->next=first;
    first=t;
 }

  else
 {
    for(i=0;i<index-1;i++)
    p=p->next;
    t->next=p->next;
    p->next=t;
 }
}

void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
    }
}
int main() {
 int A[]={10,20,30,40,50};
//  int n;
//  int A[5];
//  int index , item;
//  printf("Enter the number of nodes in Linked list\n");
//  scanf("%d",&n);
//  printf("Enter the values\n");
//  for(int i=0;i<n;i++)
//  {
//      scanf("%d",&A[i]);
//  }
//  printf("Enter the index to be inserted in\n");
//  scanf("%d",&index);
//  printf("Enter the value to be inserted\n");
//  scanf("%d",&item);
//  create(A,n);
//  Insert(first,index,item);
//  display(first);
 create(A,5);
 Insert(first,0,5);
 display(first);
return 0;
 }