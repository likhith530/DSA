#include<bits/stdc++.h>
using namespace std;

// Pick a pivot -> can be any index and then place it in correct place in the sorted array
// Smaller numbers (<=)on the left of pivot and larger numbers (>)on the right of pivot
// So we will get the sorted array
// So after this iteration , we can say that pivot element is on the correct place
// Left and right half have to be sorted now

//Time Complexity : O(N log N) , SC : O(1) - Recurison stack space O(N)
//Worstcase time complexity -> when the pivot is always largest / smallest number 
// O(N*N)

int partition(vector<int>& arr, int l, int h){
    int pivot = arr[l]; 
    int i=l,j=h;
    while(i<j){
        while(i<h && arr[i] <= pivot) // these are smaller elements
            i++;
        // i will be now at the element greater than pivot
        while(j>l && arr[j] > pivot) // these are the larger elements 
            j--;
        // j will be now at the elemt lesser than the pivot

        if(i<j){ // if they haven't crossed -> then swap
            swap(arr[i],arr[j]);
        }
    }
    // Now swap the pivot to its correct position
    swap(arr[l],arr[j]);
    return j;
}
void quickSort(vector<int>& arr, int l, int h){
    int j;
    if(l<h){ // More than one ellement in array
        j = partition(arr,l,h);
        quickSort(arr,l,j-1);
        quickSort(arr,j+1,h);
    }
}
int main(){
    int l , h;
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    l = 0, h = n-1;

    quickSort(arr,l,h);
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    return 0;
}
/*
8
1 7 2 4 6 3 8 5 
*/
