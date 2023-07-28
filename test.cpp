#include<stdio.h>
int main()
{
    int a,b;//a+b
    printf("Enter 2 numbers");
    scanf("%d %d",&a,&b);
    for(int i=1;i<=b;i++)
    {
        a++;
    }
    printf("%d",a);
    return 0;
}