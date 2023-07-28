#include<iostream>
using namespace std;
struct node
{
    int data;
    struct node *next;
}*first=NULL;

void create(int arr[],int n)
{
 struct node *temp,*last;
 first = new struct node;
 first->data = arr[0];
 first->next = NULL;
 last = first;
 for(int i=1;i<n;i++)
 {
     temp = new struct node;
     temp->data = arr[i];
     temp->next = temp;
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




int main()
{
    int arr[]={18,8,20,3,30};
    create(arr,4);
    display(first);
    return 0;
}