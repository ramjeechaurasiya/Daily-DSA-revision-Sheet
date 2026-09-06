#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int current_sum=0;
    int max_sum=INT_MIN;
    // int start=0,end=0,temp_start=0;
    for(int i=0;i<n;i++){
        current_sum=max(current_sum+arr[i],arr[i]);
        max_sum=max(max_sum,current_sum);
        // if(current_sum<=arr[i]){
        //     current_sum=arr[i];
        //     temp_start=i;
        // }
        // else {
        //     current_sum+=arr[i];
        // }
    //  if(current_sum>max_sum){
    //         max_sum=current_sum;
    //         start=temp_start;
    //         end=i;
        
    //     }
        }
    
    cout<<max_sum<<endl;
return 0;
}