#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
   int first_max=INT_MIN;
   int  second_max=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>first_max){
            second_max=first_max;
           first_max=arr[i];
        }

       else if(arr[i]>second_max && arr[i]!=first_max){
            second_max=arr[i];
        }
    }
    cout << "First max: " << first_max << endl;
    cout << "Second max: " << second_max << endl;

    return 0;
}