#include<bits/stdc++.h>
using namespace std;

int LongestIncreasingSubsequence(vector<int> &arr, int N)
{
    vector<int> LIS(N,1);
    int ans; 
    for(int i=1;i<N;i++)
    {
        for(int j =0;j<i;j++)
        {
            if(arr[j] < arr[i]) //from smaller elements choosing the one with max LIS
                LIS[i] = max(LIS[i],LIS[j]+1); // max of choosing or not choosing
        }
        ans = max(ans,LIS[i]);
    }
    //return *max_element(LIS.begin(),LIS.end());
    return ans;
}
int main()
{
    int t;
    cin>>t;

    while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);

    for(int i=0;i<n;i++) cin >> arr[i];

    int res = LongestIncreasingSubsequence(arr,n);
    cout<<"The LIS is "<< res <<endl;
    }
    return 0;
}