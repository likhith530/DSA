#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define size 10
void insert(int q[],int *r,int *f,int data)
{
    if(*r==size-1)
    printf("Queue overflow!\n");
    else
    {
        *r=(*r)+1;
        q[*r]=data;
    }
}
int delete(int q[],int *r, int *f)
{
    int del_item=-1;
    if(*f==*r)
    printf("All elements deleted!\n");
    else if(*r==-1)
    printf("Queue underflow!\n");
    else
    {
        *f=(*f)+1;
        del_item=q[*f];
        return del_item;
    }
}
void display(int queue[], int *r, int *f)
{
    int i;
    if(*r==*f)
    printf("Nothing to display!\n");
    else
    {
        for(i=(*f)+1;i<=*r;i++)
        {
            printf("%d ",queue[i]);
        }
    }
}
void merge(char str[],int q[], int *r1,int *f1,int n,int m)
{
    char res[n+m];
    res[0]='#';
    int s=n+m;
    int min;
    if(n>m)
    min=m;
    else
    min=n;
    
    char queue[s];
    int i,j;
    for(i=0;i<min;i=i++)
    {
       // queue[i]=(char)delete(q,r1,f1);
        res[i]+=delete(q,r1,f1) - 48;
        // queue[i+1]=str[i];
        res[i]+=str[i];
    }
    if(min=m)
    {
        while(*r1=n-1) 
        {
            res[i]=delete(q,r1,f1);
            i++;
        }
    }
    else
    {
        while(str[i]!='\0')
        {
            res[i]=str[i];
            i++;
        }
    }
    for(i=0;i<n+m;i++)
    {
        printf("%c ",res[i]);
    }
    
    
}
int main()
{
    char str[100];
    int r1=-1,f1=-1,n,m,i,j;
    int q[100],data;
    printf("Enter the character array:\n");
    scanf("%s",str);
    printf("The character array is:\n");
    for(i=0;i<strlen(str);i++)
    {
        printf("%c ",str[i]);
    }
    printf("\n");
    printf("Enter the number of elements in the integer queue:\n");
    scanf("%d",&n);
    printf("Enter integer queue elements:\n");
    for(i=1;i<=n;i++)
    {
        printf("Enter element %d:\n",i);
        scanf("%d",&data);
        insert(q,&r1,&f1,data);
    }
    printf("The integer queue:\n");
    display(q,&r1,&f1);
    printf("\n");
    printf("The final queue:\n");
    merge(str,q,&r1,&f1,n,strlen(str));

    return 0;
}