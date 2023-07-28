#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// #include<ctype.h>
struct Node{
char name[20];
char dept[10];
int years_of_exp;
struct Node* next;
};//typedef Node


struct Node *insertAtFirst(struct Node *first,char name[],char dept[],int yoe)
{
    struct Node *new=(struct Node *)malloc(sizeof(struct Node));
    strcpy(new->name,name);
    strcpy(new->dept,dept);
    new->years_of_exp=yoe;
    new->next=NULL;
    if(first==NULL)
    {
        first=new;
       return first;
    }
    else
    {
    new->next=first;
    first=new;
    return first;
    }
}

void display(struct Node *first)
{
    struct Node*p = first;
    while(p!=NULL)
    {
        if(p->years_of_exp>10)
        {
        printf("%s",(p->name));
        printf("\n");
        printf("%s",(p->dept));
        printf("\n");
        printf("%d \n",p->years_of_exp);
        }
        p=p->next;
    }
    if(first==NULL)
    printf("Nothing to display!");
}


int main()
{
    struct Node *first =NULL;
    int ch,data,index,yoe;
    char name[20];
    char dept[10]; 
    while(1)
    {
    printf("Enter 1 to insert at the beginning.\nEnter 2 to display\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the years of experience:\n");
            scanf("%d",&yoe);
            printf("Enter name\n");
            scanf("%s",name);
            printf("Enter department\n");
            scanf("%s",dept);
            first=insertAtFirst(first,name,dept,yoe);
            break;
            case 2:
            display(first);
            break;
            default:printf("Wrong!");
        }
    }
    return 0;
}
