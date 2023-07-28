#include<stdlib.h>
#include<stdio.h>
int fib(int n)
{
    if(n==0)    return 0;
    if(n==1)    return 1;
    if(n%5==0)  return 11;
    else    return fib(n-1) + fib(n-2);
}
int main()
{
    int n,res;
    printf("Enter the value of n \n");
    scanf("%d",&n);
    res = fib(n);
    res = res %(1000000007);
    printf("%d",res);
    return 0;
}