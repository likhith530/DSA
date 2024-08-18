#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    int knapsack(vector<int>& weight,vector<int>& value, int W, int n){
        //Base cond:
        if(n==0 || W==0) return 0;

        if(weight[n-1] <= W){ 
            return max(value[n-1] + knapsack(weight,value,W-weight[n-1],n-1),
                knapsack(weight,value,W,n-1));
            // Max of include and not include
        }
        else //weight[n-1] > W
        {
            return knapsack(weight,value,W,n-1); // Can't include
        }
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