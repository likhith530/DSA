#include<bits/stdc++.h>
using namespace std;
//Time Complexity : O(N log N) , SC : O(N) - Recurison stack space O(N)

void merge(vector<int>& arr,int l,int mid, int h){
    vector<int> res(h-l+1);
    int i=l,j=mid+1;
    int k=0; // for iterating in res
    while(i<=mid && j<=h){
        if(arr[i] <= arr[j]){
            res[k++] = arr[i++];
        }
        else{
            res[k++] = arr[j++];
        }
    }
    while(i<=mid)
    {
        res[k++] = arr[i++];
    }
    while(j<=h){
        res[k++] = arr[j++];
    }
    
    for(int i=0;i<res.size();i++){
        arr[l+i] = res[i];
    }
}
void mergeSort(vector<int>& arr, int l , int h){
    int mid;
    if(l<h){
        mid = l +(h-l)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,h);
        merge(arr,l,mid,h);
    }
}

int main(){
    int l , h;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    l = 0, h = n-1;

    mergeSort(arr,l,h);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
/*
8
1 7 2 4 6 3 8 5 
*/
