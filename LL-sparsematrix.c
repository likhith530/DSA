#include <stdio.h>
#include<stdlib.h>
struct Node 
{
    int row, col,data;
    struct Node *next;
};
struct Node *insert(struct Node *head, int row, int col, int data)
{
    struct Node *temp=(struct Node *)malloc(sizeof(struct Node));
    temp->row=row;
    temp->col=col;
    temp->data=data;
    if(head==NULL)
    {
        return temp;
    }
    else
    {
        struct Node *p=head;
        while(p->next!=NULL)
        {
           p=p->next; 
        }
        p->next=temp;
        temp->next=NULL;
        return head;
    }
}
void display(struct Node *head)
{
    if(head==NULL)
    {
        printf("Nothing to display!\n");
    }
    else
    {
        struct Node *p=head;
        while(p->next!=NULL)
        {
            printf("Row %d|Col %d|Data %d---->",p->row, p->col,p->data);
            p=p->next;
        }
        if(p->next==NULL)
        {
           printf("Row %d|Col %d|Data %d\n",p->row, p->col,p->data); 
        }
    }
}
void main()
{
    struct Node *head=NULL;
    int i, j,row,col;
    printf("Enter the number of rows in the sparse matrix:\n");
    scanf("%d",&row);
    printf("Enter the number of columns in the sparse matrix:\n");
    scanf("%d",&col);
    int sparseMat[row][col];
    printf("Enter the sparse matrix:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",&sparseMat[i][j]);
        }
    }
    printf("The sparse matrix is:\n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d",sparseMat[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(sparseMat[i][j]!=0)
            {
                head=insert(head,i+1,j+1,sparseMat[i][j]);//i+1 - row number , j+1 - column number
            }
        }
    }
    
    display(head);
}
