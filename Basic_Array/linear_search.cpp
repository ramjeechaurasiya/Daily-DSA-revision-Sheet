#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int search;
    cin>>search;
    int index=0;
    for(int i=0;i<n;i++){
        if(arr[i]==search){
            index=i;
        }
    }
    cout<<search<<" Element present at index: "<<index<<endl;
    return 0;
}