#include<iostream>
using namespace std;
double exp(double x , long n)
{  
    if(n==0)
    return 1;

    if(n<0)
    {
        x=1/x;
        n=-n;
    }

    if(n%2==1)
    return x*exp(x,n/2)*exp(x,n/2);

    if(n%2==0)
    return exp(x,n/2)*exp(x,n/2);  
}

int main()
{
    long n;
    double x,res;
    cin>>x>>n;
    res=exp(x,n);
    cout<<res;
}
