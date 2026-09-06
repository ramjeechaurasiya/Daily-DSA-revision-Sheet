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
    for(int i=0;i<n;i++){
        if(arr[i]>arr[(i+1)%n]){
            count++;
        }
    }
    if(count>1){
        cout<<"False\n";
        
    }
    else{
        cout<<"True\n";
    }
return 0;
}