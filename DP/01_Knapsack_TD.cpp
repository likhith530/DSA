#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int knapsack(vector<int>& weight,vector<int>& value, int W, int n){
        //Changing variables are n & W
        vector<vector<int>> dp(n+1,vector<int>(W+1,0)); // init to 0
        //Base cond --> Init  ( here already done as i==0 & j==0 -> alreaydy 0)
        for(int i=1;i<n+1;i++){ // n
            for(int j=1;j<W+1;j++){ // W
                if(weight[i-1] <= j){ // Include or Not include -> j is curr capacity
                    dp[i][j] = max(value[i-1] + dp[i-1][j-weight[i-1]] , 
                                dp[i-1][j]);
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][W];
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