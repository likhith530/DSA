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

void display(struct node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p = p->next;
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

 int RecursiveCount(struct node *p)
 {
     if(p==0)
         return 0;
    else
        return RecursiveCount(p->next)+1 ;
 }

 int sum(struct node *p)
 {
     int sum=0;
     while(p)
     {
         sum+=p->data;
         p=p->next;
     }
     return printf("Sum of elements in node : %d \n",sum);
 }

int Recursivesum(struct node *p)
{
    if(p==NULL)
        return 0;        
    else
        return Recursivesum(p->next) + p->data;
}

int maximum(struct node *p)
{
    int max=-32768; //Min_int 
    while(p)
    {
        if(p->data>max)
         max= p->data; 
     p=p->next;
    }
    return max;
}

int minimum(struct node *p)
{
     int min=32768; //MAX_int 
    while(p)
    {
        if(p->data<min)
         min= p->data; 
     p=p->next;
    }
    return min;
}

struct node * Search(struct node *p, int x)//returns the pointer type
{
   while(p)
   {
       if(p->data==x)
         return p;
     p=p->next;
   }
   return NULL;//not found
}

struct node * RecursiveSearch(struct node *p,int x)
{
    while(p)
    {
        if(p->data==x)
          return p;
        else 
          return RecursiveSearch(p->next,x);
    }
    return NULL;
}

struct node * ImprovedSearch(struct node *p, int x)//returns the pointer type
{  
    struct node* q=NULL; //tailing pointer
   while(p)
   {
       if(p->data==x)//we will move to first node 
       {
        q->next=p->next;
        p->next=first;
        first=p;
        return p;
       }
       q=p;
       p=p->next;      
   }
        return NULL;//not found
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

int Delete(struct node *p,int index)
{
 if(p!=NULL)
 {
 display(p->next);
 printf("%d ",p->data);
  }
struct node *q=NULL;
int x=-1,i;
if(index < 1 || index > count(p))
return -1;
if(index==1)
{
q=first;
x=first->data;
first=first->next;
free(q);
return x;
}
else
{
for(i=0;i<index-1;i++)
{
q=p;
}
p=p->next;
q->next=p->next;
x=p->data;
free(p);
return x;
  }
 }


int main()
{  
    struct node *t;
    int arr[]={18,8,20,3,30};
    create(arr,5);
    display(first);
    count(first);
    sum(first);
    
    printf("The number of nodes by recusion %d \n",RecursiveCount(first));
   
    printf("The sum of elements by recursion is %d \n", Recursivesum(first));
    
    printf("The maximum number is %d \n",maximum(first));

    printf("The minimum number is %d \n",minimum(first));

   struct node *t1 = Search(first,8);
    if(t1)
      printf("Search Succesful! %d found \n",t1->data);
    else
      printf("Search Unsuccesful! %d not found \n",t1->data);
    
    struct node *t2 = RecursiveSearch(first,20);
    if(t2)
      printf("Search Succesful! %d found \n",t2->data);
    else
      printf("Search Unsuccesful! %d not found \n",t2->data);

    struct node *t3 = ImprovedSearch(first,18);
    if(t3)
      printf("Search Succesful! %d found \n",t3->data);
    else
      printf("Search Unsuccesful! %d not found \n",t3->data);

    Insert(first,0,5);
    display(first);

    return 0;
}