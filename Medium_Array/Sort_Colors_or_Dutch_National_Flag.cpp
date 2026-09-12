#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    int red=0;
        int white=0;
        int blue=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)red++;
            if(nums[i]==1)white++;
            if(nums[i]==2)blue++;
        }
        int idx=0;
        while(red--){
            nums[idx++]=0;
        }
        while(white--){
            nums[idx++]=1;
        }
        while(blue--){
            nums[idx++]=2;
        }

        for(int i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        return 0;
}