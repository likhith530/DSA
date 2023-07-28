#include<stdio.h>
#include<stdlib.h>
struct node
{
    char value;
    struct node* next;
};
typedef struct node * NODE;

NODE getnode()
{
    NODE new=(NODE)malloc(sizeof(struct node));
    return new;
}

NODE insertatend(NODE head,char item)
{
  NODE newnode=getnode();
  newnode->value=item;
  newnode->next=NULL;
  NODE temp=head;
  if(head==NULL)
  {
      return newnode;
  }
  while (temp->next != NULL)
  {
      temp=temp->next;
  }
  temp->next=newnode;
  return head;
}
NODE merge(NODE head1,NODE head2)
{
    NODE list3=NULL;
    while(head1!=NULL && head2!=NULL)
    {
        list3=insertatend(list3,head1->value);
        list3=insertatend(list3,head2->value);
        head1=head1->next;
        head2=head2->next;
        
    }
    while (head1 != NULL)
    {
        list3=insertatend(list3,head1->value);
        head1=head1->next;
    }
    while (head2 != NULL)
    {
        list3=insertatend(list3,head2->value);
        head2=head2->next;
    }
    return list3;
}
void display(NODE head)
{
    while(head!=NULL)
    {
    printf("%c",head->value);
    head=head->next;
    }
    printf("\n");
    
}
void main()
{
    NODE head1;
    NODE head3;
    NODE head2;
    head1=head2=NULL;
    int i;
    char item;
    while(1)
    {
        printf("Enter choice\n1.Insert in list1\n2.Insert in list2\n3.Merge lists\n4.Display list1 \n5.Display list2\n6.Display merged list\n");
       scanf("%d",&i);
    switch(i)
    {
        case 1:printf("Enter item");
               scanf(" %c",&item);
               head1=insertatend(head1,item);
               break;
       case 2:printf("Enter item");
               scanf(" %c",&item);
               head2=insertatend(head2,item);
               break;
        case 3:head3=merge(head1,head2);
               break;
        case 4:display(head1);
               break;
         case 5:display(head2);
         break;
         case 6:display(head3);
         break;
         default: exit(0);
    }
    }
    
}