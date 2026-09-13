#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    unordered_map<int,int>mp;
    int sum=0;
 
// do not mess with finding sum of subarray with finding two sum


    vector<pair<int,int>>res;
    for(int i=0;i<n;i++){
        
         int rem=k-arr[i];
         if(mp.find(rem)!=mp.end()){
           cout<<mp[rem]<<" "<<i<<endl;
            }
         
            mp[arr[i]]=i;

        }
         
         cout<<endl;
         return 0;
}