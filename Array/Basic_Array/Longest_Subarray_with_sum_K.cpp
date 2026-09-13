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
    unordered_map<int,int>mp;
    int sum=0;
    int maxLen=0;

    for(int i=0;i<n;i++){
        sum+=arr[i];
        int rem=sum-k;
        if(mp.find(rem)!=mp.end()){
            maxLen=max(maxLen,i-mp[rem]);
        }
        if(mp.find(rem)==mp.end()){
            mp[sum]=i;
        } 
    }
    cout<<maxLen<<endl;
    return 0;
}