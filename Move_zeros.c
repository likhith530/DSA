#include<stdio.h>
#include<stdlib.h>
int n,i,j=0;
int b[10];
void move_zeros_1(int a[],int n)
{
    //Method 1 (using array -- O(1))
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            a[j]=a[i];
            j++;
        }
    }
    for(;j<n;j++)   a[j]=0;
}
void display1(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

void move_zeros_2(int a[],int n)
{
    //Method 2 (using array -- O(n))
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0)
        {
            b[j]=a[i];
            j++;
        }
    }
    for(;j<n;j++)   b[j]=0;
}
void display2(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",b[i]);
    }
}
int main()
{
    int a[]={0,0,1,3,12};
    // int a[]={0};
     n=5;
    move_zeros_1(a,n);
    display1(a,n);
    // move_zeros_2(a,n);
    // display2(a,n);
    return 0;

}