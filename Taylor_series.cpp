#include<iostream>
using namespace std;
double res;
double exp(double x , long n)
{    
    static double p=1,f=1;
    if(n==0)
    return 1;
    else
    {
        res = exp(x,n-1);
        p=p*x;
        f=f*n;
        return res + p/f;
    }
}
int main()
{
    double x;
    long n;
    cin>>x>>n;
    cout<<exp(x,n);
    return 0;
}