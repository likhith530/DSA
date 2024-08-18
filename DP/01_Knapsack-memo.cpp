#include<bits/stdc++.h>
using namespace std;
class Solution{
private:
    int solve(vector<int>& weight,vector<int>& value, int W, int n,vector<vector<int>> &dp){
        //Base cond:
        if(n==0 || W==0) return 0;
        //Memo cond:
        if(dp[n][W] != -1) return dp[n][W];
        if(weight[n-1] <= W){ 
            return dp[n][W] = max(value[n-1] + knapsack(weight,value,W-weight[n-1],n-1),
                knapsack(weight,value,W,n-1));
            // Storing & returning of Max of include and not include
        }
        else //weight[n-1] > W
        {
            return dp[n][W] = knapsack(weight,value,W,n-1); // Can't include
        }
    }
public:
    int knapsack(vector<int>& weight,vector<int>& value, int W, int n){
        //Changing variables are n & W
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1)); // init to -1
        return solve(weight,value,W,n,dp); //pass dp
    }
};
int main(){
    cout<<"Enter Input"<<endl;
    int n;
    int W; //Capacity
    cin>>n;
    cin>>W;
    vector<int> weight(n),value(n);
    for(int i=0;i<n;i++)
    {
        cin>>weight[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>value[i];
    }
    Solution ob;
    cout<<ob.knapsack(weight,value,W,n)<<endl;
    return 0;
}
/*
4
8
2 3 4 5
3 4 5 6
*/