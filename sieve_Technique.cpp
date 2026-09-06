#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<bool>res(n+1,true);
    res[0]=false;
    res[1]=false;
    for(int i=2;i*i<=n;i++){
        if(res[i]){
            for(int j=i*i;j<=n;j+=i){
                res[j]=false;
            }
        }
    }

    for(int i=0;i<=n;i++){
        if(res[i]){
            cout<<i<<" ";
        }
    }
    return 0;
}