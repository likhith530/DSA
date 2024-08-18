//First Negative Number in every Window of size k
//If no negatives in window -> 0
//Store the answers in a list -> n-k+1 elements

#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void solve(vector<int> arr, int k, vector<int> &ans)
{
    int n = arr.size();
    queue<int> Q;
    int i=0,j=0;
    for(;j<k-1;j++)
    {
        if(arr[j]<0)
            Q.push(arr[j]);
    }
    while(j<n)
    {
        if(arr[j]<0)
            Q.push(arr[j]);
        if(j-i+1 == k) //We have to print the first negative now 
        {
            if(!Q.empty())
                ans.push_back(Q.front());
            else
                ans.push_back(0);
        }
        //Now to slide window , check arr[i] -> if negative remove it from queue 
        if(arr[i]<0)
            Q.pop();
        i++;
        j++;
    }
}
int main()
{
    int n;
    cout<<"Enter the array size\n";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter the Elements\n";
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int k;
    cout<<"Enter the window size\n";
    cin>>k;
    vector<int> ans;

    solve(arr,k,ans);

    cout << "First Negative Numbers in each window of size " << k << " are: ";
    for(int num : ans)
        cout<<num<<" ";
}
//8
//12 -1 -7 8 -15 30 16 28
//3