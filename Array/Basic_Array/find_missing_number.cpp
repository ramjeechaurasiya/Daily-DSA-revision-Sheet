#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n-1);
    for(int i=0;i<n-1;i++){
        cin>>arr[i];
        }
    // long long sum=0;
    // for(int i=0;i<n-1;i++){
    //     sum+=arr[i];
    // }
    // long long total=1LL*n*(n+1)/2;
    // long long missing= total-sum;

    int xor1=0,xor2=0;
    for(int i=0;i<n-1;i++){
        xor1^=arr[i];
    }
    for(int i=1;i<=n;i++){
        xor2^=i;
    }
    int missing=xor1^xor2;
    cout<<"Missing number is : "<<missing<<endl;
    return 0;
    }