#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>spf(n+1);
    for(int i=0;i<=n;i++){
        spf[i]=i;
    }

    for(int i=2;i*i<=n;i++){
        if(spf[i]==i){
            for(int j=i*i;j<=n;j+=i){
                if(spf[j]==j){
                    spf[j]=i;
                }
            }
        }
    }
int cnt=0;
    while(n>1){
        int prime_factor=spf[n];
        cnt++;

        cout<<prime_factor<<" ";
        n/=prime_factor;
    }
    cout<<endl;
    cout<<"Total prime factors: "<<cnt<<endl;
    return 0;
}