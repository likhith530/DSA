#include <cmath>
#include<iostream>

using namespace std;

int main()
{
    string s;
    cout<<"Enter the Binary String"<<endl;
    cin>>s;
    int n = s.size();
    long long dec = 0;
    for(int i=0;i<n;i++)
    {
        dec += (s[i] - '0') * pow(2,n-i-1);
    }
    cout<<dec<<endl;
    return 0;
}