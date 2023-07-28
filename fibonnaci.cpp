#include<iostream>
using namespace std;
int a[10];
long fib(long n)
{ 
    if(n<=1)
    return n;
    if (a[n-2]==-1)
    a[n-2]=fib(n-2);
    if (a[n-1]==-1)
    a[n-1]=fib(n-1);

    return a[n-2]+a[n-1];
}
int main()
{
    for(int i=0;i<10;i++)
    {
        a[i]=-1;
    }
    int n;
    cin>>n;
     cout<<fib(n);
  return 0;
}