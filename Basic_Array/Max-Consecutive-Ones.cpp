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
    int maxCount = 0;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            count++;
        }
        else{
            count=0;
        }
        maxCount=max(maxCount,count);

    }
    cout<<"Max Consecutive Ones: "<<maxCount<<endl;
    return 0;
}
