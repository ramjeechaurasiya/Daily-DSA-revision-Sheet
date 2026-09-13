#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int count=0;
    int k;
    cin>>k;
    // for(int i=0;i<n;i++){
    //     int sum=0;
    //     for(int j=i;j<n;j++){
    //         sum+=arr[j];
            
    //         if(sum==k){
    //             count=max(count,j-i+1);
    //         }
    //     }
    // }
    // cout<<count<<endl;



    // using sliding window approach using for looop
    // int left=0,right=0;
    // int sum=0,maxLen=0;
    // for(int right=0;right<n;right++){
    //     sum+=arr[right];
    //     while(sum>k){
    //         sum-=arr[left];
    //         left++;
    //     }
    //     if(sum==k){
    //         maxLen=max(maxLen,right-left+1);
    //     }

    // }


    // using sliding window approach using while looop
    int left=0,right=0;
    int sum=0,maxLen=0;
    while(right<n){
        sum+=arr[right];
        while(sum>k){
            sum-=arr[left];
            left++;
        }
        if(sum==k){
            maxLen=max(maxLen,right-left+1);
        }
        right++;
    }
    cout<<maxLen<<endl;
    return 0;

}
