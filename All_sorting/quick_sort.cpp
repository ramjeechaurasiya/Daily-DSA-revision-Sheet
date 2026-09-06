#include<bits/stdc++.h>
using namespace std;
int recursiveCalls = 0;
int partitionCalls = 0;
int Partition(vector<int>&res,int low,int high){
    partitionCalls++;
    int pivot=res[high];
    int j=low-1;
    for(int i=low;i<high;i++){
        if(res[i]<=pivot){
            j++;
            swap(res[j],res[i]);
        }
    }
    swap(res[high],res[j+1]);
    return j+1;
}
void quickSort(vector<int>&res,int low,int high){
    if(low<high){
        recursiveCalls++;
        int partion=Partition(res,low,high);
        quickSort(res,low,partion-1);
        quickSort(res,partion+1,high);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>res(n);
    for(int i=0;i<n;i++){
        cin>>res[i];
    }
    quickSort(res,0,n-1);

    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }

    cout<<endl;
    cout<<"Partition count: "<<partitionCalls<<endl;
    cout<<"Recurssive call count: "<<recursiveCalls<<endl;
    return 0;
}