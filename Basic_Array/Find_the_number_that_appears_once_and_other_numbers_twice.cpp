#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    // this  is using map 

//     unordered_map<int,int>mp;
//     for(int i=0;i<n;i++){
//         mp[arr[i]]++;
//     }
// int x=0;
//     for(auto it:mp){
//         if(it.second==1){
//                 x=it.first;
//         }
//     }
// cout<<x<<endl;
// return 0;




// now using xor concpet which help us to find uquniue number
int xorr=0;
for(int i=0;i<n;i++){
    xorr^=arr[i];
}
cout<<xorr<<endl;
return 0;
    
}
