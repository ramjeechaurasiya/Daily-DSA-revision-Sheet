#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
        }
        
        // j → unique elements ki position
        // i → poora array check karega

        int j=0;

        for(int i=1;i<n;i++){
            
            if(arr[j]!=arr[i]){
                j++;
                arr[j]=arr[i];
            }
        }

     cout << "Unique Elements: ";

    for(int i = 0; i <= j; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nCount: " << j + 1;

    return 0;
}
