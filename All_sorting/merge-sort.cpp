#include<bits/stdc++.h>
using namespace std;
int recursiveCalls = 0;
int mergeCount = 0;

void merge(vector<int>&arr,int low ,int mid,int high){
    mergeCount++;
    int i=low;
    int k=0;
    vector<int> temp(high - low + 1);
    int j=mid+1;
    while(i<=mid&&j<=high){
        if(arr[i]<=arr[j]){
            temp[k]=arr[i];
            k++;
            i++;
        }
        else{
            temp[k]=arr[j];
            j++;
            k++;
        }
    }
    while(i<=mid){
        temp[k]=arr[i];
        k++;
        i++;
    }
    while(j<=high){
        temp[k]=arr[j];
        k++;
        j++;
    }

    for(int i=0;i<temp.size();i++){
        arr[low+i]=temp[i];
    }
}
void mergeSort(vector<int>&arr,int low,int high){
    recursiveCalls++;
    if(low<high){
        int mid=(low+high)/2;
        mergeSort(arr,low,mid);
        mergeSort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    mergeSort(arr,0,n-1);

    for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
cout<<"recursiveCalls: "<<recursiveCalls<<endl;

// Merge Sort makes roughly 2n - 1 recursive calls and
//  n - 1 merge operations for an array of size n

cout<<"mergeCount: "<<mergeCount<<endl;




return 0;

}